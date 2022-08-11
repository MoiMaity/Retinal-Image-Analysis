#include<stdio.h>
#include<stdlib.h>
#define row 3
#define col 3

main()
{
	//int row,col;
	int i,j;
	//printf("Enter row and column :",&row,&col);
	int a[row][col],b[row+2][col+2];
	printf("Enter terms :");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	/*for(i=0;i<3;i++)			//top and bottom
	{
		for(j=0;j<3;j++)
		{
			b[i][j]=a[i][j+3];
			b[i][j+3*(3-1)]=a[i][i+3*(3-1)-3];
		}
	}
	for(j=0;j<3;j++)			//left and right
	{
		for(i=0;i<3;i++)
		{
			b[i*3][j]=a[i*3+1][j];
			b[i*3+3-1][j]=a[i*3+3-2][j];
		}
	}*/
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
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
	for(i=0;i<row+2;i++)
	{
		for(j=0;j<col+2;j++)
		{
			printf("%d ",b[i][j]);
		}
		printf("\n");
	}
	
}
