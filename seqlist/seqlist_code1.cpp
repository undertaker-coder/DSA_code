#include<iostream>
#define MAXSIZE 100
using namespace std;
typedef int ElemType ;
//顺序表结构体
typedef struct {
    int *data;
    int length;
}Sqlist;
//初始化顺序表
Sqlist *initList(){
	Sqlist *L=new Sqlist ;
	L->data=new int[MAXSIZE];
	L->length=0;
	return L;
}
//最后位添加元素
bool addList(Sqlist *L,int elm){
	if(L->length>=MAXSIZE){
		cout<<"Positions Overflow "<<endl;
		return false;
	}
	L->data[L->length]=elm;
	L->length++;
	return true;
}
//插入元素
bool insertList(Sqlist *L,int position,int elm){
	if(L->length>=MAXSIZE){
		cout<<"Positions Overflow "<<endl;
		return false;
	}
	if(position<1||position>L->length+1){
		cout<<"Error insert position"<<endl;
		return false;
	}
	for(int i=L->length;i>=position;i--){
		L->data[i]=L->data[i-1];
	}
	L->data[position-1]=elm;
	L->length++;
	return true;
} 
//删除元素
bool deleteList(Sqlist *l,int position){
    if(l->length<1){
    	cout<<"empty list"<<endl;
    	return false;
	}
	if(position>l->length||position<1){
		cout<<"Overflow action"<<endl;
		return false;
	}
	for(int i=position;i<l->length;i++){
		l->data[i-1]=l->data[i];
	}
	l->length--;
	return true;
}
//改变元素
bool changeList(Sqlist *l,int position,int elm){
	if(position>l->length||position<1){
		cout<<"Overflow action"<<endl;
		return false;
	}
	l->data[position-1]=elm;
	return true;
}
//查找元素
int findList(Sqlist *l,int elm){
	if(l->length<1){
		cout<<"empty list"<<endl;
		return 0;
	}
	for(int i=0;i<l->length;i++){
		if(l->data[i]==elm){
			cout<<"find "<<elm<<" in position "<<i+1<<endl;
			return i+1;
		}
	}
	cout<<"Not find"<<endl;
	return 0;
}
//遍历输出列表
bool coutList(Sqlist *l){
	if(l->length<1){
		cout<<"empty list"<<endl;
		return false;
		
	}
	for(int i=0;i<l->length;i++){
		cout<<l->data[i]<<" ";
	}
	cout<<endl;
	return true;
}
//主函数
int main(){
	Sqlist *list1=initList();
	insertList(list1,1,12);
	insertList(list1,2,13);
	insertList(list1,3,14);
	findList(list1,13);
	coutList(list1);
	
	//删除释放空间
	delete[] list1->data;
    delete list1;
    list1 = nullptr;
	return 0;
}















