//                        归并排序及其基本操作代码
//************************ Edited by 486desu *********************//
#include<iostream>
using namespace std;

void merge(int *a,int low,int mid,int high){//并集操作
	int *tmp=new int[high-low+1];//临时数组，存放合并后的结果
	int tidx=0;//临时数组下标
	int lidx=low;//左边数组下标
	int ridx=mid+1;//右边数组下标
	while((lidx<=mid)&&(ridx<=high)){//当左右数组都没有遍历完时
		if(a[lidx]>a[ridx]){
			tmp[tidx]=a[ridx];
			ridx++;
			tidx++;//将右边数组的元素放入临时数组
		}
		else{
			tmp[tidx]=a[lidx];
			lidx++;
			tidx++;//将左边数组的元素放入临时数组
		}
	}
	while(lidx<=mid){//当左边数组没有遍历完时
		tmp[tidx]=a[lidx];
		lidx++;
		tidx++;
	}
	while(ridx<=high){//当右边数组没有遍历完时
		tmp[tidx]=a[ridx];
		ridx++;
		tidx++;
	}
    for(int i=0;i+low<high+1;i++){//将临时数组的元素放回原数组
    	a[i+low]=tmp[i];
	}
    delete []tmp;//释放临时数组的内存
    tmp=NULL;//防止野指针
	return;
}

void mergeSort(int *a,int low,int high){
	if(low>=high){
		return;
	}//递归终止条件
	int mid = (low+high)/2;//分治
	mergeSort(a,low,mid);//递归调用,左分治
	mergeSort(a,mid+1,high);//递归调用,右分治
	merge(a,low,mid,high);//合并操作
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
    mergeSort(a,0,len-1);
    printList(a,len);
    return 0;
}














