//                        插入排序及其基本操作代码
//************************ Edited by 486desu *********************//
#include<iostream>
using namespace std;
void insertSort(int *a,int len){
    for(int i=1;i<len;i++){
        for(int j=i;j>0;j--){
           if(a[j-1]>a[j]){
                int swap=a[j-1];
                a[j-1]=a[j];
                a[j]=swap;//从后向前层层交换
           }
           else{
                break;//节约时间
           }
        }
    }
    return;
}
//优化版插入排序
void insertSort2(int *a, int len) {
    for (int i = 1; i < len; i++) {
        int key = a[i];
        int j = i - 1;//前一位开始比较
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];//后移
            --j;
        }
        a[j + 1] = key;//注意是j+1
    }
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
    insertSort(a,len);
    printList(a,len);
    return 0;
}