#include<stdio.h>
#include<stdlib.h>

#define row 576
#define col 768

int a[row][col],b[row][col];
int th=100;

main()
{
	FILE *fp,*fq;
	int i,j;
	fp=fopen("1_histogram_input.txt","r");
	fq=fopen("1_threshold(hist).txt","w+");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			fscanf(fp,"%d",&a[i][j]);
		}
	}
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(a[i][j]>=th)
				b[i][j]=255;
			else if(a[i][j]<th)
				b[i][j]=0;
		}
	}
	fprintf(fq,"P2\n768 576 255 ");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			fprintf(fq,"%d ",b[i][j]);
		}
	}
	fclose(fp);
	fclose(fq);
}
