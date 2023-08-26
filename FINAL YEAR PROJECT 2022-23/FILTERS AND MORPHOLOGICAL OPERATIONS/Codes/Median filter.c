#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int a[2000][2000];
int b[2000][2000];
void main()
{
	FILE *fptr;
	int n,m,r,i,j,p,q,c,k,l;
	char ch;
	int med[9];
	fptr=fopen("Dilation.pgm","r");
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
	
	
	fptr=fopen("Median Filter.pgm","w");
	fprintf(fptr,"P2\n%d %d %d\n",n,m,r);
	for(i=1;i<m+1;i++)
	{
		for(j=1;j<n+1;j++)
		{
			c=0;
			for(p=-1;p<=1;p++)
			{
				for(q=-1;q<=1;q++)
				{
					med[c++]=b[i+p][j+q];
				}
			}
			for(k=0;k<8;k++)
			{
				for(l=k+1;l<9;l++)
				{
					int temp;
					if(med[k]>med[l])
					{
						temp=med[k];
						med[k]=med[l];
						med[l]=temp;
					}
				}
			}
			fprintf(fptr,"%d ",med[4]);
		}	
	}
	fclose(fptr);
}
