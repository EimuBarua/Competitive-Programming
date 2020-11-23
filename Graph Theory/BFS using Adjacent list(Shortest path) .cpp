#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define soja(i,a,n) for(ll i=a;i<=n;i++)
#define ulta(i,n,a) for(ll i=n;i>=a;i--)
#define pb push_back
ll bfs(ll node,ll edge,ll st,ll dt,vector<ll>adj[],vector<ll>&d,vector<ll>parent,vector<ll>&path)
{
    ll k;
    vector<bool>vis(node+1,0);
    queue<ll>q;
    q.push(st);

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
            {q.push(adj[k][i]);
            d[adj[k][i]]=d[k]+1;
            }
        }
    }
    if(vis[dt]==0)
        return 0;
    k=dt;
    bool fg=0;
        while(1)
    {
        if(k==-1)
            break;
            if(fg==0)
        path.pb(k);
        if(k==st)
            fg=1;
        k=parent[k];
    }
    if(fg==0)
    return 0;
    else
        return 1;
}
int main()
{
    ll node,edge,a,b,st,dt;
    cin>>node>>edge>>st>>dt;
    vector<ll>d(node+1,0);
    vector<ll>path;
    vector<ll>adj[node+1];
    vector<ll>parent(node+1,-1);
    soja(i,1,edge)
    {
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
        parent[b]=a;
    }
    if(bfs(node,edge,st,dt,adj,d,parent,path)==0)
        cout<<"NO path"<<endl;
    else
    {
    cout<<d[dt]<<endl;
ulta(i,path.size()-1,0)
cout<<path[i]<<" ";
cout<<endl;
    }
    return 0;
}
