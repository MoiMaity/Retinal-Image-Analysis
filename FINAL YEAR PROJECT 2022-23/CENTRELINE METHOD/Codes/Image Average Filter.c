//Average filter on image
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int a[1024][1024];
int b[1026][1026];
int n,m,r,i,j,p,q,s,size=13;
float avg;
char ch;
void main()
{
	FILE *fptr;
	int z=(size-1)/2;
	fptr=fopen("../Boundary Omission-trial/eye27_green.pgm","r");
	fscanf(fptr,"%c %d %d %d %d",&ch, &i, &m, &n, &r);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			fscanf(fptr,"%d",&a[i][j]);
		}
	}
	for(i=z;i<n+z;i++)    //copying original array values
	{
		for(j=z;j<m+z;j++)
		{
			b[i][j]=a[i-z][j-z];
		}
	}
	for(i=z;i<n+z;i++)    //vertical padding on right and left columns
	{
		for(j=0;j<z;j++)
		{
			b[i][j]=b[i][z];
			b[i][m+z-1+j]=b[i][m+z-1];
		}
	}
	for(j=0;j<m+(2*z);j++)    //horizontal padding on top and bottom rows
	{
		for(i=0;i<z;i++)
		{
			b[i][j]=b[z][j];
			b[n+z-1+i][j]=b[n+z-1][j];
		}
	}
	
	fptr=fopen("../Boundary Omission-trial/eye27_mean-13.pgm","w");
	fprintf(fptr,"P2\n%d %d %d\n",m,n,r);
	for(i=z;i<n+z;i++)
	{
		for(j=z;j<m+z;j++)
		{
			s=0;avg=0.0;
			for(p=-(z);p<=z;p++)
			{
				for(q=-(z);q<=z;q++)
				{
					s+=b[i+p][j+q];
				}
			}
			avg=round((float)s/(size*size));
			fprintf(fptr,"%d ",(int)avg);
			b[i][j]=(int)avg;
		}	
	}
	fclose(fptr);
}
