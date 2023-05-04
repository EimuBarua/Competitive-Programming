#include<bits/stdc++.h>
using namespace std;
#define ll  long long int
#define soja(i,a,n) for(ll i=a;i<=n;i++)
#define ulta(i,n,a) for(ll i=n;i>=a;i--)
#define pb push_back
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const ll mod=1e9+7;
void modnor(ll &x) {x %= mod; if(x < 0)(x += mod);}
ll modmul(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); return (x*y)%mod; }
ll modadd(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); return (x+y)%mod; }
ll modsub(ll x, ll y) { x %= mod, y %= mod; modnor(x),modnor(y); x -= y; modnor(x); return x; }
ll modpow(ll b, ll p) { ll r = 1; while(p) {if(p&1) r = modmul(r, b); b = modmul(b, b);p >>= 1;}return r;}
ll modinverse(ll x){return modpow(x,mod-2);}  /// if mod is prime.
ll moddiv(ll x, ll y){return modmul(x,modinverse(y));}
ll check(ll n)
{
    ll k=modmul(n,n+1);
    return k;
}
int main()
{
    fast;
    ll n,m,k,t,sum=0,f=0;
    cin>>n;
    soja(i,1,n)
    {
        m=n/i;
        t=n/m;
       k=modsub(check(t),check(i-1));
        sum=modadd(sum,modmul(m,k));
        i=t;
    }
    cout<<moddiv(sum,2LL)<<endl;
 
}
