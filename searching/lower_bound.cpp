#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define soja(i,a,n) for(ll i=a;i<=n;i++)
#define ulta(i,n,a) for(ll i=n;i>=a;i--)
#define pb push_back
vector<ll>v;
//finding lower bound
//lower bound is the left most index with value greater /equal to a particular number
ll lower_search(ll n,ll m)
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
    }
    return l;
}
int main()
{
    ll n,m,k,t,sum=0;
    cin>>n;
    soja(i,0,n-1)
{cin>>k;
v.pb(k);}
v.pb(0);
    cin>>m;
    k=lower_search(n,m);

    ulta(i,n,k+1)
    {
        v[i]=v[i-1];
    }
    v[k]=m;
    soja(i,0,v.size()-1)
    cout<<v[i]<<" ";
    cout<<endl;
    return 0;
}
