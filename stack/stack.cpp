//                        栈的基本操作及其代码
//************************ Edited by 486desu *********************//
#include<iostream>
#define MAX 100
using namespace std;
typedef int elmtype;
typedef struct{
	elmtype * data;
	int top;
}stack;//结构定义
stack * initStack();//初始化栈
bool pushStack(stack *s,elmtype elm);//入栈
bool popStack(stack *s,elmtype *e);//出栈
bool getHead(stack *s,elmtype *e);//获取栈顶元素
void destroyStack(stack* s);//销毁栈



int main(){
    //操作检验
	stack *s=initStack();
	elmtype a, b;
	pushStack(s,11);
	pushStack(s,12);
    if (getHead(s, &a)) cout << a << endl;   
    if (popStack(s, &b)) cout << b << endl;  
    destroyStack(s); 
    
    return 0;
}

stack * initStack(){
	stack *s=new stack;
	s->data=new elmtype[MAX];
	s->top =-1;
	return s;
}

bool pushStack(stack *s,elmtype elm){
	if(s->top>=MAX-1){//判断栈满（注意栈的深度最大为MAX-1）
		cout<<"Full stack"<<endl;
		return false;
	}
	s->top++;
	s->data[s->top] = elm;
	
	return true;
}
bool popStack(stack *s,elmtype *e){
	if(s->top<0){//判断栈空 
		cout<<"Empty stack"<<endl;
		return false;
	}
	*e=s->data[s->top];
	s->top--;
	return true;
}

bool getHead(stack *s,elmtype *e){
	if(s->top<0){//判断栈空
		cout<<"Empty stack"<<endl;
		return false;
	}
	*e=s->data[s->top];
	return true;
}
//销毁栈，释放内存
void destroyStack(stack* s) {
    delete[] s->data;
    delete s;
}







