#pragma once

#include <switch.h>

#include "types.hpp"

class Input{
public:
    static Result rc;
    static bool initflag;
    static PadState pad;

    static u64 update();
    static void init();
    static void cleanup();

    static Vector2 getJoystickPos(int joyNum);

};