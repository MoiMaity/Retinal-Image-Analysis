#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define ROWS 576
#define COLS 768

int image1[ROWS][COLS],image2[ROWS][COLS],result[ROWS][COLS];
int i,j;

void main()
{
	FILE *fptr1,*fptr2,*fptr3;
	fptr1=fopen("averagefilterinput.txt","r");
	fptr2=fopen("input.txt","r");
	
	for(i=0;i<ROWS;i++)
	{
		for(j=0;j<COLS;j++)
		{
			fscanf(fptr1,"%d",&image1[i][j]);
		}
	}
	
	for(i=0;i<ROWS;i++)
	{
		for(j=0;j<COLS;j++)
		{
			fscanf(fptr2,"%d",&image2[i][j]);
		}
	}
	
	fptr3=fopen("Normalised_Background_Image.pgm","w");
	fprintf(fptr3,"P2\n768 576 255 ");
	
	for(i=0;i<ROWS;i++)
	{
		for(j=0;j<COLS;j++)
		{
			result[i][j]=image2[i][j]-image1[i][j];
			if (result[i][j]<0)
				result[i][j]=0;
			fprintf(fptr3,"%d ",result[i][j]);
		}
	}
	
	fclose(fptr1);
	fclose(fptr2);
	fclose(fptr3);
}
