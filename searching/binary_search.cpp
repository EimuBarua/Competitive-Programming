#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define soja(i,a,n) for(ll i=a;i<=n;i++)
#define ulta(i,n,a) for(ll i=n;i>=a;i--)
#define pb push_back
vector<ll>v;
ll bin_search(ll n,ll m)
{
    ll l=0,r=n-1,mid;
    bool fg=0;
    while(1)
    {
            mid=(l+r)/2;
        if(v[mid]==m)
        {fg=1;
            break;}
        if(l>r)
            break;
        if(v[mid]>m)
        {
            r=mid-1;
        }
        else
            l=mid+1;
        cout<<mid<<" "<<l<<endl;
    }
    if(fg)
        cout<<"Found"<<endl;
    else
        cout<<"NO"<<endl;
}
int main()
{
    ll n,m,k,t,sum=0;
    cin>>n;
    soja(i,1,n)
    {
        v.pb(i);

    }
 
    cin>>m;
    bin_search(n,m);
    return 0;
}
