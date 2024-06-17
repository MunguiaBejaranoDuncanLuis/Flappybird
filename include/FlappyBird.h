#pragma once
#include <iostream>
#include <ncurses.h>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <chrono>

void goToXY(int x, int y);
void loadBitmapImage(const char* filename, int x, int y);

class Flappy_Bird {
private:
    static const int hurdleCount = 4;
    int hurdlePos[hurdleCount][2];
    int screenWidth = 79;
    int screenHeight = 25;
    int hurdleGap = 8;
    int betweenHurdleGap;

    int birdX = 17;
    int birdY = 15;

    int jump = 4;
    int score = 0;

public:
    Flappy_Bird();
    void printHurdle();
    bool collisionCheck();
    void clearBird();
    void printScore();
    void printBird();
    void printRoad();
    void play();
};