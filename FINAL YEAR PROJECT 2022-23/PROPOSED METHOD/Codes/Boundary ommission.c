//subtraction
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int a[2000][2000];
int b[2000][2000];
int n,m,r,i,j,p,q,s;
float avg;
void main()
{
	FILE *fptr1,*fptr2,*fptr3,*fptr4;
	char ch;
	int x,y,z,p,val;
	fptr1=fopen("../Boundary Omission-trial/Retinal Area-19.pgm","r");
	fscanf(fptr1,"%c %d %d %d %d",&ch, &i, &m, &n, &r);
	fptr2=fopen("../Boundary Omission-trial/Centerline.pgm","r");
	fscanf(fptr2,"%c %d %d %d %d",&ch, &i, &m, &n, &r);
	fptr3=fopen("../Boundary Omission-trial/Final boundary.pgm","r");
	fscanf(fptr3,"%c %d %d %d %d",&ch, &i, &m, &n, &r);
	fptr4=fopen("../Boundary Omission-trial/Boundary omitted-19.pgm","w");
	fprintf(fptr4,"P2\n%d %d %d\n",m,n,r);
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			fscanf(fptr1,"%d",&x);
			fscanf(fptr2,"%d",&y);
			fscanf(fptr3,"%d",&z);
			if(x==255 && y==255)
				val=255;
			else
				val=0;
			
			if((val-z)<0)
				fprintf(fptr4,"%d ",0);
			else
				fprintf(fptr4,"%d ",(val-z));
			
		}	
	}
	fclose(fptr1);
	fclose(fptr2);
	fclose(fptr3);
	fclose(fptr4);
}
