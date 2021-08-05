#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define soja(i,a,n) for(ll i=a;i<=n;i++)
#define ulta(i,n,a) for(ll i=n;i>=a;i--)
#define pb push_back
ll a[25][25],dp[30][1<<20];
ll n;
ll f(ll x,ll mask)
{
    if(x>n)
        return 0;
    if(dp[x][mask]!=-1)
        return dp[x][mask];
    dp[x][mask]=1e18;
    soja(i,0,n-1)
    {
        if(mask&(1<<i))///check the bit is on or not
        {
            ll k=mask^(1<<i);///removing the bit
            dp[x][mask]=min(dp[x][mask],a[x][i+1]+f(x+1,k));
        }
    }
    return dp[x][mask];
}
int main()
{
    cin>>n;
    soja(i,1,n)
    {
        soja(j,1,n)
        {
            cin>>a[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));
    cout<<f(1,(1<<n)-1)<<endl;
}
