#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define row 576
#define col 768

int i,j,k;
int a[row][col],b[row+2][col+2],d[row][col],e[row][col],f[row][col];

int average(int b[row+2][col+2],int i,int j)
{
	int c[9],u,v;
	c[0]=b[i-1][j-1];
	c[1]=b[i-1][j];
	c[2]=b[i-1][j+1];
	c[3]=b[i][j-1];
	c[4]=b[i][j];
	c[5]=b[i][j+1];
	c[6]=b[i+1][j-1];
	c[7]=b[i+1][j];
	c[8]=b[i+1][j+1];
	int t = (c[0]+c[1]+c[2]+c[3]+c[4]+c[5]+c[6]+c[7]+c[8])/9;
	if(t>255)
		return 255;
	else if(t<0)
		return 0;
	else
		return t;
	
}
main()
{
	FILE *fp;
	FILE *fq;
	int i,j;
	fp = fopen("1_bottomhat_input.txt","r");
	fq = fopen("1_unsharp.txt","w+");
	for(i = 0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			fscanf(fp,"%d ",&k);
			a[i][j]=k;
		
		}
	}
	//corner padding
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(i==0)
			{
				if(j==0)
					b[i][j]=a[i][j];
				else if(j==col-1)
					b[i][j+2]=a[i][j];
			}
			if(i==row-1)
			{
				if(j==0)
					b[i+2][j]=a[i][j];
				else if(j==col-1)
					b[i+2][j+2]=a[i][j];
			}
		}
	}
	//top and bottom padding
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(i==0)
				b[i][j+1]=a[i][j];
			if(i==row-1)
				b[i+2][j+1]=a[i][j];
		}
	}
	//left and right padding
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(j==0)
				b[i+1][j]=a[i][j];
			if(j==col-1)
				b[i+1][j+2]=a[i][j];
		}
	}
	//remaining
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			b[i+1][j+1]=a[i][j];
		}
	}
	//average filter
	for(i=1;i<=row;i++)
	{
		for(j=1;j<=col;j++)
		{
			d[i][j] = average(b,i,j);
		}
	}
	//unsharp mask
	for(i=1;i<=row;i++)
	{
		for(j=1;j<=col;j++)
		{
			e[i][j] = a[i][j]-d[i][j];
			f[i][j] = a[i][j]+e[i][j];
			if(f[i][j]>255)
				f[i][j]=255;
			else if(f[i][j]<0)
				f[i][j]=0;
		}
	}
	fprintf(fq,"P2\n768 576 255 ");
	for(i=1;i<=row;i++)
	{
		for(j=1;j<=col;j++)
		{
			fprintf(fq,"%d ",f[i][j]);
		}
		
	}
	fclose(fp);
	fclose(fq);
	
}
