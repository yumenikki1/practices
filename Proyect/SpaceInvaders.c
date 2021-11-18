#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define FALSE 0
#define TRUE 1

void healthbar(int n)
{
    printf("     LIVES:   ");
    for(int i = 0; i< n; i++){
            printf("\x03");
    }
}
int main()
{
    int sizey = 26;
    int sizex = 48;
    int x, y, yi, yy = sizey - 1, xx = sizex;
    char world[sizey][sizex];
    char player = 'A';
    char playerShoot = '\xF8';
    char enemy = '\xEB';
    char enemyShielded = '\xE9';
    char enemyLaser = 'v';
    char enemylaserL = '\xF8';
    char enemylaserR = '\xF9';
    char explosion = '*';
    int lives = 3;
    int score = 0;
    int victory = 1;
    int laserReady = TRUE;
    int enemyReady = FALSE;
    int enemyLaserwReady = FALSE;
    int scorecounter = 0;

    printf("\n\n            \n\n");
    printf("           ___                     ___                 _            \n          / __|_ __  __ _ __ ___  |_ _|_ ___ ____ _ __| |___ _ _ ___\n          \\__ \\ '_ \\/ _` / _/ -_)  | || ' \\ V / _` / _` / -_) '_(_-<\n");
    printf("          |___/ .__/\\__,_\\__\\___| |___|_||_\\_/\\__,_\\__,_\\___|_| /__/\n               |_|                                                   \n");

    printf("\n");
    printf("     __  ____  ____  ________  ________ ____ _________         ___ __  _         \n");
    printf("     \\ \\/ / / / /  |/  / __/ |/ /  _/ //_/ //_/  _<  / ___ ___/ (_) /_(_)__  ___ \n");
    printf("      \\  / /_/ / /|_/ / _//    // // ,< / ,< _/ / / / / -_) _  / / __/ / _ \\/ _ \\ \n");
    printf("      /_/\\____/_/  /_/___/_/|_/___/_/|_/_/|_/___//_/  \\__/\\_,_/_/\\__/_/\\___/_//_/\n");
    Sleep(1000);
    printf("\n                             use WASD to move and SPACE to shoot");
    Sleep(1000);
    printf("\n                                  press any key to start");
    getch();

    int totalEnemies = 0;
    for (x = 0; x < sizex; x ++) {
        for (y = 0; y < sizey; y ++) {
            if ((y+1) % 2 == 0 && y < 7 && x > 4
            && x < sizex - 5 && x % 2 ==0) {
                world[y][x] = enemy;
                totalEnemies ++;
            }
            else if ((y+1) % 2 == 0 && y >= 7 && y < 9 && x > 4
            && x < sizex - 5 && x % 2 ==0){
                world[y][x] = enemyShielded;
                totalEnemies = totalEnemies + 2;
            }
            else {
                world[y][x] = ' ';
            }
        }
    }
    world[sizey-1][sizex / 2] = player;
    int i = 1;
    char keyPress;
    int currentEnemies = totalEnemies;
    while(currentEnemies > 0 && lives >= 0) {
        scorecounter++;
        if (score-1 >= 0 && scorecounter > 10){ score --; scorecounter = 0;}
        int drop = 0;
        laserReady ++;

        system("cls");
        printf("ASCII SPACE INVADERS YUMENIKKI1 EDITION       SCORE:    %d", score);
        healthbar(lives);
        printf("\n");
            for (y = 0; y < sizey; y ++) {
           printf("\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0   "); printf("\xBA");
                for (x = 0; x < sizex; x ++) {
                    printf("%c",world[y][x]);
                }
            printf("\xBA"); printf("   \xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0");
            printf("\n");
            }
            if(kbhit()){
            keyPress = getch();
        }
        else {
            keyPress = 'x';
        }
        if (keyPress == 'a') {
            for (x = 0; x < sizex; x = x+1) {
                if ( world[yy][x+1] == player) {
                    world[yy][x] = player;
                    world[yy][x+1] = ' ';
        }
    }
        }

        if (keyPress == 'd') {
            for (x = sizex - 1; x > 0; x = x-1) {
                if ( world[yy][x-1] == player) {
                    world[yy][x] = player;
                    world[yy][x-1] = ' ';
        }
        }
        }
       if (keyPress == 'w') {
            for (x = 0; x < sizex; x = x+1) {
                if ( world[yy][x] == player && (yy > (sizey / 2))) {
                     world[yy - 1][x] = player;
                    yy=yy-1;
                    world[yy+1][x] = ' ';
        }
    }
        }
         if (keyPress == 's') {
            for (x = 0; x < sizex; x = x+1) {
                if ( world[yy][x] == player && (yy < (sizey-1))) {
                     world[yy + 1][x] = player;
                    yy=yy+1;
                    world[yy-1][x] = ' ';
            }
        }
        }
       //shoot
        for (x = 0; x < sizex; x ++) {
            for (y = sizey-1; y >= 0; y --) {
                if (i%2 == 0 && world[y][x] == enemyLaser && (world[y+1][x] != enemy && world[y+1][x] != enemyShielded)){
                world[y+1][x] = enemyLaser;
                world[y][x] = ' ';
                }
                else if (i%2 == 0 && world[y][x] == enemyLaser && (world[y+1][x] == enemy | world[y+1][x] == enemyShielded)){
                    world[y][x] = ' ';
                }
            }
        }
        for (x = 0; x < sizex; x ++) {
            for (y = 0; y < sizey; y ++) {
                if ((i % 5) == 0 && (world[y][x] == enemyShielded || world[y][x] == enemy) && (rand() % 14) > 11 && world[y+1][x] != playerShoot) {
                    for (yi = y+1; yi < sizey; yi ++) {
                        if (world[yi][x] == enemy
                        | world[yi][x] == enemyShielded) {
                            enemyReady = FALSE;
                            break;
                        }
                        enemyReady = TRUE;
                    }
                    if (enemyReady) {
                        world[y+1][x] = enemyLaser;
                    }
                }
                if (world[y][x] == playerShoot && world[y-1][x] == enemy) {
                    world[y][x] = ' ';
                    world[y-1][x] = explosion;
                    currentEnemies --;
                    score = score + 50;
                }
                else if (world[y][x] == playerShoot && world[y-1][x] == enemyShielded) {
                    world[y][x] = ' ';
                    world[y-1][x] = enemy;
                    currentEnemies--;
                    score = score + 50;
                }
                 if (world[y][x] == playerShoot && world[y-1][x] == enemyLaser) {
                    world[y][x] = ' ';
                }
                else if (world[y][x] == explosion) {
                    world[y][x] = ' ';
                }
                 if ((i+1) % 2 == 0 && world[y][x] == enemyLaser && world[y+1][x] == player) {
                    world[y][x] = ' ';
                    Sleep(300);
                    lives--;
                    x = sizex / 2;
                    yy = sizey - 1;
                    system("cls");
                    for(int t = sizey/2; t< sizey; t++){
                        for(int r = 0; r < sizex; r++){
                            world[t][r] = ' ';
                        }
                    }
                    Sleep(300);
                    if(score-1 >= 0)score = score -50;
                    world[sizey-1][sizex / 2] = player;
                    Sleep(700);
                }
                else if (world[y][x] == playerShoot
                && world[y-1][x] != enemyLaser) {
                        world[y][x] = ' ';
                        world[y-1][x] = playerShoot;
                }
            }
        }



        if (keyPress == ' ' && laserReady > 2) {
            for (x = 0; x < sizex; x = x+1) {
                if ( world[yy][x] == player) {
                    world[yy - 1][x] = playerShoot;
                    laserReady = FALSE;
                }
            }
        }
        i ++;

}
system("cls");
    if (lives > 0) {
        printf("\n \n \n \n \n \n               Victory!!! \n \n \n \n \n");
        Sleep(1000);
        printf("\n \n               Score: %d", score);
        Sleep(1000);
        getch();
    }
    else {
        printf("\n \n \n \n             Game Over");
        Sleep(1000);
        printf("\n \n \n \n             You Lose");
        Sleep(1000);
        printf("\n \n               Score: %d", score);
        getch();
    }
}
