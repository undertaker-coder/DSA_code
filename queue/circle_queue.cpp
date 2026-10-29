//                        (环形)队列及其基本操作代码
//************************ Edited by 486desu *********************//
#include<iostream>
#define MAXSIZE 100
using namespace std;
typedef int elmtype;
typedef struct{
	elmtype *data;
	int head;
	int tail;
}queue;
queue *initQueue();//初始化队列
bool addQueue(queue *q,elmtype elm);//入队
bool giveQueue(queue *q,elmtype *e);//出队
bool getHead(queue *q,elmtype *e);//获取队头元素
void destroyQueue(queue *q);//销毁队列

int main(){
	//检查操作结果
	queue *q=initQueue();
	addQueue(q,11);
	addQueue(q,12);
	addQueue(q,13);
	elmtype e;
	giveQueue(q,&e);
	cout<<e<<endl;
	destroyQueue(q);

	return 0;
}
queue *initQueue(){
	queue *q=new queue;
	q->data=new elmtype[MAXSIZE];
	q->head=0;
	q->tail=0;
	return q;
}

bool addQueue(queue *q,elmtype elm){
	if((q->tail+1)%MAXSIZE==q->head){
		cout<<"Full queue"<<endl;
		return false;
	}
	q->data[q->tail]=elm;
	q->tail=(q->tail+1)%MAXSIZE;
	return true;
}

bool giveQueue(queue *q,elmtype *e){
	if(q->tail==q->head){
		cout<<"Empty queue"<<endl;
		return false;
	}
	*e=q->data[q->head];
	q->head=(q->head+MAXSIZE+1)%MAXSIZE;
	return true;
}

bool getHead(queue *q,elmtype *e){
	if(q->tail==q->head){
		cout<<"Empty queue"<<endl;
		return false;
	}
	*e=q->data[q->head];
	return true;
}
void destroyQueue(queue *q) {
    delete[] q->data; 
    delete q;  
	q=NULL;       
}












