# Space Invaders ASCII version.
This is my version of the classic game "Space Invaders". In this game you have to shoot the enemies at the top of the screen, the more enemies you kill the higher your score get. Also every 10 frames your score is reduced by one. So the less time you take, you'll lose less points.

### Libraries
I used these libraries in the code
![imagen](https://user-images.githubusercontent.com/88511121/142474286-9ff79070-d9d7-4541-b7a6-598b8e9b495e.png)

# Structure
The whole game happens in the int main function.
First I print the world that is a two dimensional array.

I made a subroutine for the healthbar that prints the hearts the number of lives times in the screen every frame.

# Functionality
I used the kbhit() function in the conio.h library to control the spaceship. So when you press the w key, the spaceship moves a character higher in the y axis; if you press the "s" key, the spaceship moves a character lower in the y axis; if you press the "a" key, you move a character to the left; and if you press the "d" key you move a character tho the right.
Using the Spacebar will spawn a laser above the spaceship ant this will go a characer upward everyframe.
Every character in the world has its own behaviour that updates every frame.
