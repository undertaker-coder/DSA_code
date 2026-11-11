//                       二分查找排序及其基本操作代码
//************************ Edited by 486desu *********************//
#include<iostream>
using namespace std;

int binarySearch(int *a,int len,int num){//二分查找
    int high=len-1;//注意数组下标为长队减一
    int low=0;
    int mid;
    while(low<=high){
        //mid的计算要放到循环里面
        mid = low + (high - low) / 2;//防止溢出
        if(a[mid]>num){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}
void binarySort(int *a,int len){
    for(int i=1;i<len;i++){
        int tmp=a[i];
        int k= binarySearch(a,i,a[i]);//二分查找插入位置

        for(int j=i-1;j>=k;j--){
            a[j+1]=a[j];
        }//挪出空间存放新值

        a[k]=tmp;//插入新值
    }
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
    binarySort(a,len);
    printList(a,len);
    return 0;
}