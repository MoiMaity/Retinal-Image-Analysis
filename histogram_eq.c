#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define row 256
#define col 256

void main()
{
	FILE *fp,*fq;
	int i,j,k;
	int a[row][col];
	int x[row+1],y[row+1];
	float z[row+1],p;
	for(i=0;i<row+1;i++)
	{
		x[i]=0;
		y[i]=0;
		z[i]=0.0;
	}
	fp=fopen("original_mandrill_input.txt","r");
	fq=fopen("original_mandrill_histogram.txt","w+");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			fscanf(fp,"%d",&a[i][j]);
			k=a[i][j];
			x[k]++;
		}
	}
	y[0]=x[0];
	for(i=1;i<row+1;i++)
	{
		y[i]=y[i-1]+x[i];
	}
	for(i=0;i<row+1;i++)
	{
		p=((float)y[i]/(float)y[row]);
		z[i]=(round)(p*row);
		//printf("%.2f ",z[i]);
		
	}
	
	
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			k=(int)z[a[i][j]];
			fprintf(fq,"%d ",k);
		}
	}
	fclose(fp);
	fclose(fq);
}
