
// primefactor in O(logn) but have to use seive
#include<bits/stdc++.h>
using namespace std;
#define ll int
#define soja(i,a,n) for(ll i=a;i<=n;i++)
#define ulta(i,n,a) for(ll i=n;i>=a;i--)
#define pb push_back
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const ll mx=1e7+1;
ll vis[mx+5];
void seive()
{
    for(ll i=1;i<=mx;i++)vis[i]=1e9;
    vis[1]=1;
    for(ll i=3;i*i<=mx;i+=2)
    {
        if(vis[i]==1e9)
        {
        vis[i]=i;
        for(ll j=i*i;j<mx;j+=2*i)
        vis[j]=min(i,vis[j]);}
    }
    for(ll i=3;i<=mx;i+=2)
    {
        if(vis[i]==1e9)vis[i]=i;
    }
    for(ll i=2;i<=mx;i+=2)vis[i]=2;

}
vector<ll>primefactor(ll n)
{

    vector<ll>v;
        while(vis[n]!=n)
        {
        v.pb(vis[n]);
            n/=vis[n];
        }
        if(n>1)
           v.pb(n);
        return v;
}
int main()
{
    fast;
    seive();
    ll n,t;
    cin>>n;
    vector<ll>v=primefactor(n);
   for(auto xx:v)cout<<xx<<" ";
   cout<<endl;


}
