//thresholding
#include<stdio.h>
#include<stdlib.h>
int a[2000][2000];
void main()
{
	int n,m,r,i,j;
	char ch;
	FILE *fptr;
	fptr = fopen("../Boundary Omission-trial/eye27_closing.pgm","r");
	fscanf(fptr,"%c %d %d %d %d",&ch, &i, &n, &m, &r);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			fscanf(fptr,"%d",&a[i][j]);
		}
	}
	fptr = fopen("../Boundary Omission-trial/eye27_tophat.pgm","w");
	fprintf(fptr,"P2\n%d %d %d\n",n,m,r);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if (a[i][j]>4)
				fprintf(fptr," %d",255);
			else
				fprintf(fptr," %d",0);
		}
	}
	fclose(fptr);
}
