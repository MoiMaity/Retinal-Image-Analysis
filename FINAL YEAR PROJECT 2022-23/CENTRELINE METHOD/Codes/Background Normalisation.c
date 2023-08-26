//Background normalisation
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int a[2000][2000];
int b[2000][2000];
int n,m,r,i,j,p,q,s;
float avg;
void main()
{
	FILE *fptr1,*fptr2,*fptr3;
	char ch;
	int x,y;
	fptr1=fopen("../Boundary Omission-trial/eye27_green.pgm","r");
	fscanf(fptr1,"%c %d %d %d %d",&ch, &i, &m, &n, &r);
	fptr2=fopen("../Boundary Omission-trial/eye27_mean-13.pgm","r");
	fscanf(fptr2,"%c %d %d %d %d",&ch, &i, &m, &n, &r);
	fptr3=fopen("../Boundary Omission-trial/eye27_bg normalisation.pgm","w");
	fprintf(fptr3,"P2\n%d %d %d\n",m,n,r);
	for(i=1;i<n+1;i++)
	{
		for(j=1;j<m+1;j++)
		{
			fscanf(fptr1,"%d",&x);
			fscanf(fptr2,"%d",&y);
			if((y-x)<0)
				fprintf(fptr3,"%d ",0);
			else
				fprintf(fptr3,"%d ",(y-x));
		}	
	}
	fclose(fptr1);
	fclose(fptr2);
	fclose(fptr3);
}
