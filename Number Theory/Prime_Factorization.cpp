#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define soja(i,a,n) for(ll i=a;i<=n;i++)
#define ulta(i,n,a) for(ll i=n;i>=a;i--)
#define pb push_back
vector<ll>prime;
void seive()
{
    ll n=1e7;
    vector<bool>vis(n,0);
    for(ll i=3;i*i<=n;i+=2)
    {
        if(vis[i]==0)
        {
        for(ll j=i*i;j<n;j+=2*i)
        vis[j]=1;}
    }
    prime.pb(2);
    for(ll i=3;i<n;i+=2)
    {
        if(vis[i]==0)
            prime.pb(i);
    }
}
ll primefactor(ll n,vector<ll>&a)
{
    seive();
    ll m=sqrt(n);
    soja(i,0,prime.size()-1)
    {
        while(n%prrime[i]==0)
        {
            a.pb(prime[i]);
            n/=prime[i];
        }
        if(n==1||prime[i]>m)
            break;
            m=sqrt(n);
    }
    if(n>1)
        a.pb(n);
}
int main()
{
    ll n;
    vector<ll>a;
    cin>>n;
    primefactor(n,a);
    soja(i,0,a.size()-1)
    cout<<a[i]<<" ";
}

