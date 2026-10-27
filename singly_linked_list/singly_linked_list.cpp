//                        单链表及其基本操作代码
//************************ Edited by 486desu *********************//
#include<iostream>
#define MAXMIZE 100
using namespace std;
typedef int elmtype;
//节点定义
typedef struct node1{
	elmtype data;
	struct node1 *next;
}node;
//函数声明
node* initList();//初始化并创建头节点
bool headInsert(node* l,elmtype elm);//头插法
bool tailInsert(node* l,elmtype elm);//尾插法
int traverseList(node * l);//遍历链表
bool posInsert(node *l,int pos,elmtype elm);//按位置插入
bool posDelete(node *l,int pos);//按位置删除
int getLength(node * l);//获取链表长度
bool freeList(node *l);//释放链表
//主函数
int main()
{
    //检查操作结果
	node *list=initList();
	tailInsert(list,11);
	posInsert(list,1,12);
	traverseList(list);
	posDelete(list,2);
	traverseList(list);
	cout<<getLength(list)<<endl;
	freeList(list);
	traverseList(list);
	//释放头指针
	delete list;
	list=NULL;
	return 0;
}


node* initList(){
	node *head=new node;
	head->data=0;
	head->next=NULL;
	return head;
}

bool headInsert(node* l,elmtype elm){
	node * add=new node;
	add->data=elm;
	add->next=l->next;
	l->next=add;
	return true;
}

bool tailInsert(node* l,elmtype elm){
	node *p=l;
	while(p->next!=NULL){
		p=p->next;
	}
	node *add=new node;
	add->data=elm;
	add->next=NULL;
	p->next=add;
	return true; 
}

int traverseList(node * l){
	node *p=l;
	int i=0;
	while(p!=NULL){
		cout<<p->data<<" "; 
		p=p->next;
		i++;
	}
	cout<<endl;
	return i;
}
//注意按位置插入和删除要检查位置是否合法
bool posInsert(node *l,int pos,elmtype elm){
	if(pos<1){//检查位置是否合法
		cout<<"Overflow action"<<endl;
			return false;
	}
	node *p=l;
	for(int i=0;i<pos-1;i++){
		if(p==NULL){
			cout<<"Overflow action"<<endl;
			return false;
		}
		p=p->next;
	}//找到前驱节点
	if(p==NULL){//检查前驱节点是否存在，防止空指针解引用
		cout<<"Overflow action"<<endl;
			return false;
	}
	node *add=new node;
	add->data=elm;
	add->next=p->next;
	p->next=add;//插入位置可以为空指针,不影响在该位置插入
	return true; 
}

bool posDelete(node *l,int pos){
	if(pos<1){
		cout<<"Overflow action"<<endl;
		return false;
	}
	node *p=l;
	for(int i=0;i<pos-1;i++){
		if(p==NULL){
			cout<<"Overflow action"<<endl;
			return false;
		}
		p=p->next;
	}//找到前驱节点
	if(p==NULL||p->next==NULL){//前驱节点不存在或者要删除的节点不存在
	    cout<<"Overflow action"<<endl;
		return false;
	}
	node *q=p->next;
	p->next=q->next;
	delete q;
	return true;
}

int getLength(node * l){
	node *p=l;
	int i=0;
	while(p!=NULL){
		p=p->next;
		i++;
	}
	return i;
}
//改良版
bool freeList(node *l){
	node* p=l->next;
	node *q=NULL;
	while(p!=NULL){
		q=p->next ;
		delete p;
		p=q;
	} 
	l->next=NULL;
	return true;
}
//原版代码思路过于冗长，应该直接从头节点的下一个节点开始遍历，释放每个节点，最后将头节点的next指针置为NULL即可。下面是原版代码的注释掉版本：
/*bool freeList(node *l){
	node *p=l;
	node *q=NULL;
    bool ifhappen=false;
	while(p->next!=NULL){
		if(ifhappen==false){
			if(p->next==NULL){
				return true;
			}
			else{
				p=p->next;
			}
			ifhappen=true;
		}
		else{
			q=p->next;
			delete p;
			p=q;
		}
	}
	delete p;
	l->next=NULL;
	p=NULL;
	q=NULL;
	return true;
}*/




















