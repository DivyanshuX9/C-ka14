#include <stdio.h>
int main()
{
    int n;
    printf("enter the size of matrix");
    scanf("%d", &n);
    int ar1[n][n], ar2[n][n], multi[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &ar1[i][j]);
        }
        printf("\n");
    }
    printf("\n2nd matrix\n");
     for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &ar2[i][j]);
        }
        printf("\n");
    }
    for (int c = 0; c < n; c++)
    {
        for (int a = 0; a < n; a++)
        { 
          int  sum=0;
            for (int b = 0; b < n; b++)
            {
                sum += ar1[c][b] * ar2[b][a];
            }
            multi[c][a] = sum;}
        }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", multi[i][j]);
        }
        printf("\n");
    }
    return 0;
}