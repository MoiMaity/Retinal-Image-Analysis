//Sobel operator
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int a[2000][2000];
int b[2000][2000];
int n,m,r,i,j,p,q;
void main()
{
	FILE *fptr;
	int sx,sy;
	char ch;
	float g;
	int cx[3][3]= {{-1,0,1},{-2,0,2},{-1,0,1}};
	int cy[3][3]= {{1,2,1},{0,0,0},{-1,-2,-1}};
	fptr=fopen("../Boundary Omission-trial/Boundary1-19.pgm","r");
	fscanf(fptr,"%c %d %d %d %d",&ch, &i, &n, &m, &r);
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
	
	
	fptr=fopen("../Boundary Omission-trial/Sobel Boundary2-19.pgm","w");
	fprintf(fptr,"P2\n%d %d %d\n",n,m,r);
	for(i=1;i<m+1;i++)
	{
		for(j=1;j<n+1;j++)
		{
			sx=0,sy=0;
			for(p=-1;p<=1;p++)
			{
				for(q=-1;q<=1;q++)
				{
					sx+=b[i+p][j+q]*cx[p+1][q+1];
					sy+=b[i+p][j+q]*cy[p+1][q+1];
				}
			}
			g=sqrt(pow(sx,2)+pow(sy,2));
			fprintf(fptr,"%d ",(int)g);
		}	
	}
	fclose(fptr);
}
