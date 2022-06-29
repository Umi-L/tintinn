#include <Input.hpp>
#include <switch.h>
#include <stdio.h>

#include "Types.hpp"


double maxStickPos = 32767.0;

PadState Input::pad;
Result Input::rc;
bool Input::initflag;

void Input::init(){

    // Configure our supported input layout: all players with standard controller styles
	padConfigureInput(8, HidNpadStyleSet_NpadStandard);

	// Initialize the gamepad for reading all controllers
    padInitializeAny(&Input::pad);

    Input::rc=0;
    Input::initflag=0;

    Input::rc = hiddbgInitialize();
    if (R_FAILED(Input::rc)) {
        printf("hiddbgInitialize(): 0x%x\n", Input::rc);
    }
    else {
        Input::initflag = 1;
    }

    printf("--Input system initialized--\n");
}

u64 Input::update(){
    // padGetButtonsDown returns the set of buttons that have been
    // newly pressed in this frame compared to the previous one

    padUpdate(&Input::pad);
    return padGetButtonsDown(&pad);
}

void Input::cleanup(){
    if (Input::initflag) {
        // These *must* be run at some point before exiting.

        // You can also use hiddbgUnsetAutoPilotVirtualPadState with a specific AbstractedVirtualPadId if you want.

        // Input::rc = hiddbgUnsetAllAutoPilotVirtualPadState();
        // printf("hiddbgUnsetAllAutoPilotVirtualPadState(): 0x%x\n", Input::rc);

        hiddbgExit();
    }
}
    
Vector2 Input::getJoystickPos(int joyNum){
    HidAnalogStickState analog_stick_l = padGetStickPos(&Input::pad, joyNum);

	Vector2 stickNormalized = Vector2(static_cast<double>(analog_stick_l.x) / maxStickPos, static_cast<double>(-analog_stick_l.y) / maxStickPos);

    return stickNormalized;
}
