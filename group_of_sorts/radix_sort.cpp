//                        基数排序及其基本操作代码
//************************ Edited by 486desu *********************//
#include<iostream>
#include<math.h>
#define MAXSIZE 100//最大队列长度

using namespace std;

typedef int elmtype;

typedef struct {
	elmtype *data;
	int head;
	int tail;
} queue;
//队列实现
queue *initQueue();
bool addQueue(queue *q, elmtype elm);
bool giveQueue(queue *q, elmtype *e);
bool getHead(queue *q, elmtype *e);
bool isEmpty(queue *q);
void destroyQueue(queue *q);
//基数排序
void radixSort(int *a,int len,int maxnum);
void printList(int *a,int len);

int main(){
    int len;
    cin>>len;
    int a[len]={0};
    for(int i=0;i<len;i++){
        cin>>a[i];
    }
    int maxnum=1;  // 最大位数，初始为 1
    int base = 10;  // 用整型来代替 pow，效率高且准确
    
    for(int i = 0; i < len; i++){
        // 用 while 确保能找出最大的位数，比如 999 会一直找到 1000
        while(a[i] >= base){ 
            maxnum++;
            base *= 10;
        }
    }
    radixSort(a,len,maxnum);
    printList(a,len);
    return 0;
}
//具体函数实现

queue *initQueue() {
	queue *q = new queue;
	q->data = new elmtype[MAXSIZE];
	q->head = 0;
	q->tail = 0;
	return q;
}

bool addQueue(queue *q, elmtype elm) {
	if ((q->tail + 1) % MAXSIZE == q->head) {
		//cout << "Full queue" << endl;
		return false;
	}
	q->data[q->tail] = elm;//尾加
	q->tail = (q->tail + 1) % MAXSIZE;
	return true;
}

bool giveQueue(queue *q, elmtype *e) {
	if (q->tail == q->head) {
		//cout << "Empty queue" << endl;
		return false;
	}
	*e = q->data[q->head];//头出
	q->head = (q->head + MAXSIZE + 1) % MAXSIZE;
	return true;
}

bool getHead(queue *q, elmtype *e) {
	if (q->tail == q->head) {
		//cout << "Empty queue" << endl;
		return false;
	}
	*e = q->data[q->head];//头出
	return true;
}

bool isEmpty(queue *q) {
    return q->head == q->tail;
}

void destroyQueue(queue *q) {
    delete[] q->data; 
    delete q;  
	q = NULL;       
}



void radixSort(int *a,int len,int maxnum){
	queue *q[10];
	queue *tmp;//临时队列，存放上一轮排序结果
	tmp=initQueue(); 
	for(int i=0;i<10;i++){
		q[i]=initQueue();//初始化10个队列，存放1-10位的数字
	}
	for(int i=0;i<len;i++){
		addQueue(tmp,a[i]);//将原数组元素放入临时队列
	}
	int now=1;//当前位数，1表示个位，10表示十位，100表示百位
	for(int j=1;j<maxnum+1;j++){//循环maxnum次，分别对每一位进行排序
		
		while(!isEmpty(tmp)){//将上一轮排序结果放入对应队列
     		int k;
			giveQueue(tmp,&k);
			addQueue(q[(k/now)%10],k);//将k放入对应队列，注意%10，否则可能越界
		}
		for(int k=0;k<10;k++){//将每个队列中的元素放入临时队列
			while(!isEmpty(q[k])){//取到对应队列为空为止
				int z;
				giveQueue(q[k],&z);
				addQueue(tmp,z);
			}
		}
        now*=10;//位数增加
	}
	for(int i=0;i<len;i++){
		int k;
		giveQueue(tmp,&k);
		a[i]=k;//将排序结果放回原数组
	}
	destroyQueue(tmp);
    for(int i=0;i<10;i++){
        destroyQueue(q[i]);
    }//释放队列内存
	return;
    
}
void printList(int *a,int len){
    for(int i=0;i<len;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return;
}
















