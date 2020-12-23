#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define soja(i,a,n) for(ll i=a;i<=n;i++)
#define ulta(i,n,a) for(ll i=n;i>=a;i--)
#define pb push_back
vector<ll>adj[1000],dis(1000,-1);
ll bfs(ll n)
{
    queue<ll>q;
    ll k=0;
    dis[n]=0;
    q.push(n);
    while(1)
    {
        if(!q.size())
            break;
            n=q.front();
            q.pop();
           // cout<<n<<endl;
        for(auto i:adj[n])
        {

            if(dis[i]==-1)
            {
                dis[i]=dis[n]+1;
                q.push(i);
            }
            dis[i]=min(dis[i],dis[n]+1);
        }
    }
}
int main()
{
    ll n,m,k,t,sum=0;
    ll node,edge;
    cin>>node>>edge;
    soja(i,0,edge-1)
    {
        cin>>n>>m;
        adj[n].pb(m);
        adj[m].pb(n);
    }
    bfs(1);
    soja(i,1,node)
    cout<<dis[i]<<" ";
    cout<<endl;
    return 0;
}
