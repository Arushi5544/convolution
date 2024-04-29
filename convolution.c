
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void matrix_mul(int **arr, int n, int **filter, int filter_size, int **mul, int padding, int stride) {
    int l, k;
    for(int a = 0; a < ((n+2*padding-filter_size)/stride+1); a+=stride) {
        for(int b = 0; b < ((n+2*padding-filter_size)/stride+1); b+=stride) {
            k = 0;
            for(int i = a; i < a+filter_size; i++) { 
                l = 0;
                for(int j = b; j < b+filter_size; j++) {
                    mul[a][b] += arr[i][j] * filter[l][k]; 
                    l++;
                }
                k++;
            }
        }
    }
}
	
void print(int **mul, int r, int c) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            printf("%7d", mul[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int n, filter_size, padding, stride;
    n = (rand() % (10-5+1))+5;//dimension of inpaddingut matrix
    filter_size = (rand() % (4-3+1))+3;// dimension of filter/kernel
    padding = (rand() % (3-0+1))+0;// size of paddingadding
    stride = (rand() % (3-1+1))+1;
    printf("padding value=%d",padding);
    printf("strided value=%d",stride);
    int padded_size = n + 2 * padding;
    //dynamically allocating spaddingace
    int **arr = malloc(padded_size * sizeof(int *));
    int **filter = malloc(filter_size * sizeof(int *));
    int **mul = malloc((n + 2 * padding - filter_size + 1) * sizeof(int *));
    
    for(int i = 0; i < padded_size; i++) {
        arr[i] = malloc(padded_size * sizeof(int));
    }
    for(int i = 0; i < filter_size; i++) {
        filter[i] = malloc(filter_size * sizeof(int));
    }
    for(int i = 0; i < (n+2*padding-filter_size+1); i++) {
        mul[i] = malloc((n+2*padding-filter_size+1) * sizeof(int));
    }
	//assigning random values for inpaddingut matrix  along with paddingadding initialized to 0
    for(int i = 0; i < padded_size; i++) {
        for(int j = 0; j < padded_size; j++) {
            if(padding > 0) {
                if(i < padding || i >= padded_size - padding || j < padding || j >= padded_size - padding)
                    arr[i][j] = 0;
                else
                    arr[i][j] = (rand() % (10 - 1 + 1)) + 1;
            } else {
                arr[i][j] = (rand() % (10 - 1 + 1)) + 1;
            }
        }
    }

    printf("\nInpaddingut matrix 1\n\n");
    print(arr, padded_size, padded_size);
    // assigning random values to filter_size
    for(int i = 0; i < filter_size; i++) {
        for(int j = 0; j < filter_size; j++) {
            filter[i][j] = (rand() % (4 - (-4) + 1)) + (-4);
        }
    }

    printf("\nInpaddingut matrix 2\n\n");
    print(filter, filter_size, filter_size);
    //initializing resultant matrix with 0
    for(int i = 0; i < ((padded_size - filter_size)/stride + 1); i++) {
        for(int j = 0; j < ((padded_size - filter_size)/stride + 1); j++) {
            mul[i][j] = 0;
        }
    }
    //function to opaddingerate the convolution
    matrix_mul(arr, n, filter, filter_size, mul, padding,stride);

    printf("\nOutpaddingut matrix\n\n");
    print(mul, (n+2*padding-filter_size)/stride+1, (n+2*padding-filter_size)/stride+1);

   
    return 0;
}
