#include<iostream>
using namespace std;
#define MAX 100
typedef struct node{
	int weight;
	int parent,lch,rch;
}node;

typedef node  Hufftree[MAX];

void selectMin(Hufftree ht,int n,int &s1,int &s2) {
	s1=s2=-1;
	for(int i=0;i<n;i++){
		if(ht[i].parent==-1){
			if(s1==-1||ht[i].weight<ht[s1].weight){
				s2=s1;
				s1=i;
			
			}else if(s2==-1||ht[i].weight<ht[s2].weight){
				s2=i;
			}
		}
	}
	return;
}

void createHufftree(Hufftree ht,int *weights,int n){
	int i;
	int m=2*n-1;
	for(i=0;i<m;i++){
		ht[i].weight=weights[i];
		ht[i].parent=-1;
		ht[i].lch=-1;
		ht[i].rch=-1;
	}
	
	for(i=n;i<m;i++){
		int s1,s2;
		selectMin(ht,i,s1,s2);
		ht[s1].parent=i;
		ht[s2].parent=i;
		ht[i].weight=ht[s1].weight+ht[s2].weight;
		ht[i].lch=s1;
		ht[i].rch=s2;
	}
	return ;
}

void printHufftree(Hufftree ht,int n){
    int m=2*n-1;
    cout<<"weight"<<"\t"<<"parent"<<"\t"<<"lch"<<"\t"<<"rch"<<endl;
	for(int i=0;i<m;i++){
		cout<<ht[i].weight<<"\t"<<ht[i].parent<<"\t"<<ht[i].lch<<"\t"<<ht[i].rch<<endl;
	} 
	return;
}

int main(){
	int weights[]={5,15,40,30,10};
	int n=sizeof(weights)/sizeof(weights[0]);
	Hufftree ht;
	createHufftree(ht,weights,n);
	printHufftree(ht,n);
	return 0;
}











