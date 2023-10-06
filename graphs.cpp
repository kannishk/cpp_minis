#include<iostream>
#include <queue>
using namespace std;
void bfs();
void dfs();
void dfs_traversal(int node);


    const int N = 1e5+2;
    bool vis[N];
    vector<int> adj[N];

int main(){

    // bfs();
    dfs();

    return 0;
}
    
void bfs(){

    for(int i=0;i<N;i++){
        vis[i]=0;
    }

    int n,m;
    cin>>n>>m;

    int x,y;

    for(int i=0;i<m;i++){
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    queue<int> q;
    q.push(1);
    vis[1]=true;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<endl;

        for(auto i: adj[node]){
            if(!vis[i]){
                vis[i]=true;
                q.push(i);
            }
        }
    }
}

void dfs(){
    // const int N = 1e5+2;
    // bool vis[N];
    // vector<int> adj[N];

    for(int i=0;i<N;i++){
        vis[i]=0;
    }

    int n,m;
    cin>>n>>m;

    int x,y;

    for(int i=0;i<m;i++){
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs_traversal(1);
}

void dfs_traversal(int node){
    vis[node]=true;

    for(auto i : adj[node]){
        if(!vis[i]){
            dfs_traversal(i);
        }
    }

    cout<<node<<endl;
}