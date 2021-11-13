#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define soja(i,a,n) for(ll i=a;i<=n;i++)
#define ulta(i,n,a) for(ll i=n;i>=a;i--)
#define pb push_back
ll par[100005];
ll ran[100005];
void make_set(ll n)
{
    soja(i,1,n)
        {par[i]=i;
        ran[i]=0;}
}
ll find_set(ll x)
{
    if(par[x]==x)
        return x;
    return par[x]=find_set(par[x]);
}
void uni(ll x,ll y)
{
    x=find_set(x);
    y=find_set(y);
    if(x!=y)
    {
        if(ran[x]==ran[y])
        {
        ran[x]++;
        par[y]=x;
        }
        else if(ran[x]>ran[y])
            par[y]=x;
        else
            par[x]=y;

    }
}
int main()
{
    ll n,m,k,t,sum=0,x,y;
    /// number of  elements
    scanf("%lld",&n);
    make_set(n);
    
    return 0;
}
