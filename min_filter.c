#include<stdio.h>
#include<stdlib.h>
#define row 256
#define col 256

int min(int b[row+2][col+2],int i, int j)
{
	int c[9],x,y,temp;
	c[0]=b[i-1][j-1];
	c[1]=b[i-1][j];
	c[2]=b[i-1][j+1];
	c[3]=b[i][j-1];
	c[4]=b[i][j];
	c[5]=b[i][j+1];
	c[6]=b[i+1][j-1];
	c[7]=b[i+1][j];
	c[8]=b[i+1][j+1];
	for(x=0;x<8;x++)
	{
		for(y=0;y<8-x;y++)
		{
			if(c[y]>c[y+1])
			{
				temp=c[y];
				c[y]=c[y+1];
				c[y+1]=temp;
			}
		}
	}
	return c[0];
}
main()
{
	FILE *fp,*fq;
	int i,j,sum,avg;
	int a[row][col],b[row+2][col+2];
	fp=fopen("original_mandrill_input.txt","r");
	fq=fopen("original_mandrill_minfilter.txt","w+");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			fscanf(fp,"%d",&a[i][j]);
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
	//min filter
	for(i=1;i<=row;i++)
	{
		for(j=1;j<=col;j++)
		{
			b[i][j]=min(b,i,j);
		}
	}
	for(i=1;i<=row;i++)
	{
		for(j=1;j<=col;j++)
		{
			fprintf(fq,"%d ",b[i][j]);
		}
	}
	fclose(fp);
	fclose(fq);
	
}
