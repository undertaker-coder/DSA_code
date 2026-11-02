
//注意，左孩子做线索时指向中序遍历的前一个结点，右孩子做线索时指向下一个节点
//线索化二叉树时还需二外创建头节点，其lch指向root，rch指向最后一个节点
//第一个遍历到的节点的lch指向头节点，最后一个遍历到的节点的rch指向头节点
//线索二叉树类似循环链表
#include<iostream>
#define MAX 100
using namespace std;
typedef char elmtype;

typedef struct node{
    elmtype data;
    bool  isLClue,isRClue;
    struct node * lch;
    struct node * rch;
}node;

typedef node* bitree;

void createTree(bitree &t,char *a,int &idx){
    if(a[idx]=='\0'){
        return;
    }
    if(a[idx]=='#'){
        t=NULL;
        idx++;
        return;
    }

}



