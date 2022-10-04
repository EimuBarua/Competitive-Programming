/// complexity  O(nlogn) // n edge

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define soja(i,a,n) for(ll i=a;i<=n;i++)
#define ulta(i,n,a) for(ll i=n;i>=a;i--)
#define pb push_back
#define endl "\n"
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const ll mx=1e5+7;
ll par[mx];
ll ran[mx];
void make_set(ll n)
{
    soja(i,1,n)
        {par[i]=i;
        ran[i]=0;}
}
ll find_set(ll x)
{
    if(par[x]==x)
        return x;
    return par[x]=find_set(par[x]);
}
void uni(ll x,ll y)
{
    x=find_set(x);
    y=find_set(y);
    if(x!=y)
    {
        if(ran[x]==ran[y])
        {
        ran[x]++;
        par[y]=x;
        }
        else if(ran[x]>ran[y])
            par[y]=x;
        else
            par[x]=y;

    }
}
int main()
{
    fast;
    ll node,edge,x,y,cost,sum=0;
    cin>>node>>edge;
    make_set(node);
    vector<pair<ll,pair<ll,ll>>>adj,mst;
    soja(i,1,edge)
    {cin>>x>>y>>cost;
    adj.pb({cost,{x,y}});
    }
    cout<<endl;
    sort(adj.begin(),adj.end());
    soja(i,0,edge-1)
    {
        cost=adj[i].first;
        x=adj[i].second.first;
        y=adj[i].second.second;
        if(find_set(x)!=find_set(y))
        {
            mst.pb({x,{y,cost}});
            uni(x,y);
        }
    }
    soja(i,0,mst.size()-1)
    {
        sum+=mst[i].second.second;
        cout<<mst[i].first<<" "<<mst[i].second.first<<" "<<mst[i].second.second<<endl;
    }
    cout<<"COST "<<sum<<endl;


    return 0;
}
