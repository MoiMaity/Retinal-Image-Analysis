//Contrast limited adaptive histogram equalization (clahe)
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int a[2000][2000];
int a2[2000][2000];
int b[500];
int d[500];
float c[500];
void main()
{
	int n,m,r,i,j,v;
	char ch;
	FILE *fptr;
	fptr = fopen("../Clahe Paper/19_test.pgm","r");
	fscanf(fptr," %c%d %d %d %d",&ch, &i, &n, &m, &r);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			fscanf(fptr,"%d",&a[i][j]);	
			a2[i][j]=0;			
		}
	}
	fclose(fptr);
	//1st
	for(i=0;i<=r;i++)
	{
		b[i]=0;
		d[i]=0;
		c[i]=0.0;
	}
	for(i=0;i<=m/2;i++)
	{
		for(j=0;j<=n/2;j++)
		{
			v=a[i][j];
			b[v]++;
		}
	}
	d[0]=b[0];
	for(i=1;i<=r;i++)
	{
		d[i]=d[i-1]+b[i];
	}
	for(i=0;i<=r;i++)
	{
		c[i]=((float)d[i]/(float)d[r])*r;	
		c[i]=round(c[i]);
	}
	for(i=0;i<=m/2;i++)
	{
		for(j=0;j<=n/2;j++)
		{
			v=a[i][j];
			a2[i][j]=(int)c[v];
		}
	}
	//2nd
	for(i=0;i<=r;i++)
	{
		b[i]=0;
		d[i]=0;
		c[i]=0.0;
	}
	for(i=0;i<=m/2;i++)
	{
		for(j=n/2;j<n;j++)
		{
			v=a[i][j];
			b[v]++;
		}
	}
	d[0]=b[0];
	for(i=1;i<=r;i++)
	{
		d[i]=d[i-1]+b[i];
	}
	for(i=0;i<=r;i++)
	{
		c[i]=((float)d[i]/(float)d[r])*r;	
		c[i]=round(c[i]);
	}
	for(i=0;i<=m/2;i++)
	{
		for(j=n/2;j<n;j++)
		{
			v=a[i][j];
			a2[i][j]=(int)c[v];
		}
	}
	//3rd
	for(i=0;i<=r;i++)
	{
		b[i]=0;
		d[i]=0;
		c[i]=0.0;
	}
	for(i=m/2;i<m;i++)
	{
		for(j=0;j<=n/2;j++)
		{
			v=a[i][j];
			b[v]++;
		}
	}
	d[0]=b[0];
	for(i=1;i<=r;i++)
	{
		d[i]=d[i-1]+b[i];
	}
	for(i=0;i<=r;i++)
	{
		c[i]=((float)d[i]/(float)d[r])*r;	
		c[i]=round(c[i]);
	}
	for(i=m/2;i<m;i++)
	{
		for(j=0;j<=n/2;j++)
		{
			v=a[i][j];
			a2[i][j]=(int)c[v];
		}
	}
	//4th
	for(i=0;i<=r;i++)
	{
		b[i]=0;
		d[i]=0;
		c[i]=0.0;
	}
	for(i=m/3;i<m;i++)
	{
		for(j=n/3;j<n;j++)
		{
			v=a[i][j];
			b[v]++;
		}
	}
	d[0]=b[0];
	for(i=1;i<=r;i++)
	{
		d[i]=d[i-1]+b[i];
	}
	for(i=0;i<=r;i++)
	{
		c[i]=((float)d[i]/(float)d[r])*r;	
		c[i]=round(c[i]);
	}
	for(i=m/2;i<m;i++)
	{
		for(j=n/2;j<n;j++)
		{
			v=a[i][j];
			a2[i][j]=(int)c[v];
		}
	}
	
	
	fptr = fopen("../Clahe Paper/Clahe.pgm","w");
	fprintf(fptr,"P2\n%d %d %d\n",n,m,r);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			fprintf(fptr,"%d ",a2[i][j]);
		}
	}
	fclose(fptr);
}
