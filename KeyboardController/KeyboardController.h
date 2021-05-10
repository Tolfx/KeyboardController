#pragma once
#include <iostream>
#include <windows.h>
#include <string>
class KeyboardControllerWindows
{
    private:
        INPUT ip;
        INPUT ShiftK;
        INPUT CtrlK;
        INPUT AltK;
        boolean Shift;
        boolean Ctrl;
        boolean Alt;

        int CharacterInt(char a)
        {
            return (int)a;
        }

    public:

        KeyboardControllerWindows()
        {
            ip.type = INPUT_KEYBOARD;
            ip.ki.wScan = 0;
            ip.ki.time = 0;
            ip.ki.dwExtraInfo = 0;

            ShiftK.type = INPUT_KEYBOARD;
            ShiftK.ki.wScan = 0;
            ShiftK.ki.time = 0;
            ShiftK.ki.dwExtraInfo = 0;

            CtrlK.type = INPUT_KEYBOARD;
            CtrlK.ki.wScan = 0;
            CtrlK.ki.time = 0;
            CtrlK.ki.dwExtraInfo = 0;

            AltK.type = INPUT_KEYBOARD;
            AltK.ki.wScan = 0;
            AltK.ki.time = 0;
            AltK.ki.dwExtraInfo = 0;
        }

        void Hold_Shift()
        {
            Shift = !!Shift;
            ShiftK.ki.wVk = VK_SHIFT;
            SendInput(1, &ShiftK, sizeof(INPUT));
        }

        void Release_Shift()
        {
            Shift = !!Shift;
            ShiftK.ki.dwFlags = 0;
            ShiftK.ki.dwFlags = KEYEVENTF_KEYUP;
            SendInput(1, &ShiftK, sizeof(INPUT));
        }

        void Hold_Ctrl()
        {
            Ctrl = !!Ctrl;
            CtrlK.ki.wVk = VK_CONTROL;
        }

        void Release_Ctrl()
        {
            Ctrl = !!Ctrl;
            CtrlK.ki.dwFlags = KEYEVENTF_KEYUP;
        }

        void Hold_Alt()
        {
            Alt = !!Alt;
            AltK.ki.wVk = VK_MENU;
        }

        void Release_Alt()
        {
            Alt = !!Alt;
            AltK.ki.dwFlags = KEYEVENTF_KEYUP;
        }

        void PressCharacter(char *x)
        {
            ip.ki.wVk = (CharacterInt(*x));
            ip.ki.dwFlags = 0;

            SendInput(1, &ip, sizeof(INPUT));

            ip.ki.dwFlags = KEYEVENTF_KEYUP;
            SendInput(1, &ip, sizeof(INPUT));
        }

};