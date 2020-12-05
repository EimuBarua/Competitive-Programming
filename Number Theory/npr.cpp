#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define soja(i,a,n) for(ll i=a;i<=n;i++)
#define ulta(i,n,a) for(ll i=n;i>=a;i--)
#define pb push_back
ll mod=1e9+7;
vector<ll>factor(10000005);
ll bigmod(ll n,ll m)
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
void facto()
{
    factor[0]=1;
    soja(i,1,10000000)
    {
        factor[i]=(factor[i-1]%mod)*(i%mod);
        factor[i]%=mod;
    }
}
int main()
{
    facto();
    ll n,m,k,r,sum;
    cin>>n>>r;
    //npr=n!/((n-r)!)
        k=(factor[n-r]%mod);
        k%=mod;
        k=bigmod(k,mod-2);
        k%=mod;
    k*=(factor[n]%mod);
    k%=mod;
    cout<<k<<endl;

}
