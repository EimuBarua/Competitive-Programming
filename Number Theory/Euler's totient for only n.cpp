#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define soja(i,a,n) for(ll i=a;i<=n;i++)
#define ulta(i,n,a) for(ll i=n;i>=a;i--)
#define pb push_back
vector<ll>prime;
void seive()
{
    vector<bool>vis(10000000,0);
    for(ll i=3;i*i<=10000000;i+=2)
    {
        if(vis[i]==0)
        {
            for(ll j=i*i;j<10000000;j+=2*i)
                vis[j]=1;
        }
    }
    prime.pb(2);
    for(ll i=3;i<10000000;i+=2)
    {
        if(vis[i]==0)
        {
            prime.pb(i);
        }
    }
}
int main()
{
    seive();
    ll n,m,k,t,sum=0;
    cin>>n;
    k=n;
    soja(i,0,prime.size()-1)
    {
        if(prime[i]>sqrt(n)||n==1)
            break;

        if(n%prime[i]==0)
        {
            k=(k*(prime[i]-1))/prime[i];
            while(1)
            {
                if(n%prime[i]!=0)
                    break;
            n/=prime[i];
            }
        }
    }
if(n>1)
k=(k*(n-1))/n;
    cout<<k<<endl;
    return 0;
}
