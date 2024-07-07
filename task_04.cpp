#include <iostream>
using namespace std;

void printGrid(int grid[9][9]) {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

bool findEmptyLocation(int grid[9][9], int& row, int& col) {
    for (row = 0; row < 9; ++row) {
        for (col = 0; col < 9; ++col) {
            if (grid[row][col] == 0) {
                return true;
            }
        }
    }
    return false;
}

bool isValidMove(int grid[9][9], int row, int col, int num) {
    // Check if 'num' is not already present in the current row
    for (int i = 0; i < 9; ++i) {
        if (grid[row][i] == num) {
            return false;
        }
    }  
    // Check if 'num' is not already present in the current col
    for (int i = 0; i < 9; ++i) {
        if (grid[i][col] == num) {
            return false;
        }
    }
    // Check if 'num' is not already present in the current 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }
    
    return true;
}

bool solveSudoku(int grid[9][9]) {
    int row, col;   
    if (!findEmptyLocation(grid, row, col)) {
        return true;
    }
    
    for (int num = 1; num <= 9; ++num) {
        if (isValidMove(grid, row, col, num)) {
            grid[row][col] = num;
            
            if (solveSudoku(grid)) {
                return true;
            }
            
            grid[row][col] = 0; // Backtrack
        }
    }
    
    return false;
}

void readGrid(int grid[9][9]) {
    cout << "Enter the Sudoku grid (9x9, use 0 for empty cells):\n";
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            cin >> grid[row][col];
        }
    }
}

int main() {
    int grid[9][9];
    
    readGrid(grid);
    
    if (solveSudoku(grid)) {
        cout << "Sudoku Solved Successfully:" << endl;
        printGrid(grid);
    } else {
        cout << "No solution exists" << endl;
    }
    
    return 0;
}
