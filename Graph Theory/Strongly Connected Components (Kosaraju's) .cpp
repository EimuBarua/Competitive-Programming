#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define soja(i,a,n) for(ll i=a;i<=n;i++)
#define ulta(i,n,a) for(ll i=n;i>=a;i--)
#define pb push_back
const ll mx=1e5+5;
vector<ll>adj[mx],tra[mx];
ll vis[mx],vis1[mx];
stack<ll>s;
void dfs(ll x)///normal dfs
{
    vis[x]=1;
    for(auto xx:adj[x])
    {
        if(vis[xx]==0)
        {
            vis[xx]=1;
            dfs(xx);
        }
    }
    s.push(x);
}
void dfs1(ll x)/// for transpose dfs
{
    cout<<x<<" ";///printing the strongly connected components
    vis1[x]=1;
    for(auto xx:tra[x])
    {
        if(vis1[xx]==0)
        {
            vis1[xx]=1;
            dfs1(xx);
        }
    }

}
int main()
{
    ll n,m,k,t,sum=0,node,edge,x,y;
    scanf("%lld %lld",&node,&edge);
    soja(i,1,edge)
    {
        scanf("%lld %lld",&x,&y);
        adj[x].pb(y);
        tra[y].pb(x);
    }
    soja(i,1,node)
    {
        if(vis[i]==0)
    dfs(i);
    }
    while(s.size())///according to their ending time
    {
        x=s.top();
        ///cout<<x<<endl;
        if(vis1[x]==0)
        {
            vis1[x]=1;
            dfs1(x);
            cout<<endl;
        }
        s.pop();
    }

}

