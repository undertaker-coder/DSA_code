//                       十字链表及其基本操作代码
//************************ Edited by 486desu *********************//
#include<iostream>
#define MAX 100
using namespace std;

typedef char VertexType;
typedef int EdgeType;

typedef struct edgenode{
    int fromvex;
    int tovex;
    struct edgenode *nextin,*nextout;
}edgenode;

typedef struct listnode{
    VertexType data;
    edgenode *nextin,*nextout;
}listnode;

typedef struct orList{
    int vertex_num;
    int edge_num;
    listnode *list[MAX];
}orlist;

void initList(orlist *G){
    G->vertex_num=4;
    G->edge_num=5;
    //初始化十字链表
    for(int i=0;i<G->vertex_num;i++){
        G->list[i]=new listnode;
        G->list[i]->data='0'+i;
        G->list[i]->nextin=NULL;
        G->list[i]->nextout=NULL;
    }
    //边数组
    int edge[5][2]={{0,3},{1,0},{2,0},{1,2},{2,1}};
    //构建十字链表
    for(int i=0;i<G->edge_num;i++){
        int from=edge[i][0];
        int to=edge[i][1];
        edgenode *a=new edgenode;
        //标记边的起点和终点
        a->fromvex=from;
        a->tovex=to;
        //头插法建立同终点（该listnode为终点）的入链表
        a->nextin=G->list[to]->nextin;
        G->list[to]->nextin=a;
        //头插法建立同起点（该listnode为起点）的出链表
        a->nextout=G->list[from]->nextout;
        G->list[from]->nextout=a;
      
    }
    return;
}

void printList(orlist *G){
    for(int i=0;i<G->vertex_num;i++){
        cout<<G->list[i]->data<<" ";
        cout<<endl<<"入链表： ";
        edgenode *a=G->list[i]->nextin;
        while(a!=NULL){
            cout<<a->fromvex<<" "<<a->tovex<<" | ";
            a=a->nextin;
        }

        cout<<endl<<"出链表： ";

        a=G->list[i]->nextout;
        while(a!=NULL){
            cout<<a->fromvex<<" "<<a->tovex<<" | ";
            a=a->nextout;
        }
        cout<<endl;
    }
    return;
}

int main(){
    orlist G;
    initList(&G);
    printList(&G);
    return 0;
}