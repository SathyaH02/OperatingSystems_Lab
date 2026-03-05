#include <stdio.h>
int main()
{
    int m,matrix[100][100];
    printf("Enter the no.of rows in the square matrix: ");
    scanf("%d",&m);
    printf("Enter elements of the matrix: ");
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<m; j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }

    for (int i=0; i<m; i++)
    {
        int rowSum=0,colSum=0;
        for (int j=0; j<m; j++)
        {
            rowSum+=matrix[i][j];
            colSum+=matrix[j][i];
        }
        printf("\nSum of row %d: %d", i+1, rowSum);
        printf("\nSum of column %d: %d", i+1, colSum);
    }

    return 0;
}
