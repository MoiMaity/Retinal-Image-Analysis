#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void main()
{
	int a[256][256],b[256][256],k,i,j,x,t;
	double c=105.89;
	double m;
	FILE *fp,*fq;
	fp=fopen("original_mandrill_input.txt","r");
	fq=fopen("original_mandrill_output.txt","w+");
	for(i=0;i<256;i++){
		for(j=0;j<256;j++){
			fscanf(fp,"%d",&k);
			a[i][j]=k;
		}
	}
	for(i=0;i<256;i++){
		for(j=0;j<256;j++){
			m=c*log(a[i][j]+1);
			/*if(m>255)
				b[i][j]=m-255;
			else
				b[i][j]=m;*/
			t=m/255;
			for(x=0;x<t;x++)
				m=m-255;
			b[i][j]=m;
		}
	}
	for(i=0;i<256;i++){
		for(j=0;j<256;j++){
			fprintf(fq,"%d ",b[i][j]);
		}
	}
	//fscanf(fp,"%d",&k);
	fclose(fp);
	fclose(fq);
}
