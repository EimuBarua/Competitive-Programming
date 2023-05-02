#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define soja(i,a,n) for(ll i=a;i<=n;i++)
#define ulta(i,n,a) for(ll i=n;i>=a;i--)
#define pb push_back
const ll mx=2e5+7;
ll a[mx];
ll tree[mx*4];
void build(ll x,ll y,ll node)
{
	if(x==y)
		tree[node]=a[x];
	else
	{
		ll mid=(x+y)/2;
		build(x,mid,node*2);
		build(mid+1,y,node*2+1);
		tree[node]=min(tree[node*2],tree[node*2+1]);
	}
}
ll query(ll x,ll y,ll x1,ll y1,ll node)
{
	if(y1<x||y<x1)
		return 1e18;
	if(x<=x1&&y>=y1)
		return tree[node];
	ll mid=(x1+y1)/2;
	ll sum=query(x,y,x1,mid,node*2);
	sum=min(sum,query(x,y,mid+1,y1,node*2+1));
	return sum;
}

int main()
{
	ll n,m,k,t,sum=0,x,y;
	cin>>n>>m;
	soja(i,1,n)
	{
		cin>>a[i];
	}
	build(1,n,1);
	soja(i,1,m)
	{
	    cin>>x>>y;
	    sum=query(x,y,1,n,1);
	    cout<<sum<<endl;
	}
}
