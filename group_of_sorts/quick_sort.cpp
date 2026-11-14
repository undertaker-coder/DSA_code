#include<iostream>
using namespace std;
void swap(int &a,int &b){
	int tmp=a;
	a=b;
	b=tmp;
	return;
}

int partition(int *a,int low,int high){
	int pivot=a[low];
    while(low<high){
    	while(a[high]>=pivot&&low<high){
    		high--;
		}
		a[low]=a[high];
		while(a[low]<=pivot&&low<high){
    		low++;
		}
		a[high]=a[low];
	}
	a[low]=pivot;
	return low;
}

void quickSort(int *a,int begin,int end){
	if(begin>=end){
		return;
	}
	int pivot=partition(a,begin,end);
	quickSort(a,begin,pivot-1);
	quickSort(a,pivot+1,end);
	return;
} 

void printList(int *a,int len){
    for(int i=0;i<len;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return;
}

int main(){
    int len;
    cin>>len;
    int a[len]={0};
    for(int i=0;i<len;i++){
        cin>>a[i];
    }
    quickSort(a,0,len-1);
    printList(a,len);
    return 0;
}
