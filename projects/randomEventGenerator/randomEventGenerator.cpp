#include <iostream>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int randNum = rand() % 5 + 1;

    switch (randNum) {
        case 1:
            std::cout << "You win a bumper sticker!" << endl;
            break;
        case 2:
            std::cout << "You win a t-shirt!" << endl;
            break;
        case 3:
            std::cout << "You win a plushie!" << endl;
            break;
        case 4:
            std::cout << "You win a free lunch!" << endl;
            break;
        case 5:
            std::cout << "You win a concert ticket!" << endl;
            break;
        default:
            break;
    }


    return 0;
}

