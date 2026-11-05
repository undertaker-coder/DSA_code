//                        哈夫曼树的基本操作及其代码
//************************ Edited by 486desu *********************//

#include<iostream>
using namespace std;
#define MAX 100//最大结点数
typedef struct node{
	int weight;//权值
	int parent,lch,rch;//父结点，左孩子，右孩子
}node;

typedef node  Hufftree[MAX];//哈夫曼树的类型定义

void selectMin(Hufftree ht,int n,int &s1,int &s2);//选择最小的两个结点
void createHufftree(Hufftree ht,int *weights,int n);//创建哈夫曼树
void printHufftree(Hufftree ht,int n);//打印哈夫曼树

int main(){
    //测试
	int weights[]={5,15,40,30,10};
	int n=sizeof(weights)/sizeof(weights[0]);
	Hufftree ht;
	createHufftree(ht,weights,n);
	printHufftree(ht,n);

	return 0;
}


void selectMin(Hufftree ht,int n,int &s1,int &s2) {
	s1=s2=-1;
	for(int i=0;i<n;i++){
		if(ht[i].parent==-1){//未被选过，无父节点
			if(s1==-1||ht[i].weight<ht[s1].weight){
				s2=s1;
				s1=i;//挪动值，保证s1<=s2；
            
			}else if(s2==-1||ht[i].weight<ht[s2].weight){
				s2=i;//保证s1<=s2；
			}
		}
	}
	return;
}

void createHufftree(Hufftree ht,int *weights,int n){
	int i;
	int m=2*n-1;//总结点数（加上生成节点和叶节点）
	for(i=0;i<m;i++){
		ht[i].weight=weights[i];
		ht[i].parent=-1;
		ht[i].lch=-1;
		ht[i].rch=-1;
	}//初始化
	
	for(i=n;i<m;i++){
		int s1,s2;
        //选择最小的两个结点，生成局部哈夫曼树
		selectMin(ht,i,s1,s2);
		ht[s1].parent=i;
		ht[s2].parent=i;
		ht[i].weight=ht[s1].weight+ht[s2].weight;
		ht[i].lch=s1;
		ht[i].rch=s2;
	}//创建哈夫曼树
	return ;
}

void printHufftree(Hufftree ht,int n){
    int m=2*n-1;
    cout<<"weight"<<"\t"<<"parent"<<"\t"<<"lch"<<"\t"<<"rch"<<endl;
	for(int i=0;i<m;i++){
		cout<<ht[i].weight<<"\t"<<ht[i].parent<<"\t"<<ht[i].lch<<"\t"<<ht[i].rch<<endl;
	} 
	return;
}













