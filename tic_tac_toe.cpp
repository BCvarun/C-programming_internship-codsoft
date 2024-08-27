//Program which implements the tic_tac_toe game

#include <iostream>

using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE];
char currentPlayer;

void initializeBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
    currentPlayer = 'X';
}

void displayBoard() {
    cout << "  1   2   3" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << i + 1 << " ";
        for (int j = 0; j < SIZE; j++) {
            cout << board[i][j];
            if (j < SIZE - 1) cout << " | ";
        }
        cout << endl;
        if (i < SIZE - 1) cout << " ---|---|---" << endl;
    }
}

bool isWin() {
    // Check rows
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < SIZE; i++) {
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
        return true;
    }
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
        return true;
    }

    return false;
}

bool isDraw() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void makeMove() {
    int row, col;
    while (true) {
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;
        if (row >= 1 && row <= SIZE && col >= 1 && col <= SIZE && board[row - 1][col - 1] == ' ') {
            board[row - 1][col - 1] = currentPlayer;
            break;
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }
}

void playGame() {
    initializeBoard();
    bool gameWon = false;

    while (true) {
        displayBoard();
        makeMove();

        if (isWin()) {
            displayBoard();
            cout << "Player " << currentPlayer << " wins!" << endl;
            gameWon = true;
            break;
        }

        if (isDraw()) {
            displayBoard();
            cout << "The game is a draw!" << endl;
            break;
        }

        switchPlayer();
    }
}

int main() {
    char playAgain;

    do {
        playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!" << endl;

    return 0;
}
