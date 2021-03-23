// Program that performs matrix sum and multiplication of matrices A and B.
// A(1000 * 10000) & B (1000 * 10000)
#include <stdio.h>
#define SIZE1 1000
#define SIZE2 10000

using namespace std;

//Function for matrix sum
int** matsum(int** first, int** second){
        int** res = new int*[SIZE1];
	for(int i = 0; i < SIZE1; i++){
		*(res + i) = new int[SIZE2];
        	for(int j = 0; j < SIZE2; j++){
                	*(*(res + i)+ j) = *(*(first + i)+ j) + *(*(second + j)+ i);
                }
        }
        return res;
}

//Function for matrix multiplication
int** matmul(int** first, int** second){
	int ** res = new int*[SIZE1];
	for(int i = 0; i < SIZE1; i++){
		*(res + i) = new int[SIZE1];
        	for(int j = 0; j < SIZE1; j++){
			*(*(res + i)+ j) = 0;
                	for(int k = 0; k < SIZE2; k++){
                        	*(*(res + i)+ j) = *(*(res + i)+ j) + *(*(first + i)+ k) * *(*(second + k)+ j);
                        }
                }
        }
	return res;
}

int main(){

	int** A = new int*[SIZE1];
	int** B = new int*[SIZE2];
	      
        //initialize matrices A & B to non-zero values
        for(int x = 0; x < SIZE2; x++){
		*(B + x) = new int[SIZE1];
		for(int y = 0; y < SIZE1; y++){
			if(!x)							
				*(A + y) = new int[SIZE2];
        		*(*(A + y)+ x) = x + y;
			*(*(B + x)+ y) = (y > x) ? y - x : x - y;        
	        } 
        }

	int** sum;
	int** mul;

	//Function call to appropriate matrix operation
	
	sum = matsum(A, B);
	mul = matmul(A, B);
	return 0; 

} 

