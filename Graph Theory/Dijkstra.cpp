#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define soja(i,a,n) for(ll i=a;i<=n;i++)
#define ulta(i,n,a) for(ll i=n;i>=a;i--)
#define pb push_back
const ll inf =1e18;
ll n,m,k,t,sum=0,node,edge,cost,src,minnode,u,w;
vector<pair<ll,ll>> adj[100005];
void dij(ll src)
{
        vector<ll>dis(node+1,inf),parent(node+1,-1);
        set<pair<ll,ll>>q;
        dis[src]=0;
        q.insert({dis[src],src});
        while(!q.empty())
        {
            k=q.begin()->second;
            q.erase(q.begin());
            for(auto x:adj[k])
            {
                u=x.first;
                w=x.second;
                if(dis[k]<inf&&dis[k]+w<dis[u])
                    {
                        q.erase({dis[u],u});
                        dis[u]=dis[k]+w;
                        parent[u]=k;
                         q.insert({dis[u],u});
                    }
            }

        }

}

int main()
{
    cin>>node>>edge;
    src=1;
    soja(i,0,edge-1)
    {
        cin>>n>>m>>cost;
     adj[n].pb({m,cost});
     adj[m].pb({n,cost});
    }

    dij(src);
}
