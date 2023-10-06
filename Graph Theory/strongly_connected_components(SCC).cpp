#include"bits/stdc++.h"
using namespace std;
#define ll long long int
#define soja(i,a,n) for(ll i=a;i<=n;i++)
#define ulta(i,n,a) for(ll i=n;i>=a;i--)
#define pb push_back
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl "\n"
const ll mod=1e9+7;
void modnor(ll &x) {x %= mod; if(x < 0)(x += mod);}
ll modmul(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); return (x*y)%mod; }
ll modadd(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); return (x+y)%mod; }
ll modsub(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); x -= y; modnor(x); return x; }
ll modpow(ll b, ll p) { ll r = 1; while(p) {if(p&1) r = modmul(r, b); b = modmul(b, b);p >>= 1;}return r;}
ll modinverse(ll x){return modpow(x,mod-2);}  /// if mod is prime.
ll moddiv(ll x, ll y){return modmul(x,modinverse(y));}
const ll mx=1e5+7;
ll vis[mx],have[mx];
ll a[mx];
vector<ll>adj[mx],radj[mx];
stack<ll>st;
ll com=0;
void dfs(ll node)
{
    vis[node]=1;
    for(auto xx:adj[node])
    {
       if(vis[xx]==0)
       {
        vis[xx]=1;
        dfs(xx);

       }

    }
    st.push(node);
}
void dfs1(ll node)
{
    vis[node]=1;
     for(auto xx:radj[node])
    {
       if(vis[xx]==0)
       {
        vis[xx]=1;
        dfs1(xx);

       }
    }

}
int main()
{

    fast;
    ll n,m,k,t,sum=0,x,y;
    cin>>n>>m;
    soja(i,1,n)
    {
        adj[i].clear();
        radj[i].clear();
        vis[i]=0;
        have[i]=0;
    }
    soja(i,1,m)
    {
        cin>>x>>y;
        if(x==y)continue; // if there is any self loops
        adj[x].pb(y);
        radj[y].pb(x);
    }
    soja(i,1,n)
    {
        if(vis[i]==0)
        {
            vis[i]=1;
            dfs(i);
        }
        if(adj[i].size()==0)have[i]=1;

    }
    soja(i,1,n)vis[i]=0;
    while(st.size())
    {

        x=st.top();
        st.pop();
        if(vis[x]==0)
        {
            vis[x]=1;
            dfs1(x);
          com++;
        }
    }
   cout<<com<<endl;

}

