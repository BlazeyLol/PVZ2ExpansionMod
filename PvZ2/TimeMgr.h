#pragma once

class TimeMgr
{
public:
    char pad[0x24];
    float m_curTime;

    static TimeMgr* GetInstance()
    {
        return *(TimeMgr**)getActualOffset(0x1D7C3E4);
    }
};
