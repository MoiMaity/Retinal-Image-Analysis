#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int i,j,k;
int a[1000][1000],b[1000+2][1000+2],d[1000][1000],e[1000][1000],f[1000][1000];
int unsharp(int b[1000+2][1000+2],int i,int j)
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
	int t = (c[0]+2*c[1]+c[2]+2*c[3]+4*c[4]+2*c[5]+c[6]+2*c[7]+c[8])/16;
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
	char ch;
	int row,col,max_val,n;
	fp = fopen("01_test.pgm","r");
	fq = fopen("01_unsharp.pgm","w");
	fscanf(fp,"%c %d %d %d %d",&ch,&n,&col,&row,&max_val);
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
	
	for(i=1;i<=row;i++)
	{
		for(j=1;j<=col;j++)
		{
			d[i][j] = unsharp(b,i,j);
		}
	}
	for(i=1;i<=row;i++)
	{
		for(j=1;j<=col;j++)
		{
			f[i][j] = a[i][j]-d[i][j];
			e[i][j] = a[i][j]+f[i][j];
			if(e[i][j]>255)
				e[i][j]=255;
			else if(e[i][j]<0)
				e[i][j]=0;
		}
	}
	fprintf(fq,"P2 %d %d %d\n",col,row,max_val);
	for(i=1;i<=row;i++)
	{
		for(j=1;j<=col;j++)
		{
			fprintf(fq,"%d ",e[i][j]);
		}
		
	}
	fclose(fp);
	fclose(fq);
	
}
