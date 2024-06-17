#include "FlappyBird.h"
using namespace std;

int main() {
    while (true) {
        Flappy_Bird fb;
        fb.play();
        cout << "Do you want to play again? (Y/N)";

        char ch;
        cin >> ch;
        if (ch == 'N' || ch == 'n') {
            break;
        }
        system("clear");
    }

    return 0;
}