#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# define size 5
int mid,row,col,max_val;
int image[1000][1000],mod_image[1000][1000];

int main() {
    int m, x, y, k, l, i;
    char ch;
    FILE* input_file = fopen("noise_70.pgm", "r");
    FILE* output_file = fopen("01_DBUTM_noise70.pgm", "w");
    fscanf(input_file,"%c %d %d %d %d",&ch,&i,&col,&row,&max_val);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            fscanf(input_file, "%d", &image[i][j]);
        }
    }
    fclose(input_file);
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
        	if(image[i][j]==255 || image[i][j]==0){
        			m = size / 2;
        			int arr[2*m+1][2*m+1];
                	for(x = -m; x <= m; x++) {
                    	for(y = -m; y <= m; y++) {
                        	k = i + x;
                        	l = j + y;
                        	if (k <= 0) k = 0;
                        	if (l <= 0) l = 0;
                        	if(k > row) k = row - 1;
                        	if(l > col) l = col - 1;
                        	arr[x + m][y + m] = image[k][l];
                    	}
                	}
                	int temp = 0, b[size*size];
                	for(int i = 0; i < (2*m+1); i++) { 
                    	for(int j = 0; j < (2*m+1); j++){
							if(arr[i][j] < 255 && arr[i][j] > 0)
                        		b[temp++] = arr[i][j]; 
                    	}
                	} 
                	for (int f = 0; f < temp - 1; f++) {
                    	for (int g = f+1; g < temp; g++) {
                        	if (b[g] < b[f]) {
                            	int temp1 = b[f];
                            	b[f] = b[g];
                           	 	b[g] = temp1;
                        	}
                 	   	}
                	}
                	if (temp%2!=0){
                		mid = b[temp/2];
                	}
                	else if(temp%2==0){
                		mid = b[(temp/2)+1];
                	}
                	mod_image[i][j] = mid;
            }
        	else{
        		mod_image[i][j]=image[i][j];
        	}
        }
    }
    fprintf(output_file,"P2 %d %d %d\n",col,row,max_val);
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            fprintf(output_file,"%d ", mod_image[i][j]);
            //printf("%d ",image[i][j]);
        }
    }
    fclose(output_file);
    return 0;
}

