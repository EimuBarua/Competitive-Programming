#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define soja(i,a,n) for(ll i=a;i<=n;i++)
#define ulta(i,n,a) for(ll i=n;i>=a;i--)
#define pb push_back
vector<ll>a(10000000);
ll phi(ll n)
{
    soja(i,1,n)
    a[i]=i;
    soja(i,2,n)
    {
        if(a[i]==i)
        {

        for(ll j=i;j<=n;j+=i)
        {
            //phi(n)=n*((p1-1)/p1)*((p2-1)/p2).....
            a[j]=(a[j]*(i-1))/i;
        }
        }
    }
}
int main()
{
    ll n,m,k,t,sum=0;
    cin>>n;
    phi(n);
    soja(i,1,n)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
