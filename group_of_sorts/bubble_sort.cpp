//                        冒泡排序及其基本操作代码
//************************ Edited by 486desu *********************//
#include<iostream>
using namespace std;

void bubbleSort(int *a,int len){
    for(int i=0;i<len;i++){
        for(int j=0;j<len-i-1;j++){//注意遍历下标
            if(a[j]>a[j+1]){
                int swap=a[j];
                a[j]=a[j+1];
                a[j+1]=swap;
            }
        }
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
    bubbleSort(a,len);
    printList(a,len);
    return 0;
}