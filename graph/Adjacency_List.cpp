#include<iostream>
#define MAX 100
using namespace std;

typedef char VertexType;
typedef int EdgeType;
//后继连接节点结构体
typedef struct edgeNode{
    int index;
    struct edgeNode *next=NULL;
}edgeNode;
//邻接表节点结构体
typedef struct listNode{
    VertexType data;
    struct edgeNode * next=NULL;
}listNode;

typedef struct adj_list{
    int vertex_num;
    int edge_num;
    listNode *list[MAX];
}adj_list;

//初始化邻接表
void initGraph(adj_list *G){
    G->vertex_num=4;
    G->edge_num=5;
    //存放联通边
    int edge[5][2]={{0,1},{0,2},{0,3},{1,2},{2,3}};
    //初始化邻接表
    for(int i=0;i<G->vertex_num;i++){
        G->list[i]=new listNode;
        G->list[i]->data='0'+i;
    }

    for(int i=0;i<G->edge_num;i++){
        int from=edge[i][0];
        int to=edge[i][1];
        edgeNode *a=new edgeNode;
        a->index=to;
        a->next=G->list[from]->next;
        G->list[from]->next=a;
    }
    
    for(int i=0;i<G->edge_num;i++){
        int to=edge[i][0];
        int from=edge[i][1];
        edgeNode *a=new edgeNode;
        a->index=to;
        a->next=G->list[from]->next;
        G->list[from]->next=a;
    }
    return;
}

void printGraph(adj_list *G){
    for(int i=0;i<G->vertex_num;i++){
        cout<<G->list[i]->data<<" ";
        edgeNode *a=G->list[i]->next;
        while(a!=NULL){
            cout<<a->index<<" ";
            a=a->next;
        }
        cout<<endl;
    }
    return;
}
int main(){
    adj_list *G=new adj_list;
    initGraph(G);
    printGraph(G);
    return 0;
}
