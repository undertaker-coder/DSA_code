#include<iostream>
#define MAX 100
using namespace std;
typedef int elmtype;
typedef struct{
	elmtype * data;
	int top;
}stack;
stack * initStack();
bool pushStack(stack *s,elmtype elm);
bool popStack(stack *s,elmtype *e);
bool getHead(stack *s,elmtype *e);
void destroyStack(stack* s);



int main(){
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
	if(s->top>=MAX-1){
		cout<<"Full stack"<<endl;
		return false;
	}
	s->top++;
	s->data[s->top] = elm;
	
	return true;
}
bool popStack(stack *s,elmtype *e){
	if(s->top<0){
		cout<<"Empty stack"<<endl;
		return false;
	}
	*e=s->data[s->top];
	s->top--;
	return true;
}

bool getHead(stack *s,elmtype *e){
	if(s->top<0){
		cout<<"Empty stack"<<endl;
		return false;
	}
	*e=s->data[s->top];
	return true;
}

void destroyStack(stack* s) {
    delete[] s->data;
    delete s;
}







