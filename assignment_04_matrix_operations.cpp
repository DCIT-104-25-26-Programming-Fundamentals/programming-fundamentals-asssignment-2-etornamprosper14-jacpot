// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_SIZE = 10;

void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// PART A - Transpose a Matrix
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols,
                      int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

// PART B - Add Two Matrices
void addMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE],
                  int rows, int cols, int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

// PART C - Multiply Two Matrices
void multiplyMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE],
                       int m, int n, int p, int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++) {
                sum += a[i][k] * b[k][j];
            }
            result[i][j] = sum;
        }
    }
}

int main() {
    // ---------- PART A: Transpose ----------
    cout << "--- Part A: Transpose a Matrix ---" << endl;
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int matrixA[MAX_SIZE][MAX_SIZE];
    readMatrix(matrixA, rows, cols);

    int transposed[MAX_SIZE][MAX_SIZE];
    transposeMatrix(matrixA, rows, cols, transposed);

    cout << "\nOriginal Matrix:" << endl;
    displayMatrix(matrixA, rows, cols);
    cout << "\nTransposed Matrix:" << endl;
    displayMatrix(transposed, cols, rows);

    // ---------- PART B: Addition ----------
    cout << "\n--- Part B: Add Two Matrices ---" << endl;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int addA[MAX_SIZE][MAX_SIZE];
    int addB[MAX_SIZE][MAX_SIZE];
    cout << "Enter values for Matrix A:" << endl;
    readMatrix(addA, rows, cols);
    cout << "Enter values for Matrix B:" << endl;
    readMatrix(addB, rows, cols);

    int sumResult[MAX_SIZE][MAX_SIZE];
    addMatrices(addA, addB, rows, cols, sumResult);

    cout << "\nSum of Matrices:" << endl;
    displayMatrix(sumResult, rows, cols);

    // ---------- PART C: Multiplication ----------
    cout << "\n--- Part C: Multiply Two Matrices ---" << endl;
    int m, n, p;
    cout << "Enter rows of Matrix A (M): ";
    cin >> m;
    cout << "Enter columns of Matrix A / rows of Matrix B (N): ";
    cin >> n;
    cout << "Enter columns of Matrix B (P): ";
    cin >> p;

    int mulA[MAX_SIZE][MAX_SIZE];
    int mulB[MAX_SIZE][MAX_SIZE];
    cout << "Enter values for Matrix A:" << endl;
    readMatrix(mulA, m, n);
    cout << "Enter values for Matrix B:" << endl;
    readMatrix(mulB, n, p);

    int productResult[MAX_SIZE][MAX_SIZE];
    multiplyMatrices(mulA, mulB, m, n, p, productResult);

    cout << "\nProduct of Matrices (A x B):" << endl;
    displayMatrix(productResult, m, p);

    return 0;
}