// High-pass filter
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int a[2000][2000];
int b[2000][2000];

void main()
{
    FILE *fptr;
    int n, m, r, i, j, p, q, k, l;
    char ch;

    fptr = fopen("../Boundary Omission-trial/19_test.pgm", "r");
    fscanf(fptr, " %c %d %d %d %d", &ch, &i, &n, &m, &r);

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            fscanf(fptr, "%d", &a[i][j]);
        }
    }

    for (i = 1; i < m - 1; i++)
    {
        for (j = 1; j < n - 1; j++)
        {
            int sum = 0;
            for (p = -1; p <= 1; p++)
            {
                for (q = -1; q <= 1; q++)
                {
                    sum += a[i + p][j + q];
                }
            }
            int avg = sum / 9;
            a[i][j] =  a[i][j]-avg;
        }
    }

    fclose(fptr);

    fptr = fopen("../Boundary Omission-trial/High pass-19.pgm", "w");
    fprintf(fptr, "P2\n%d %d %d\n", n, m, r);

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            fprintf(fptr, "%d ", a[i][j]);
        }
        fprintf(fptr, "\n");
    }

    fclose(fptr);
}

