#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define soja(i,a,n) for(ll i=a;i<=n;i++)
#define ulta(i,n,a) for(ll i=n;i>=a;i--)
#define pb push_back
ll n,m,k,t,sum=0,bag;
ll value[100000],weight[100000];
ll dp[1000][100005];
//elements*sizeofbag
ll f(ll i,ll p)
{
    if(i>n)
        return 0;
    if(dp[i][p]>0)
        return dp[i][p];
    ll res=f(i+1,p);
    if(p+weight[i]<=bag)
        res=max(res,value[i]+f(i+1,p+weight[i]));
        return dp[i][p]=res;

}
int main()
{
    cin>>n>>bag;
    soja(i,1,n)
    cin>>weight[i]>>value[i];
    cout<<f(1,0)<<endl;
    return 0;
}
