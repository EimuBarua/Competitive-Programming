#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define soja(i,a,n) for(ll i=a;i<=n;i++)
#define ulta(i,n,a) for(ll i=n;i>=a;i--)
#define pb push_back
ll dp[1000005];
const ll mod = 1e9+7;
int main()
{
    ll n,m,k,t,sum=0,lo,hi,mid,key,index=-1;;
    cin>>n;
    ll a[n];
   soja(i,0,n-1)
   cin>>a[i];
   vector<ll>v;
   v.pb(a[0]);
   soja(i,1,n-1)
   {
       if(v.back()<a[i])
        v.pb(a[i]);
       else
  {
      ll lower=lower_bound(v.begin(),v.end(),a[i])-v.begin();
    ///cout<<lower<<endl;
    v[lower]=a[i];
  }
   }

   cout<<v.size()<<endl;
   return 0;
}
