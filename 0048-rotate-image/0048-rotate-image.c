void rotate(int** matrix, int matrixSize, int* matrixColSize)
 {
    int n=matrixSize;
    for (int j = 0; j < n / 2; j++) {
        int first = j;
        int last = n - 1 - j;

        for (int i = first; i < last; i++) {
            int offset = i - first;

            int top = matrix[first][i];

            matrix[first][i] = matrix[last - offset][first];
            matrix[last - offset][first] = matrix[last][last - offset];
            matrix[last][last - offset] = matrix[i][last];
            matrix[i][last] = top;
        }
    }
}
