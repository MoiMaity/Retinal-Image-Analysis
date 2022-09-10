#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define row 576
#define col 768

int a[row][col],b[row+2][col+2],d[row][col],e[row+2][col+2],f[row][col],g[row][col];
int se[3][3]={{0,255,0},{255,255,255},{0,255,0}};

int dilation(int b[row+2][col+2], int i, int j, int se[3][3])
{
	if(b[i][j]==se[1][1] || b[i-1][j]==se[0][1] || b[i][j-1]==se[1][0] || b[i][j+1]==se[1][2] || b[i+1][j]==se[2][1])
			return 255;
	else
		return 0;
}

int erosion(int b[row+2][col+2], int i, int j, int se[3][3])
{
	if(b[i][j]==se[1][1] && b[i-1][j]==se[0][1] && b[i][j-1]==se[1][0] && b[i][j+1]==se[1][2] && b[i+1][j]==se[2][1])
			return 255;
	else
		return 0;
}

main()
{
	FILE *fp,*fq;
	int i,j,m;
	fp=fopen("1_threshold_input.txt","r");
	fq=fopen("1_tophat.txt","w+");
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
	//erosion
	for(i=1;i<=row;i++)
	{
		for(j=1;j<=col;j++)
		{
			d[i][j]=erosion(b,i,j,se);
			
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
					e[i][j]=d[i][j];
				else if(j==col-1)
					e[i][j+2]=d[i][j];
			}
			if(i==row-1)
			{
				if(j==0)
					e[i+2][j]=d[i][j];
				else if(j==col-1)
					e[i+2][j+2]=d[i][j];
			}
		}
	}
	//top and bottom padding
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(i==0)
				e[i][j+1]=d[i][j];
			if(i==row-1)
				e[i+2][j+1]=d[i][j];
		}
	}
	//left and right padding
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(j==0)
				e[i+1][j]=d[i][j];
			if(j==col-1)
				e[i+1][j+2]=d[i][j];
		}
	}
	//remaining
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			e[i+1][j+1]=d[i][j];
		}
	}
	//dilation
	for(i=1;i<=row;i++)
	{
		for(j=1;j<=col;j++)
		{
			f[i][j]=dilation(e,i,j,se);
			
		}
	}
	//top hat
	for(i=1;i<=row;i++)
	{
		for(j=1;j<=col;j++)
		{
			g[i][j]=a[i][j]-f[i][j];
			if(g[i][j]<0)
				g[i][j]=0;	
		}
	}
	fprintf(fq,"P2\n768 576 255 ");
	for(i=1;i<=row;i++)
	{
		for(j=1;j<=col;j++)
		{
			fprintf(fq,"%d ",g[i][j]);
		}
	}
	fclose(fp);
	fclose(fq);
	
}
