//                       广度优先搜索及其基本操作代码
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

void bfs(graph *G,int a){
    //队列和visited数组初始化
    int Queue[MAX]={0};
    int head=0;
    int tail=0;
    int visited[G->vertex_num]={0};
    //前置工作（处理首项）
    Queue[0]=a;
    tail++;
    visited[a]=1;
    cout<<G->vertex[a]<<" ";
    //广度优先遍历
    while(tail!=head){
  //    cout<<G->vertex[Queue[head]]<<" ";  错误写法，出队时无需输出，入队时才要输出
        for(int i=0;i<G->vertex_num;i++){
            if(G->edgeMap[Queue[head]][i]!=0 && visited[i]!=1){
                visited[i]=1;
                cout<<G->vertex[i]<<" ";
                Queue[tail]=i;
                tail++;

            }
        }
        head++;
    }
    return;



}

int main(){
    graph G;
    initGraph(&G);
    bfs(&G,0);
    return 0;

}
