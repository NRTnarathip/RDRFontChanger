#pragma once
#include <Windows.h>

#define CHECK_OFFSET(type, field, offset) \
    static_assert(offsetof(type, field) == offset, "Bad offset")
