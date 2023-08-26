#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 576
#define COLS 768

int bit_planes[8][ROWS][COLS];
int reconstructed_image[ROWS][COLS];

int main()
{
    FILE *fp,*fq;
    int i, j, k;
	fp=fopen("bitplaneoutput.txt","r");
    fq=fopen("reconstructedimage.pgm","w");
    
    for(i=1;i<=ROWS;i++)
	{
		for(j=1;j<=COLS;j++)
		{
			for(k=0;k<8;k++)
			{
				fscanf(fp,"%d",&bit_planes[k][i][j]);
			}
		}
	}
    
    for (i = 0; i < ROWS; i++) 
	{
        for (j = 0; j < COLS; j++) 
		{
            int pixel = 0;
            for (k = 0; k < 8; k++) 
			{
                pixel |= bit_planes[k][i][j] << k;
            }
            reconstructed_image[i][j] = pixel;
        }
    }
    
    fprintf(fq,"P2\n768 576 255 ");
    for(i=0;i<ROWS;i++)
	{
		for(j=0;j<COLS;j++)
		{
			fprintf(fq,"%d ",reconstructed_image[i][j]);
		}
	}
    
    fclose(fp);
	fclose(fq);
    return 0;
}
