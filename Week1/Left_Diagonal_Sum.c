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

    int sum=0;
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<m; j++)
        {
            if (i==j) {sum+=matrix[i][j];}
        }
    }
    printf("Sum of the left diagonal elements : %d",sum);
    return 0;
}
