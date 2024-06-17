#include "FlappyBird.h"
using namespace std;

void goToXY(int x, int y) {
    move(y, x);
}

Flappy_Bird::Flappy_Bird() {
    srand(time(NULL));
    betweenHurdleGap = (screenWidth / hurdleCount) + 10;
    for (int i = 0; i < hurdleCount; i++) {
        hurdlePos[i][0] = betweenHurdleGap * (i + 1);

        int breakPos = rand() % (screenHeight / 3) + hurdleGap;
        hurdlePos[i][1] = breakPos;
    }
}

void Flappy_Bird::printHurdle() {
    int count = 0;
    for (int i = 0; i < hurdleCount; i++) {
        for (int j = 0; j < screenHeight; j++) {
            if (hurdlePos[i][1] == j) count = hurdleGap;

            if (count == 0) {
                if (hurdlePos[i][0] < screenWidth) {
                    goToXY(hurdlePos[i][0] + 1, j);
                    printw(" ");

                    goToXY(hurdlePos[i][0], j);
                    printw("%d", i);
                }
            } else {
                if ((count == 1 || count == hurdleGap) && hurdlePos[i][0] < screenWidth) {
                    if (hurdlePos[i][0] + 1 > 0) {
                        goToXY(hurdlePos[i][0] + 1, j);
                        printw("   ");
                    }

                    if (hurdlePos[i][0] - 1 > 0) {
                        goToXY(hurdlePos[i][0] - 1, j);
                        printw("===");
                    }
                }
                count--;
            }
        }

        hurdlePos[i][0]--;

        if (hurdlePos[i][0] == -1) {
            int prev;
            if (i == 0)
                prev = hurdleCount - 1;
            else
                prev = i - 1;

            hurdlePos[i][0] = hurdlePos[prev][0] + betweenHurdleGap;

            int breakPos = rand() % (screenHeight / 3) + hurdleGap;
            hurdlePos[i][1] = breakPos;

            for (int i = 0; i < screenHeight; i++) {
                goToXY(0, i);
                printw(" ");
            }
        }
    }
}

bool Flappy_Bird::collisionCheck() {
    if (birdY == 0 || birdY + 3 == screenHeight) return true;

    for (int i = 0; i < hurdleCount; i++) {
        if (hurdlePos[i][0] == birdX &&
            (birdY >= hurdlePos[i][1] ||
            birdY + 3 <= (hurdlePos[i][1] + hurdleGap))
            ) {
            score++;
        }

        if (hurdlePos[i][0] >= birdX - 5 &&
            hurdlePos[i][0] <= birdX &&
            (birdY <= hurdlePos[i][1] ||
            birdY + 3 >= (hurdlePos[i][1] + hurdleGap))
            ) {
            return true;
        }
    }
    return false;
}

void Flappy_Bird::clearBird() {
    goToXY(birdX - 5, birdY);
    printw("   ");
    goToXY(birdX - 5, birdY + 1);
    printw("      ");
    goToXY(birdX - 5, birdY + 2);
    printw("       ");
}

void Flappy_Bird::printScore() {
    goToXY(0, screenHeight + 4);
    printw("Score: %d", score);
}

void Flappy_Bird::printBird() {
    goToXY(birdX - 5, birdY);		printw(" __");
    goToXY(birdX - 5, birdY + 1);	printw("/-/o\\");
    goToXY(birdX - 5, birdY + 2);	printw("\\_\\-/");
}

void Flappy_Bird::printRoad() {
    for (int i = 0; i <= screenWidth; i++) {
        goToXY(i, screenHeight);		printw("_");
        goToXY(i, screenHeight + 1);	printw("/");
        goToXY(i, screenHeight + 2);	printw("=");
    }
}

void Flappy_Bird::play() {
    initscr();
    noecho();
    cbreak();
    timeout(0);
    keypad(stdscr, TRUE);

    printRoad();
    while (true) {
        int ch = getch();
        if (ch == ' ') {
            birdY -= jump;
        }

        printHurdle();
        printBird();
        printScore();

        if (collisionCheck()) break;

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        clearBird();
        birdY += 1;
    }

    endwin();
}