//Dilation operation on image
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int a[2000][2000];
int b[2000][2000];
void main()
{
	FILE *fptr;
	int n,m,r,i,j,p,q,min;
	char ch;
	fptr=fopen("../Boundary Omission-trial/eye27_erosion.pgm","r");
	fscanf(fptr," %c%d %d %d %d",&ch, &i, &n, &m, &r);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			fscanf(fptr,"%d",&a[i][j]);
		}
	}
	
	for(i=1;i<m+1;i++)    //copying original array values
	{
		for(j=1;j<n+1;j++)
		{
			b[i][j]=a[i-1][j-1];
		}
	}
	for(i=1;i<m+1;i++)    //vertical padding on right and left columns
	{
		b[i][0]=b[i][1];
		b[i][n+1]=b[i][n];
	}
	for(j=0;j<n+2;j++)    //horizontal padding on top and bottom rows
	{
		b[0][j]=b[1][j];
		b[n+1][j]=b[n][j];
	}
	fclose(fptr);
	
	
	fptr=fopen("../Boundary Omission-trial/eye27_closing.pgm","w");
	fprintf(fptr,"P2\n%d %d %d\n",n,m,r);
	for(i=1;i<m+1;i++)
	{
		for(j=1;j<n+1;j++)
		{
			min=b[i][j];
			for(p=-1;p<=1;p++)
			{
					if(b[i+p][j]<min)
						min=b[i+p][j];
			}
			fprintf(fptr,"%d ",min);
		}	
	}
	fclose(fptr);
}
