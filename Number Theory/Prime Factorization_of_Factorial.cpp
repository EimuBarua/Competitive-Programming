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
                vis[j]=1;
        }
    }
    prime.pb(2);
    for(ll i=3;i<n;i+=2)
    {
        if(vis[i]==0)
            prime.pb(i);
    }
}
ll primefactoroffactorization(ll n,vector<ll>&a)
{
    seive();

    soja(i,0,prime.size()-1)
    {
        if(prime[i]>n)
            break;
            ll x=n;
        while(1)
        {
            if(x/prime[i]==0)
            break;
            soja(j,1,x/prime[i])
            a.pb(prime[i]);
            x=x/prime[i];
        }
    }
}
int main()
{
    ll n;
    cin>>n;
    vector<ll>a;

    primefactoroffactorization(n,a);
    soja(i,0,a.size()-1)
    cout<<a[i]<<" ";
    cout<<endl;


}

