#include "memUtils.h"

#include "Substrate/SubstrateHook.h"

uint g_libAddress = NULL;

uint getLibraryAddress(const char* libName) {
    FILE* fp = fopen("/proc/self/maps", "rt");
    if (fp == NULL) {
        perror("fopen");
        return 0;
    }

    uint addr = 0;
    char line[1024];

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strstr(line, libName) != NULL) {
            addr = strtoul(line, NULL, 16);
            break;
        }
    }

    fclose(fp);
    return addr;
}

uint getActualOffset(uint offset)
{
    if (g_libAddress == 0)
    {
        g_libAddress = getLibraryAddress("libPVZ2.so");
    }
    return g_libAddress + offset;
}

void FluffyHookFunction(uint offset, void* replace, void** result) 
{
    MSHookFunction((void*)getActualOffset(offset), replace, result);
}

void* copyVFTable(int vftableAddr, int numVFuncs)
{
    int size = numVFuncs * sizeof(int);
    void* vftableCopy = malloc(size);
    memcpy(vftableCopy, (const void*)vftableAddr, size);
    return vftableCopy;
}

void patchVFTable(void* vftable, void* funcAddr, int index)
{
    ((reinterpret_cast<void**>(vftable))[index]) = funcAddr;
}

void copyVFTable(void* dest, int vftableAddr, int numVFuncsToCopy) {
    int size = numVFuncsToCopy * sizeof(int);
    memcpy(dest, (const void*)vftableAddr, size);
}

void* createChildVFTable(int vFuncsCount, int parentVftable, int nuMVFuncsToCopy) {
    int size = vFuncsCount * sizeof(int);
    void* childVftable = malloc(size);
    copyVFTable(childVftable, parentVftable, nuMVFuncsToCopy);

    return childVftable;
}

void setVFTable(void* obj, uintptr_t newVftablePtr)
{
    *reinterpret_cast<int*>(uintptr_t(obj)) = newVftablePtr;
}

void* GetVirtualFunc(void* obj, int index) {
    void** vtable = *reinterpret_cast<void***>(obj);
    return vtable[index];
}
