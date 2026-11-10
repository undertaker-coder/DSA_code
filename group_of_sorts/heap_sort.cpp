//                        堆排序及其基本操作代码
//************************ Edited by 486desu *********************//
#include<iostream>
using namespace std;

void swap(int *a,int m,int n){
	int tmp=a[m];
	a[m]=a[n];
	a[n]=tmp;
	return;
}

void fixHeap(int *a,int root,int final){//从当前节点开始向下维护堆
    //维护堆的目的是为了保证父节点大于孩子节点
	int tmp=a[root];//保存父节点的值
	int child=root*2;//从root的左孩子开始
	while(child<=final){//如果孩子存在
		if(child+1<=final&&a[child+1]>a[child]){
			child++; //右孩子存在且大于左孩子，则选择右孩子
		}
		if(a[child]<=tmp){
			break;//如果孩子小于等于父节点，则不需要交换
		}
		a[child/2]=a[child];
        child*=2;//继续维护孩子，确保tmp小于所有父节点
	}
	a[child/2]=tmp;//用tmp保存的父节点值替换最后一个孩子节点
    //把原根节点放到空出的位置（可能是原位置）
	return; 
	
}

void heapSort(int *a,int len){
	for(int i=len/2;i>0;i--){
		fixHeap(a,i,len);
	}//生成初始大根堆
	for(int i=len;i>1;i--){
		swap(a,i,1);//将堆顶元素（最大元素）与最后一个元素交换
		fixHeap(a,1,i-1);//维护新堆
	}

	return;
}

void printList(int *a,int len){
    for(int i=1;i<=len;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return;
}

int main(){
    int len;
    cin>>len;
    int a[len+1]={0};
    a[0]=-1;
    for(int i=1;i<=len;i++){
        cin>>a[i];
    }
    heapSort(a,len);
    printList(a,len);
    return 0;
}
















