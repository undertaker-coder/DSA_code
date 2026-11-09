//                        选择排序及其基本操作代码
//************************ Edited by 486desu *********************//
#include<iostream>
using namespace std;

void chooseSort(int *a,int len){
    for(int i=0;i<len;i++){
        int min=i;
        for(int j=i;j<len;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }//查找最小值下标
        int swap=a[i];
        a[i]=a[min];
        a[min]=swap;//置换
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
    chooseSort(a,len);
    printList(a,len);
    return 0;
}