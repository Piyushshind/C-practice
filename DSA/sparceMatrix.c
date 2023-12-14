// Write a program to represent sparse matrix using array and perform simple and fast transpose.

#include <stdio.h>

#define MAX_SIZE 100
struct MatrixElement
{
    int row;
    int col;
    int value;
};
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols)
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}
void convertToSparse(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, struct MatrixElement sparseArray[], int *sparseSize)
{
    *sparseSize = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] != 0)
            {
                sparseArray[*sparseSize].row = i;
                sparseArray[*sparseSize].col = j;
                sparseArray[*sparseSize].value = matrix[i][j];
                (*sparseSize)++;
            }
        }
    }
}
void simpleTranspose(struct MatrixElement sparseArray[], int sparseSize, struct MatrixElement transposedSparseArray[])
{
    for (int i = 0; i < sparseSize; i++)
    {
        transposedSparseArray[i].row = sparseArray[i].col;
        transposedSparseArray[i].col = sparseArray[i].row;
        transposedSparseArray[i].value = sparseArray[i].value;
    }
}
void fastTranspose(struct MatrixElement sparseArray[], int sparseSize, struct MatrixElement transposedSparseArray[])
{
    int rowCount[MAX_SIZE], startingPos[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++)
    {
        rowCount[i] = 0;
    }

    for (int i = 0; i < sparseSize; i++)
    {
        rowCount[sparseArray[i].col]++;
    }

    startingPos[0] = 0;
    for (int i = 1; i < MAX_SIZE; i++)
    {
        startingPos[i] = startingPos[i - 1] + rowCount[i - 1];
    }

    for (int i = 0; i < sparseSize; i++)
    {
        int pos = startingPos[sparseArray[i].col];
        transposedSparseArray[pos].row = sparseArray[i].col;
        transposedSparseArray[pos].col = sparseArray[i].row;
        transposedSparseArray[pos].value = sparseArray[i].value;
        startingPos[sparseArray[i].col]++;
    }
}

int main()
{
    int matrix[MAX_SIZE][MAX_SIZE], rows, cols;

    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter the matrix elements:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    struct MatrixElement sparseArray[MAX_SIZE * MAX_SIZE];
    int sparseSize;
    convertToSparse(matrix, rows, cols, sparseArray, &sparseSize);
    printf("\nOriginal Matrix:\n");
    displayMatrix(matrix, rows, cols);
    printf("\nSparse Matrix:\n");
    for (int i = 0; i < sparseSize; i++)
    {
        printf("%d %d %d\n", sparseArray[i].row, sparseArray[i].col, sparseArray[i].value);
    }

    struct MatrixElement transposedSparseArray[MAX_SIZE * MAX_SIZE];
    simpleTranspose(sparseArray, sparseSize, transposedSparseArray);
    printf("\nSimple Transpose:\n");
    for (int i = 0; i < sparseSize; i++)
    {
        printf("%d %d %d\n", transposedSparseArray[i].row, transposedSparseArray[i].col, transposedSparseArray[i].value);
    }
    fastTranspose(sparseArray, sparseSize, transposedSparseArray);
    printf("\nFast Transpose:\n");
    for (int i = 0; i < sparseSize; i++)
    {
        printf("%d %d %d\n", transposedSparseArray[i].row, transposedSparseArray[i].col, transposedSparseArray[i].value);
    }

    return 0;
}
