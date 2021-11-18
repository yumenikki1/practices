# Space Invaders ASCII version.
This is my version of the classic game "Space Invaders". In this game you have to shoot the enemies at the top of the screen, the more enemies you kill the higher your score get. Also every 10 frames your score is reduced by one. So the less time you take, you'll lose less points.

## Libraries
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

# Structure
The whole game happens in the int main function.
First I print the world that is a two dimensional array.


I made a subroutine for the healthbar that prints the hearts the number of lives times in the screen every frame.

# Functionality
I used the kbhit() function in the conio.h library to control the spaceship. So when you press the w key, the spaceship moves a character higher in the y axis; if you press the "s" key, the spaceship moves a character lower in the y axis; if you press the "a" key, you move a character to the left; and if you press the "d" key you move a character tho the right.

For every character in the world has its own behaviour that updates every frame.
