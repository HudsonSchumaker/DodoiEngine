/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

#pragma once
#include "System.h"
#include "../../event/KeyPressedEvent.h"
#include "../../event/KeyReleasedEvent.h"
#include "../../event/JoyPadLeftAxisEvent.h"

class ControllerSystem final : public System {
private:
    void subscribeToEvents();

public:
    ControllerSystem();
    ~ControllerSystem() = default;
        
    void onKeyPressed(KeyPressedEvent& event);
    void onKeyReleased(KeyReleasedEvent& event);
    void joypadLeftAxis(JoyPadLeftAxisEvent& event);
};
