#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define soja(i,a,n) for(ll i=a;i<=n;i++)
#define ulta(i,n,a) for(ll i=n;i>=a;i--)
#define pb push_back
const ll mx=1000;
vector<bool>vis(mx+1,0);
vector<ll>adj[mx];
void dfs(ll a)
{
 /// cout<<a<<endl;
vis[a]=1;
for(auto i:adj[a])
{
  if(vis[i]==0)
  dfs(i);
}
}
int main() {
    ll node,edge,a,b,st;
  cin>>node>>edge;
  soja(i,0,edge-1)
  {
    cin>>a>>b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  cin>>st;
  dfs(st);
    return 0;
}
