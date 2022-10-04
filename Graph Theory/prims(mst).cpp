/// complexity  O(nlogn)

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define soja(i,a,n) for(ll i=a;i<=n;i++)
#define ulta(i,n,a) for(ll i=n;i>=a;i--)
#define pb push_back
#define endl "\n"
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const ll mx=1e5+7;
vector<pair<ll,ll>>adj[mx+5];
ll parent[mx],mcost[mx],mst[mx];
int main()
{
    fast;
    ll node,edge,x,y,cost,sum=0;
    cin>>node>>edge;
    soja(i,1,edge)
    {cin>>x>>y>>cost;
    adj[x].pb({y,cost});
    adj[y].pb({x,cost});}
    soja(i,1,node)
    {
        parent[i]=-1;
        mcost[i]=1e18;
        mst[i]=0;
    }
    ll st=1;/// start node 1
    mcost[st]=0;
    priority_queue<pair<ll,ll>>pq;
    pq.push({0,st});
   while(pq.size()>0)
    {
        st=pq.top().second;
        pq.pop();
        mst[st]=1;
        for(auto xx:adj[st])
        {
            if(mst[xx.first]==0&&mcost[xx.first]>xx.second)
            {
                parent[xx.first]=st;
                mcost[xx.first]=xx.second;
                pq.push({mcost[xx.first]*-1,xx.first});
            }
        }
    }
    for(ll i=1;i<=node;i++)
    {
       // cout<<parent[i]<<" "<<i<<endl;
        sum+=mcost[i];
    }
    cout<<sum<<endl;///sum of the cost of the tree

    return 0;
}
