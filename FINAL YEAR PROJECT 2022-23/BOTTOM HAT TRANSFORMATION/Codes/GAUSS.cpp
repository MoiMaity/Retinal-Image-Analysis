#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define KERNEL_SIZE 3
#define PI 3.14159
int height, width, max_val;
double input[1000][1000];
double kernel[KERNEL_SIZE][KERNEL_SIZE];
int output[1000][1000];


void generate_gaussian_kernel(double kernel[KERNEL_SIZE][KERNEL_SIZE], double sigma) {
    double r, s = 2.0 * sigma * sigma;
    int mid = KERNEL_SIZE/2;
    double sum = 0.0;

    for(int x = -mid; x <= mid; x++) {
        for(int y = -mid; y <= mid; y++) {
            r = sqrt(x*x + y*y);
            kernel[x+mid][y+mid] = exp(-(r*r)/s) / (PI * s);
            sum += kernel[x+mid][y+mid];
        }
    }
    //normalize_kernel(kernel);
    for(int i = 0; i < KERNEL_SIZE; i++) {
        for(int j = 0; j < KERNEL_SIZE; j++) {
            kernel[i][j] /= sum;
        }
    }
    for (int i = 0; i < KERNEL_SIZE; i++) {
        for (int j = 0; j < KERNEL_SIZE; j++) {
            printf("%lf ",kernel[i][j]);
        }
        printf("\n");
    }
}

void convolve(double input[1000][1000], int output[1000][1000], double kernel[KERNEL_SIZE][KERNEL_SIZE],int height,int width) {
    int mid = KERNEL_SIZE/2;

    for(int i = mid; i < height-mid; i++) {
        for(int j = mid; j < width-mid; j++) {
            double sum = 0;
            for(int x = -mid; x <= mid; x++) {
                for(int y = -mid; y <= mid; y++) {
                    sum += kernel[x+mid][y+mid] * input[i+x][j+y];
                }
            }
            output[i][j] = (int)sum;
        }
    }
}

int main() {
	int i;
	char ch;
    FILE* fp = fopen("01_test.pgm", "r");
    fscanf(fp,"%c %d %d %d %d",&ch,&i,&width,&height,&max_val);
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            fscanf(fp, "%lf", &input[i][j]);
        }
    }
    fclose(fp);
	double sum = 0;
    for(int i = 0; i < height; i++) {
    	for(int j = 0; j < width; j++)
    	{
        	sum += input[i][j];
    	}
	}
    double mean = sum / (height*width);

    // Calculate standard deviation
    double sigma = 0.0;
    for(int i = 0; i < height; i++) {
    	for(int j =0; j < width; j++)
    	{
    		sigma += pow(input[i][j] - mean, 2);
		}
    }
    sigma = sqrt(sigma / (height*width));

    // Print result
    printf("Standard deviation: %.2lf\n", sigma);


    generate_gaussian_kernel(kernel, sigma);

    convolve(input, output, kernel,height,width);

    fp = fopen("gauss op01.pgm", "w");
    fprintf(fp,"P2 %d %d %d\n",width,height,max_val);
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            fprintf(fp, "%d ", output[i][j]);
        }
    }
    fclose(fp);
    return 0;
}

