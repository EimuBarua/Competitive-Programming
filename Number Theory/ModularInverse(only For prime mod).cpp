#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define soja(i,a,n) for(ll i=a;i<=n;i++)
#define ulta(i,n,a) for(ll i=n;i>=a;i--)
#define pb push_back
ll bigmod(ll n,ll m,ll mod)
{
    ll f=1;
    while(m)
    {
        if(m%2==1)
        {
            f*=(n%mod);
            f%=mod;
        }
        n*=(n%mod);
        n%=mod;
        m/=2;
    }
    return (f%mod+mod)%mod;
}
int main()
{
    ll n,m,k,sum,mod;
    cin>>n>>m>>mod;
    //(n/m)%mod
    sum=bigmod(m,mod-2,mod);
    n*=(sum%mod);
    n%=mod;
    cout<<n<<endl;
}
