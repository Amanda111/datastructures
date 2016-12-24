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


//HeapSort
void AdjustHeap(ElemType A[], int n,int k){
	int i,j,flag;
	ElemType temp;
	i = k;
	j = 2*i+1;
	temp=A[i];
	flag = 0;
	while(j<n&&flag!=1){
		if(j<n-1&&A[j]<A[j+1])j++;
		if(temp>=A[j]){
			flag = 1;
		}else{
			A[i] = A[j];
			i = j;
			j=2*i+1;
		}
	}
	A[i] = temp;
}
void CreatInitHeap(ElemType A[],int n){
	for(int i = (n-2)/2;i>=0;i--){
		AdjustHeap(A,n,i);
	}
}

void HeapSort(ElemType A[],int n){
	int i;
	ElemType temp;
	CreatInitHeap(A,n);
	for(i=n-1;i>0;i--){
		temp = A[0];
		A[0] = A[i];
		A[i] = temp;
		AdjustHeap(A,i,0);
	}
}

//QuickSort
void QuickSort(ElemType A[], int low,int high){
	int i,j;
	ElemType temp;
	i = low;
	j = high;
	temp = A[low];
	while(i<j){
		while(i<j&&A[j]>=temp)j--;
		if(i<j){
			A[i] = A[j];
			i++;
		}
		while(i<j&&A[i]<temp)i++;
		if(i<j){
			A[j] = A[i];
			j--;
		}
	}
	A[i] = temp;
	if(low < i-1) QuickSort(A,low,i-1);
	if(j+1<high) QuickSort(A,j+1,high);
}

//MergeSort
void TwoMerge(ElemType A[],ElemType Swap[],int low,int m,int high){
	int i,j,k;
	i = low;
	j = m+1;
	k = low;
	while(i<=m&&j<=high){
		if(A[i]<=A[j]){
			Swap[k++] = A[i++];
		}else{
			Swap[k++] = A[j++];
		}
		while(i<=m){
			Swap[k++] = A[i++];
		}
		while(j<=high){
			Swap[k++] = A[j++];
		}
	}
}

void MergePass(ElemType A[],ElemType Swap[],int n,int len){
	int p = 0;
	while(p+2*len-1<=n-1){
		TwoMerge(A,Swap,p,p+len-1,p+2*len-1);
		p+=2*len;
	}
	if(p+len-1<n-1){
		TwoMerge(A,Swap,p,p+len-1,n-1);
	}else{
		for(int i = p;i<=n-1;i++){
			Swap[i] = A[i];
		}
	}
}

void MergeSort(ElemType A[],int n){
	int len = 1;
	ElemType * Swap;
	Swap = (ElemType *)malloc(sizeof(ElemType)*n);
	while(len<n){
		MergePass(A,Swap,n,len);
		len = 2*len;
		MergePass(Swap,A,n,len);
		len = 2*len;
	}
	free(Swap);
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
    //QuickSort
    /*QuickSort(a,0,N-1);*/
	BubbleSort(a, N);
	long endTime =clock();
	long time = endTime - beginTime;
	cout<<time<<endl;
    cin>>i;
 }