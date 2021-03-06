# Space Invaders.
This is my version of the classic game "Space Invaders". In this game you have to shoot the enemies at the top of the screen, the more enemies you kill the higher your score gets. Also every 10 frames your score is reduced by one. So the less time you take, the less points you lose.

### Libraries
I used these libraries in the code

![imagen](https://user-images.githubusercontent.com/88511121/142474286-9ff79070-d9d7-4541-b7a6-598b8e9b495e.png)

# Structure
The whole game happens in the int main function.
First I print the world that is a two dimensional array.
Then the characters in the world will interact as intended in order to play.

I made a subroutine for the healthbar that prints the hearts the number of lives times in the screen every frame.

# Functionality
I used the kbhit() function in the conio.h library to control the spaceship. So when you press the "w" key, the spaceship moves a character higher in the y axis; if you press the "s" key, the spaceship moves a character lower in the y axis; if you press the "a" key, you move a character to the left; and if you press the "d" key you move a character tho the right.

Using the Spacebar will spawn a laser above the spaceship and this will go a character upward everyframe in the world.
Every character in the world has its own behaviour that updates every frame.

I used the Sleep() function in the windows.h library to animate some things in order to have a better experience.

![spacecapture](https://user-images.githubusercontent.com/88511121/142474498-5222bbd8-fef5-4ca6-9c28-d8b1247e8216.PNG)

# Video
[YouTube](https://www.youtube.com/watch?v=i-9VAsmZbwU)
