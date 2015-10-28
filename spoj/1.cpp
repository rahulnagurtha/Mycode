#include <stdio.h>

int binsearch(int a[],int left,int right,int item);

int main(){
	int a[100],left =0,right,n,item,d,i;
	printf("Enter the num of elements in the array: \n");
	scanf("%d",&n);
	printf("Enter the elements as a sorted array: \n");
	for(i=0;i<n;i++){
	    scanf("%d",&a[i]);
	}
	right = n-1;
	printf("Enter the element which you want to search: \n");
	scanf("%d",&item);
	d = binsearch(a,left,right,item);
	if(d == 1) {
	    printf("Element has found");
	}
	else {
    	printf("Element does not exist");
	}
}

int binsearch(int a[],int left,int right,int item){
	printf("%d-%d\n",left,right);
	int mid;
	mid = left +(right - left)/2;
	if(left<=right) {
		if(a[mid] == item){
	    	return 1;
		}	
		else if(item < a[mid]){
			return binsearch(a,left,mid-1,item);
		}
		else if(item > a[mid]){
			return binsearch(a,mid+1,right,item);
		}
	}	
	else{
		return 0;
	}
}
