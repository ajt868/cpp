#include <iostream>
#include <ctime>

void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);


void drawBoard(char board[3][3]) {
    std::cout << "Tic-Tac-Toe Board:\n";
    for (int i = 0; i < 3; i++) {
        // Print each row
        for (int j = 0; j < 3; j++) {
            std::cout << " " << board[i][j];
            if (j < 2) std::cout << " |";
        }
        std::cout << std::endl;
        // Print horizontal line after each row except the last
        if (i < 2) std::cout << "---+---+---\n";
    }
    std::cout << std::endl;
}
int main() {
    char board[3][3] = {
        {' ', ' ', ' '}, 
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    
    char player = 'X';
    char computer = 'O';
    bool running = true;

    drawBoard(board);


    return 0;
}