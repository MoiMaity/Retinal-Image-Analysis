#include<stdio.h>
#include<stdlib.h>
int a[512][512], b[512][512];
int k;
main()
{
	FILE *fp;
	FILE *fq;
//	int a[225][225];
	int i,j;
	fp=fopen("input.txt","r");
	fq=fopen("output.txt","w+");
	for(i=0;i<512;i++)
	{
		for(j=0;j<512;j++)
		{
			fscanf(fp,"%d",&k);
			a[i][j]=k;
		}
	}
	for(i=0;i<512;i++)
	{
		for(j=0;j<512;j++)
			b[i][j]=255-a[i][j];
	}
	for(i=0;i<512;i++)
	{
		for(j=0;j<512;j++)
		{
			fprintf(fq,"%d ",b[i][j]);
		}
	}
	fclose(fp);
	fclose(fq);
}
	
