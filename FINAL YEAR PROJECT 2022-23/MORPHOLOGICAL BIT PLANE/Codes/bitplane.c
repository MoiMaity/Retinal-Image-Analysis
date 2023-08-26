#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 576
#define COLS 768

int image[ROWS][COLS];
int bit_planes[8][ROWS][COLS];

int main()
{
    FILE *fp,*fq;
    int i,j,k;
    fp=fopen("input.txt","r");
    fq=fopen("bitplaneoutput.pgm","w");
    
    for(i=0;i<ROWS;i++)
	{
		for(j=0;j<COLS;j++)
		{
			fscanf(fp,"%d",&image[i][j]);
		}
	}
    
    for (i = 0; i < ROWS; i++) 
	{
        for (j = 0; j < COLS; j++) 
		{
            int pixel = image[i][j];
            for (k = 0; k < 8; k++) 
			{
                int bit = (pixel >> k) & 1;
                bit_planes[k][i][j] = bit;
            }
        }
    }

    fprintf(fq,"P2\n768 576 255 ");
    for(i=1;i<=ROWS;i++)
	{
		for(j=1;j<=COLS;j++)
		{
			for(k=0;k<8;k++)
			{
				fprintf(fq,"%d ",bit_planes[k][i][j]);
			}
		}
	}
	fclose(fp);
	fclose(fq);
    return 0;
}
 
