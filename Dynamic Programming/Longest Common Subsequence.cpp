#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define soja(i,a,n) for(ll i=a;i<=n;i++)
#define ulta(i,n,a) for(ll i=n;i>=a;i--)
#define pb push_back
ll dp[3005][3005];
int main()
{
    ll n,m,k,t,sum=0;
    string a,b;
    cin>>a>>b;
    n=a.size();
    m=b.size();
    soja(i,0,n-1)
    {
        soja(j,0,m-1)
        {

            if(a[i]==b[j])
                dp[i+1][j+1]=dp[i][j]+1;
                else
            dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
        }
    }
    string res;
    while(1)
    {
        if(n==0||m==0)
        break;
        if(dp[n][m]==dp[n][m-1])
        m--;
        else if(dp[n][m]==dp[n-1][m])
            n--;
        else
            {res.pb(a[n-1]);
        n--,m--;}

    }
    ulta(i,res.size()-1,0)
    cout<<res[i];
    cout<<endl;
    return 0;
}
