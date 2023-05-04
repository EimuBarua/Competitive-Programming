#include<bits/stdc++.h>
using namespace std;
#define ll  int
#define soja(i,a,n) for(ll i=a;i<=n;i++)
#define ulta(i,n,a) for(ll i=n;i>=a;i--)
#define pb push_back
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
ll ma[1000005];
int main()
{
    fast;
    ll n,m,k,t,sum=0;
    cin>>n;
    soja(j,1,n)
    {
        cin>>k;
        m=sqrt(k);
        soja(i,1,m)
        {
            if(k%i==0)
            {
                ma[i]++;
                if((k/i)!=i)
                    ma[k/i]++;
            }
        }
    }
    soja(i,1,1e6)
    {
        if(ma[i]>=2)sum=i;
    }
    cout<<sum<<endl;
 
 
}
