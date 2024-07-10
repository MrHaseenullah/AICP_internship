#include <iostream>
using namespace std;

// Define the TicTacToe class
class TicTacToe {
private:
    int board[3][3];  // 3x3 board for the game

public:
    // Constructor to initialize the board with all zeros
    TicTacToe() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = 0;  // Set each cell to 0, indicating an empty cell
            }
        }
    }

    // Function to print the current state of the board
    void printBoard() {
        cout << "Current board state:" << endl;
        cout << "  0 1 2" << endl;  // Column labels
        for (int i = 0; i < 3; ++i) {
            cout << i << " ";  // Row label
            for (int j = 0; j < 3; ++j) {
                // Determine the character to print based on the cell value
                char mark = board[i][j] == 1 ? 'X' : (board[i][j] == 2 ? 'O' : '-');
                cout << mark << " ";  // Print the character
            }
            cout << endl;
        }
    }

    // Function to check if a move is valid
    bool validMove(int row, int col) {
        // Check if the move is within bounds and the cell is empty
        return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == 0);
    }

    // Function to make a move if it is valid
    bool makeMove(int player, int row, int col) {
        if (validMove(row, col)) {
            board[row][col] = player;  // Set the cell to the player's number (1 or 2)
            return true;
        } else {
            cout << "Invalid move. Try again." << endl;
            return false;
        }
    }

    // Function to check the game status
    int gameStatus() {
        // Check rows for a win
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != 0) 
                return board[i][0];
        }
        // Check columns for a win
        for (int i = 0; i < 3; ++i) {
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != 0) 
                return board[0][i];
        }
        // Check diagonals for a win
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != 0) 
            return board[0][0];
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != 0) 
            return board[0][2];

        // Check for draw
        bool draw = true;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == 0) draw = false;  // If any cell is empty, it's not a draw
            }
        }
        if (draw) return 0;  // Return 0 if it's a draw

        return -1;  // Return -1 if the game is still ongoing
    }
};

int main() {
    TicTacToe game;  // Create an instance of the TicTacToe class
    int currentPlayer = 1;  // Start with player 1
    int row, col;  // Variables to store the player's move
    int status;  // Variable to store the game status

    while (true) {
        game.printBoard();  // Print the current board state
        // Ask the current player to enter their move
        cout << "Player " << (currentPlayer == 1 ? "X" : "O") << ", enter your move (row and column) "<<endl<<"Enter value for row: ";
        cin >> row;
        cout<<"Enter value for column: ";
        cin >> col;

        // If the move is valid, make the move
        if (game.makeMove(currentPlayer, row, col)) {
            status = game.gameStatus();  // Check the game status
            if (status == 1 || status == 2) {
                game.printBoard();  // Print the final board state
                cout << "Player " << (status == 1 ? "X" : "O") << " wins!" << endl;
                break;  // End the game if there is a winner
            } else if (status == 0) {
                game.printBoard();  // Print the final board state
                cout << "It's a draw!" << endl;
                break;  // End the game if it's a draw
            }

            currentPlayer = (currentPlayer == 1) ? 2 : 1;  // Switch to the other player
        }
    }

    return 0;  // End the program
}
