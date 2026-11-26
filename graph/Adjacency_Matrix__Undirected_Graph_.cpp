//                       邻接矩阵其基本操作代码（无向图）
//************************ Edited by 486desu *********************//
#include<iostream>
#define MAX 100
using namespace std;
typedef char VertexType;
typedef int EdgeType;

typedef struct{
    VertexType vertex[MAX];
    EdgeType edge[MAX][MAX];
    int vertex_num;
    int edge_num;
}adj_graph;

void initGraph(adj_graph *G){
    G->vertex_num=4;
    G->edge_num=5;
    //初始化邻接矩阵
    for(int i=0;i<G->vertex_num;i++){
        for(int j=0;j<G->vertex_num;j++){
            G->edge[i][j]=0;
        }
    }
    //初始化顶点数组
    for(int i=0;i<G->vertex_num;i++){
        G->vertex[i]='0'+1;
    }
    //填入邻接矩阵
    G->edge[0][1]=G->edge[1][0]=1;
    G->edge[0][2]=G->edge[2][0]=1;
    G->edge[0][3]=G->edge[3][0]=1;
    G->edge[1][2]=G->edge[2][1]=1;
    G->edge[2][3]=G->edge[3][2]=1;
    //
    return;


}
void printGraph(adj_graph *G){
    for(int i=0;i<G->vertex_num;i++){
        for(int j=0;j<G->vertex_num;j++){
            cout<<G->edge[i][j]<<" ";
        }
        cout<<endl;
    }
    return;
}
int main(){
    adj_graph G;
    initGraph(&G);
    printGraph(&G);
    return 0;
}








