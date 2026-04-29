#include <iostream>
using namespace std;

#define N 4

bool isSafe(int board[N][N], int row, int col) {
    // Check column
    for (int i = 0; i < row; i++)
        if (board[i][col])
            return false;

    // Check left diagonal
    for (int i=row, j=col; i>=0 && j>=0; i--, j--)
        if (board[i][j])
            return false;

    // Check right diagonal
    for (int i=row, j=col; i>=0 && j<N; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

bool solve(int board[N][N], int row) {
    if (row == N)
        return true;

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;

            if (solve(board, row + 1))
                return true;

            // Backtrack
            board[row][col] = 0;
        }
    }
    return false;
}

void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << (board[i][j] ? "Q " : ". ");
        cout << endl;
    }
}

int main() {
    int board[N][N] = {0};

    if (solve(board, 0))
        printBoard(board);
    else
        cout << "No solution";

    return 0;
}
