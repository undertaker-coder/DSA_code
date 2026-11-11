//                        希尔排序及其基本操作代码
//************************ Edited by 486desu *********************//
#include<iostream>
using namespace std;

void shellSort(int *a,int len){
	int step =len/2;//初始步长
	while(step>=1){
		for(int j=0;j<step;j++){//遍历所有step
			int i=j;//开始插入排序，i为插入排序起始下标
			i+=step;//第一个不用排序（即为插入排序初始长度）
			while(i<len){//不取等，防越界
                //对从i开始的每个元素进行插入排序，步长为step
                //即对每个子序列进行插入排序
				int k=i-step;//k为当前元素的前一个元素下标
				int tmp=a[i];//存放待插入元素
				while(k>=j){
					if(tmp<a[k]){
						a[k+step]=a[k];//后移
                        k-=step;
					}
					else{
						break;
					}
					
				}
				a[k+step]=tmp;//插入元素
				i+=step;//继续对下一个元素进行插入排序
			}
		}
		step/=2;//步长减半
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
    shellSort(a,len);
    printList(a,len);
    return 0;
}
