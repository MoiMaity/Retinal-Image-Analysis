#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mid, max, min,row,col,max_val;
int image[1000][1000],mod_image[1000][1000];

int main() {
    int m, x, y, k, l,i;
    char ch;
    FILE* input_file = fopen("noise_70.pgm", "r");
    FILE* output_file = fopen("01_noise_70_op.pgm", "w");
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
            	for(m = 1; m <= 19; m++) {
                	int r = (2*m) + 1;
                	int c = (2*m) + 1;
                	int arr[r][c];
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
                	int temp = 0, b[r*c];
                	for(int i = 0; i < r; i++) { 
                    	for(int j = 0; j < c; j++) 
                        	b[temp++] = arr[i][j]; 
                	} 
                	for (int f = 0; f < (r*c) - 1; f++) {
                    	for (int g = f+1; g < (r*c); g++) {
                        	if (b[g] < b[f]) {
                            	temp = b[f];
                            	b[f] = b[g];
                           	 	b[g] = temp;
                        	}
                 	   	}
                	}
                	max = b[(r*c) - 1];
                	min = b[0];
                	mid = b[(r*c)/2];
                
                	if (max > mid && mid > min) {
                    	mod_image[i][j] = mid;
                    	break;
                	}
                	
            	}
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
        }
    }
    fclose(output_file);
    return 0;
}

