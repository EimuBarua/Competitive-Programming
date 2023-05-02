#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define soja(i,a,n) for(ll i=a;i<=n;i++)
#define ulta(i,n,a) for(ll i=n;i>=a;i--)
#define pb push_back
const ll mx=2e5+7;
vector<ll>adj[mx];
ll dp[mx];
void dfs(ll node)
{

    for(auto xx:adj[node])
    {
        dfs(xx);
        dp[node]+=dp[xx]+1;
    }
}

int main()
{
	ll n,m,k,t,sum=0,x,y;
	cin>>n;
	soja(i,2,n)
	{
	    cin>>x;
	    adj[x].pb(i);
	}
	dfs(1);
	soja(i,1,n)
	cout<<dp[i]<<" ";
	cout<<endl;
}
