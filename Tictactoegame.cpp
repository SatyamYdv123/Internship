#include <iostream>
#include <vector>

using namespace std;

// Function to display the current state of the board
void displayBoard(const vector<vector<char>>& board) {
    cout << "Current Board:\n";
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    return (board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
           (board[0][2] == player && board[1][1] == player && board[2][0] == player);
}

// Function to check for a draw
bool checkDraw(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false; // Found an empty cell, not a draw
            }
        }
    }
    return true; // No empty cells, it's a draw
}

// Main game function
void playGame() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); // Initialize a 3x3 board with spaces
    char currentPlayer = 'X'; // Start with player X

    while (true) {
        displayBoard(board);
        int row, col;

        // Get valid player input
        while (true) {
            cout << "Player " << currentPlayer << ", enter your move (row and column 0-2): ";
            cin >> row >> col;
            if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
                board[row][col] = currentPlayer; // Update the board
                break; // Valid input, exit the loop
            } else {
                cout << "Invalid move. Try again." << endl;
            }
        }

        // Check for win or draw
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }
        if (checkDraw(board)) {
            displayBoard(board);
            cout << "The game is a draw!" << endl;
            break;
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

int main() {
    do {
        playGame();
        char playAgain;
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
        if (playAgain != 'y') {
            break;
        }
    } while (true);

    cout << "Thank you for playing!" << endl;
    return 0;
}
