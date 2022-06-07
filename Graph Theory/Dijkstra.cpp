#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define soja(i,a,n) for(ll i=a;i<=n;i++)
#define ulta(i,n,a) for(ll i=n;i>=a;i--)
#define pb push_back
const ll inf =1e18;
const ll mx=1e5+7;
ll n,m,k,t,sum=0,node,edge,cost,src,minnode,u,w;
vector<pair<ll,ll>> adj[mx];
ll dis[mx];
ll parent[mx];
void dij(ll src)
{
       priority_queue<pair<ll,ll>>q;
        dis[src]=0;
        q.push({dis[src],src});
        while(!q.empty())
        {
            k=q.top().second;
            q.pop();
            for(auto x:adj[k])
            {
                u=x.first;
                w=x.second;
                if(dis[k]+w<dis[u])
                    {
                        dis[u]=dis[k]+w;
                        parent[u]=k;
                        q.push({dis[u],u});
                    }
            }

        }

}

int main()
{
	soja(i,0,mx-1)
	{
		dis[i]=inf;
		parent[i]=-1;
	}
    cin>>node>>edge;
    src=1;
    soja(i,0,edge-1)
    {
        cin>>n>>m>>cost;
     adj[n].pb({m,cost});
     adj[m].pb({n,cost});
    }

    dij(src);
	/*
    soja(i,1,node)
    {
    	cout<<"DIS  "<<i<<" "<<dis[i]<<endl;
    	k=i;
    	cout<<"path of "<<i<<endl;
    	while(parent[k]!=-1)
    	{
    		cout<<k<<" ";
    		k=parent[k];
    	}
    	cout<<endl;
    }*/
}
