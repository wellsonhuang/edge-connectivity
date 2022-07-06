#include <algorithm>
#include <iostream>
#include<vector>
#include <string.h>
#include<stdio.h>
#define N 1000000
using namespace std;
 
int numbers,counter,DFN[N],low[N],head[N];

struct node{
    int u,v,next;
    bool bridge;
}edge[N];
// 
//bool cmp(node a,node b){
  //  return a.u<b.u;
//}

 
void makeEdge(int u,int v){
    edge[numbers].u=u;
    edge[numbers].v=v;
    edge[numbers].next=head[u];
    edge[numbers].bridge=false;
    head[u]=numbers++;
    edge[numbers].u=v;
    edge[numbers].v=u;
    edge[numbers].next=head[v];
    edge[numbers].bridge=false;
    head[v]=numbers++;
 
}
 
void initial(){
    numbers=0;
    counter=0;
    memset(DFN,0,sizeof(DFN));
    memset(low,0,sizeof(low));
    memset(head,-1,sizeof(head));
}
 
 
void Tarjan(int u,int pre){
    DFN[u]=low[u]=++counter;
    for(int i=head[u];i!=-1;i=edge[i].next){
        int v=edge[i].v;
        if(v==pre){
            continue;
        }
        if(!DFN[v]){
            Tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>DFN[u]){
                edge[i].bridge=edge[i^1].bridge=true;
            }
        }else{
            low[u]=min(low[u],DFN[v]);
        }
    }
}
 
void print(int n){
    for(int i=0;i<n;i++){
        if(!DFN[i]){
            Tarjan(i,i);
        }
    }
 
    vector <pair<int,int> >answer;
    for(int i=0;i<numbers;i++){
        if(edge[i].bridge==true&&edge[i].v>edge[i].u){
            answer.push_back(make_pair(edge[i].u,edge[i].v));
        }
    }
    sort(answer.begin(),answer.end());
    for(int i=0;i<answer.size();i++){
        printf("%d %d\n",answer[i].first,answer[i].second);
    }
 
 
}
 


int main() {
   int n;
   while(scanf("%d",&n)!=EOF){
       initial();
       int u , v;
       while(cin>>u>>v){
       makeEdge(u,v);
       }
       print(n);
   }

}
