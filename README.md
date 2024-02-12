# ARM Chess Timer 

This is a simple chess timer for ARM devices. The timer is controlled by two buttons, one for each player. The timer is displayed on a 16x2 LCD display there are 3 buttons one for each player and one for reset

## Drivers Implemented
- **GPIO** (General Purpose Input/Output)
- **Timer 2**  (UpCounting mode)
- **LCD** : 16x2 Display used for displaying the time it's on 8-bit mode and data and pins are defined in the `lcd.h` file
- **External Interrupts** : Used for the buttons and adjusted for the debouncing of the buttons

## How to use

1. Connect the LCD to the ARM device
2. Connect the buttons to the ARM device
3. Connect the ARM device to the computer
4. Clone the repository
5. make sure you have the arm-none-eabi-gcc, arm-none-eabi-gdb, arm-none-eabi-binutils, arm-none-eabi-newlib installed
  - On Debian Based System (Althrough I am not sure) : `sudo apt-get install gcc-arm-none-eabi gdb-arm-none-eabi binutils-arm-none-eabi newlib-arm-none-eabi`  
  - On Arch Based System : `sudo pacman -S arm-none-eabi-gcc arm-none-eabi-gdb arm-none-eabi-binutils arm-none-eabi-newlib`
  - On Mac : `brew install gcc-arm-embedded`
  - On Windows : You are on your own!
6. Open the project in vscode 
7. Install PlatformIO extension
8. Specify the pins of the LCD in the `lcd.h` file 
9. Specify the pins of the buttons in the `main.c` file
10. Upload the code to the ARM device using the PlatformIO extension

## Photos of the project
![image](https://github.com/Walid-Kh/Arm-Chess-Timer/blob/master/assets/ChessTime!.jpg)
![image](https://github.com/Walid-Kh/Arm-Chess-Timer/blob/master/assets/Time.jpg)

## Video of the project
<iframe width="560" height="315" src="https://www.youtube.com/embed/0KKOslfDLpI?si=Ro6-LcQMaOQLSPL0" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>