#pragma once

// Useful for filtering logcat
#define LIB_TAG "PVZ2ExpansionMod"

#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, LIB_TAG, __VA_ARGS__))
#define LOGW(...) ((void)__android_log_print(ANDROID_LOG_WARN, LIB_TAG, __VA_ARGS__))

// original logging func: 10C5F34
// maybe i could hook it?