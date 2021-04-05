#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define soja(i,a,n) for(ll i=a;i<=n;i++)
#define ulta(i,n,a) for(ll i=n;i>=a;i--)
#define pb push_back
const ll inf =1e9+7;
ll n,m,k,t,sum=0,node,edge,cost,src,minnode;
ll adj[1000][1000];
void dij(ll src)
{
    //making all dis inf
    vector<ll>dis(node+1,inf);
    //making all nodes unvisited
    vector<ll>vis(node+1,0);
    //make the src node 0 
    dis[src]=0;
    //finding for all the nodes except the last node
    soja(i,0,node-2)
    {
        k=inf,minnode=0;
        //finding the minimum dist from all the unvisited nodes
        soja(j,0,node-1)
        {
            if(vis[j]==0&&dis[j]<=k)
                k=dis[j],minnode=j;
        }
        // making the found node visit
        vis[minnode]=1;
        //changing all the unvisited nodes distance 
        soja(j,0,node-1)
        {
            if(vis[j]==0&&adj[minnode][j]!=-1&&(dis[minnode]+adj[minnode][j])<dis[j])
                dis[j]=dis[minnode]+adj[minnode][j];
        }
    }
    soja(i,0,node-1)
    cout<<dis[i]<<" ";
    cout<<endl;
}
int main()
{
    cin>>node>>edge;
    src=0;
    memset(adj,-1,sizeof(adj));
    soja(i,0,edge-1)
    {
        cin>>n>>m>>cost;
        adj[n][m]=cost;
          adj[m][n]=cost;
    }
    dij(src);
}
