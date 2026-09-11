#include <stdio.h>
void fillMatrix(int rows,int cols,int matrix[rows][cols]){
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			matrix[i][j]=i*cols+j+1;
		}
	}
}
void printMatrix(int rows, int cols, int matrix[rows][cols], const char* str){
	printf("%s\n",str);
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			printf("%4d", matrix[i][j]);
		}
		printf("\n");
	}
}
int sumMatrix(int rows, int cols, int matrix[rows][cols]){
	int sum=0;
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			sum+=matrix[i][j];
		}
	}
	return sum;
}
int findMax(int rows, int cols, int matrix[rows][cols],int* outRow,int* outCol){
	int maxElement=matrix[0][0];
	*outRow=0;
	*outCol=0;
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			if(matrix[i][j]>maxElement){
				maxElement=matrix[i][j];
				*outRow=i;
				*outCol=j;
			}	
		}
	}
	return maxElement;
}
void transpose(int rows, int cols, int src[rows][cols], int dst[cols][rows]){
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			dst[j][i]=src[i][j];
		}
	}
}
void rowSums(int rows, int cols, int matrix[rows][cols], int rowSums[rows]){
	for(int i=0; i<rows; i++){
		rowSums[i]=0;
		for(int j=0; j<cols; j++){
			rowSums[i]+=matrix[i][j];
		}
	}
}
void colSums(int rows, int cols, int matrix[rows][cols], int colSums[cols]){
	for (int j=0; j<cols; j++){
		colSums[j]=0;
		for(int i=0; i<rows; i++){
			colSums[j]+=matrix[i][j];
		}
	}
}
void printRowSums(int rows, int* rowSums){
	printf("Массив сумм в каждой строке матрицы:\n");
	int i=0;
	while(i<rows){
		printf("%2d",rowSums[i++]);
	}
	printf("\n");

}
void printColSums(int cols, int* colSums){
	printf("Массив сумм в каждом столбце матрицы:\n");
	int i=0;
	while(i<cols){
		printf("%2d",colSums[i++]);
	}
	printf("\n");
}
void multiply(int m, int n, int p, int A[m][n], int B[n][p], int C[m][p]){
	for(int i=0; i<m; i++){
		for(int j=0; j<p; j++){
			C[i][j]=0;
			for(int k=0; k<n; k++){
				C[i][j]+=A[i][k]*B[k][j];
			}
		}
	}
}
int main(void)
{
	int rows=4;
	int cols=4;
	int A[rows][cols];
	int B[rows][cols];
	int C[rows][cols];
	fillMatrix(rows,cols,A);
	fillMatrix(rows,cols,B);
	fillMatrix(rows,cols,C);
	return 0;
}
