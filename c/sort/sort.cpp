# include "stdio.h"
# include "stdlib.h"              // 该文件包含malloc()、realloc()和free()等函数
# include "iostream.h"            // 该文件包含标准输入输出流cout和cin
# include "time.h"
typedef int ElemType;
# define N 1000

void InsertSort(ElemType A[], int n){
	int i,j;
	ElemType temp;
	for(i = 1;i<n;i++){
		temp = A[i];
		j = i - 1;
		while(j>-1&&temp<A[j]){
			A[j+1] = A[j];
			j--;
		}
		A[j+1]  = temp;
	}
}


void ShellSort(ElemType A[],int n,int d[],int num){
	int i,j,k,m,span;
	ElemType temp;
	for(m = 0;m<num;m++){
		span = d[m];
		for(k = 0;k<span;k++){
			for(i=k+span;i<n;i+=span){
				temp = A[i];
				j = i-span;
				while(j>-1&&temp<A[j]){
					A[j+span]= A[j];
					j-=span;
				}
				A[j+span] = temp;
			}
		}
	}
}

void main()
{
	int a[N];
	int num = 10;
	int arr[] = {5000,2500,1250,625,400,200,100,25,2,1};
	for(int i=0;i<N;i++){
		a[i] = rand();
	}
    long beginTime =clock();
	ShellSort(a,N,arr,num);
	long endTime =clock();
	long time = endTime - beginTime;
	cout<<time<<endl;
    cin>>i;
 }	



void SelectSort(ElemType A[], int n){
	int i,j,min;
	ElemType temp;
	for(i = 0;i<n;i++){
		min = i;
		for(j=i+1;j<n;j++){
			if(A[j]<A[min]) {
				min = j;
			}
		}
		if(min!=i){
			temp = A[i];
			A[i] = A[min];
			A[min] = temp;
		}
	}
}


void BubbleSort(ElemType A[], int n){
	int i,j,flag = 1;
	ElemType temp;
	for(i = 0;i<n&&flag==1;i++){
		flag = 0;
		for(j=0;j<n -i;j++){
			if(A[j]>A[j+1]) {
				flag = 1;
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
		}
	}
}

void main()
{
	int a[N];
	for(int i=0;i<N;i++){
		a[i] = rand();
	}
    long beginTime =clock();
    // ShellSort
	// int num = 10;
	// int arr[] = {5000,2500,1250,625,400,200,100,25,2,1};
    //Sort method
	BubbleSort(a, N);
	long endTime =clock();
	long time = endTime - beginTime;
	cout<<time<<endl;
    cin>>i;
 }