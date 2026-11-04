//                        线索二叉树的基本操作及其代码
//************************ Edited by 486desu *********************//


//注意，左孩子做线索时指向中序遍历的前一个结点，右孩子做线索时指向下一个节点
//线索化二叉树时还需二外创建头节点，其lch指向root，rch指向最后一个节点
//若为空树，则头节点lch指向自身
//第一个遍历到的节点的lch指向头节点，最后一个遍历到的节点的rch指向头节点
/*线索二叉树类似循环链表遍历，但只能进行中序遍历，先左孩子搜索到底，再后继跳转，最后访问右节点，
不断重复以上流程*/
#include<iostream>
using namespace std;

typedef struct node{
	char data;
	bool lf=false;
	bool rf=false;//判断lch和rch是否表示前驱/后继
	struct node * lch,* rch;
}node ;
typedef node * bitree;

void createTree(bitree &t,const char *a,int &idx);//创建树并初始化lf,rf
void midThreadTree(bitree &t,bitree &prev);//中序线索化
bitree createThreadTree(const char *a);//创建中序线索化的线序哦二叉树
void midReverseTree(bitree head);//以链表形式中序遍历线索二叉树
void destroyNode(bitree &t);
void destroyThreadTree(bitree &head);//销毁树


int main(){
	//测试
	bitree head=createThreadTree("ABD##E##C##");
	midReverseTree(head);
	return 0;
}


void createTree(bitree &t,const char *a,int &idx){
	if(a[idx]=='\0'){
		t=NULL;
		return;
	}
	if(a[idx]=='#'){
		t=NULL;
		idx++;//别忘记自加
		return;
	}

	t=new node;
	t->data=a[idx];
	idx++;

	createTree(t->lch,a,idx);
	if(t->lch==NULL){
		t->lf=true;
	}//初始化lf

	createTree(t->rch,a,idx);
	if(t->rch==NULL){
		t->rf=true;
	}//初始化rf

	return;
}

void midThreadTree(bitree &t,bitree &prev){
	if(t==NULL){
		return;
	}
	
	midThreadTree(t->lch,prev);
	
	if(t->lf==true){
		t->lch=prev;
	}//前驱线索化
	if(prev->rf==true){
		prev->rch=t;
	}//后继线索化
	
	prev=t;//移动prev
	
	midThreadTree(t->rch,prev);
	
	return;
	
}

bitree createThreadTree(const char *a){
	bitree head=new node;

	head->data='0';
	head->lf=false;
	head->rf=true;
	head->lch=head->rch=NULL;//创建并初始化head

	bitree t=NULL;
	int idx=0;

	createTree(t,a,idx);//创建树

	if(t==NULL){
		head->lch=head;
		head->rch=head;
		return head;
	}//空树
	else{
		head->lch=t;
	}

	bitree prev=head;
	midThreadTree(t,prev);
	if(prev->rf){//最后一个节点是否可以后续线索化
	    prev->rch=head;//补齐最后一个节点
	}
	head->rch=prev;

	return head;
	 
}

void midReverseTree(bitree head){
	if(head->lch==head){
		cout<<"Empty tree"<<endl;
		return;
	}//空树
	bitree i=head->lch;

	while(i!=head){//环形链表终止条件
	    while(i->lf==false){
		    i=i->lch;
	    } //寻找该节点的最左子树
		cout<<i->data<<" ";
		while(i->rf==true&&i->rch!=head){
			i=i->rch;
			cout<<i->data<<" "; 
		}//跳转后继节点（同时遍历它们）
		i=i->rch;//跳转到右节点，重复以上过程
	}
	cout<<endl;
	return;
}


void destroyNode(bitree &t){//只能后序遍历销毁树
    if(t == NULL) return;//空树
    if(t->lf == false) destroyNode(t->lch);   // 真左孩子才递归
    if(t->rf == false) destroyNode(t->rch);   // 真右孩子才递归
    delete t;
    t = NULL;
}

void destroyThreadTree(bitree &head){
    if(head == NULL) return;
    if(head->lch != head){        // 空树就只剩一个 head
        destroyNode(head->lch);
    }
    delete head;
    head = NULL;
}












