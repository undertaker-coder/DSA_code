//                        二叉树的基本操作及其代码
//************************ Edited by 486desu *********************//
#include<iostream>
#define MAX 100
using namespace std;
typedef char elmtype;

typedef struct node{
    elmtype data;
    struct node * lch;
    struct node * rch;
}node;

typedef node * bitree;


void deleteTree(bitree &t);//销毁二叉树
void frontCreateTree(bitree &t,const char *a,int &idx);//前序建树
void frontReserve(bitree t);//前序遍历
void middleReserve(bitree t);//	中序遍历
void afterReserve(bitree t);//后序遍历


int main(){
	//操作检验
	bitree t=NULL;
	char a[]="ABD##E##C##";
	int idx=0;
	frontCreateTree(t,a,idx);
	cout << "PreOrder:  "; frontReserve(t);  cout << endl;
    cout << "InOrder:   "; middleReserve(t); cout << endl;
    cout << "PostOrder: "; afterReserve(t);  cout << endl;
	deleteTree(t);
	
	return 0;
}

void deleteTree(bitree &t){
	if(t==NULL){
		return;
	}
	deleteTree(t->lch);
	deleteTree(t->rch);
	delete t;//先访问孩子再删除自身
	t=NULL;
}

void frontCreateTree(bitree &t,const char *a,int &idx){
	//注意：此处传入t本身，而非备份（因为需要修改外部指针）；
	// 这里的idx是引用传递，目的是让递归函数能修改外部的idx值
	if(a[idx]=='\0'){
		t=NULL;//置空指针
		return;
	}
    if(a[idx]=='#'){
    	t=NULL;
    	idx++;
	}
	else{
		t=new node;
		t->data=a[idx];
		t->lch=NULL;
		t->rch=NULL;
		idx++;
		frontCreateTree(t->lch,a,idx);
		frontCreateTree(t->rch,a,idx);
	}
}

void frontReserve(bitree t){
	if(t==NULL){
		return;
	}
	cout<<t->data<<" ";
	frontReserve(t->lch);
	frontReserve(t->rch);
}

void middleReserve(bitree t){
	if(t==NULL){
		return;
	}
	
	middleReserve(t->lch);
	cout<<t->data<<" ";
	middleReserve(t->rch);
}

void afterReserve(bitree t){
	if(t==NULL){
		return;
	}
	
	afterReserve(t->lch);
	afterReserve(t->rch);
	cout<<t->data<<" ";
}


/* 总结（by DSH）
   & 是"允许改外面"的通行证。
  建树、删树需要改外部指针 → 给通行证；(需要手动修改函数外的指针，所以要传引用，只读操作则不传)
  遍历只读 → 不给通行证，既不需要，也顺便防手滑。
  这也正是 C++ 里"能不加 & 就不加，能加 const 就加 const"这条习惯的体现：
  参数修饰得越严格，函数能造成的副作用就越小，越不容易出 bug。

*/