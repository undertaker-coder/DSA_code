//                      深度优先搜索及其基本操作代码
//************************ Edited by 486desu *********************//
#include<iostream>
#define MAX 100
using namespace std;

typedef char VertexType;
typedef int EdgeType;

typedef struct graph{
    int vertex_num;
    int edge_num;
    VertexType vertex[MAX];
    EdgeType edgeMap[MAX][MAX];
}graph;

void initGraph(graph *G){
    G->vertex_num=9;
    G->edge_num=15;
    //初始化vertex
    for(int i=0;i<G->vertex_num;i++){
        G->vertex[i]='A'+i;
    }
    //初始化边数组
    for(int i=0;i<G->vertex_num;i++){
        for(int j=0;j<G->vertex_num;j++){
            G->edgeMap[i][j]=0;
        }
    }
    //边数组
    int edge[15][2]={{0,1},{0,5},{1,6},{1,2},{1,8},{5,6},{5,4},
    {6,7},{4,7},{6,3},{7,3},{4,3},{8,3},{2,3},{8,2}};
    //存放边数组
    for(int i=0;i<G->edge_num;i++){
        int from=edge[i][0];
        int to=edge[i][1];
        G->edgeMap[from][to]=1;
        G->edgeMap[to][from]=1;
    }
    return;
}

void dfs1(graph *G,int i,int *visited){
    cout<<G->vertex[i]<<" ";
    visited[i]=1;
    for(int k=0;k<G->vertex_num;k++){
        if(visited[k]!=1 && G->edgeMap[i][k]!=0)
        dfs1(G,k,visited);
    }
    return;
}
void dfs(graph *G,int i){
    int visited[G->vertex_num]={0};
    dfs1(G,i,visited);
    return;
}

int main(){
    graph G;
    initGraph(&G);
    dfs(&G,0);
    return 0;

}
