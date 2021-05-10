#include <KeyboardController.h>

int main()
{
    KeyboardControllerWindows Keyboard;
    Keyboard.Hold_Shift();
    Keyboard.PressCharacter((char*)"H");
    Keyboard.PressCharacter((char*)"E");
    Keyboard.PressCharacter((char*)"L");
    Keyboard.PressCharacter((char*)"L");
    Keyboard.PressCharacter((char*)"O");
    Keyboard.Release_Shift();
}