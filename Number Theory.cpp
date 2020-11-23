#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define soja(i,a,n) for(ll i=a;i<=n;i++)
#define ulta(i,n,a) for(ll i=n;i>=a;i--)
#define pb push_back
ll bfs(ll node,ll edge,ll st,ll dt,vector<ll>adj[],vector<ll>parent)
{
    queue<ll>q;
    vector<bool>vis(node+1,0);
    vector<ll>d(node+1,0);
    q.push(st);
    ll k;
    while(1)
    {
        if(q.empty()==1)
            break;
        k=q.front();
        vis[k]=1;
        q.pop();
        soja(i,0,adj[k].size()-1)
        {
            if(vis[adj[k][i]]==0&&k<adj[k][i])
               {
                q.push(adj[k][i]);
                d[adj[k][i]]=d[k]+1;}
        }
    }
    if(vis[dt]==0)
        return -1;
        else
            return d[dt];
            

}
int main()
{
    ll node,edge,st,dt,a,b;
    cin>>node>>edge>>st>>dt;
    vector<ll>parent(node+1,-1);
 vector<ll>adj[node+1];
 soja(i,1,edge)
 {
     cin>>a>>b;
     adj[a].pb(b);
     adj[b].pb(a);
     parent[b]=a;
 }
 cout<<"Shortest distance "<<bfs(node,edge,st,dt,adj,parent)<<endl;
}

