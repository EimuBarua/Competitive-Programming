#include<bits/stdc++.h>
using namespace std;
#define ll int
#define soja(i,a,n) for(ll i=a;i<=n;i++)
#define ulta(i,n,a) for(ll i=n;i>=a;i--)
#define pb push_back
#define line cout<<"\n"
void debugg(){cout<<"##Debug ";}
template<typename T>void print(T x){cout<<x<<" ";}
template<typename T> void debug(T x){debugg();print(x);line;}
template<typename T> void debug(T a,T b){debugg();print(a);print(b);line;}
template<typename T> void debug(T a,T b,T c){debugg();print(a);print(b);print(c);line;}
template<typename T> void debug(T a,T b,T c,T d){debugg();print(a);print(b);print(c);print(d);line;}
template<typename T> void debugarray(T v,ll n){debugg();soja(i,0,n-1)print(v[i]);line;}
ll a[1001],b[1001];
ll dp[1002][100002];
 
int main()
{
    ll n,m,k,t,sum=0;
    cin>>n>>m;/// m = maximum weight
    soja(i,1,n)
    cin>>a[i];///weight array
    soja(i,1,n)
    cin>>b[i];///value array
    soja(i,1,n)
    {
        soja(j,0,m)
        {
            if(j>=a[i])
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-a[i]]+b[i]);
            else
                dp[i][j]=dp[i-1][j];
        }
    }
   cout<<dp[n][m];
    line;
    return 0;
}
