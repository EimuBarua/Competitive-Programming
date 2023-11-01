#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define soja(i,a,n) for(ll i=a;i<=n;i++)
#define ulta(i,n,a) for(ll i=n;i>=a;i--)
#define pb push_back
vector<ll>prime;
void seive()
{
   ll  n=1e7;
    vector<bool>a(n,0);
    prime.pb(2);
    for(ll i=3;i*i<=n;i+=2)
    {
        if(a[i]==0)
        {

        for(ll j=i*i;j<n;j+=2*i)
            a[j]=1;}
    }
    for(ll i=3;i<n;i+=2)
    {
        if(a[i]==0)
            prime.pb(i);
    }
}
void segseive(ll l,ll r,vector<ll>&v)
{
    ll k;
    vector<bool>a(r-l+1,0);

    soja(i,0,prime.size()-1)
    {
        //because all prime divisors are before the sqrt(n)
        if(prime[i]>sqrt(r))
            break;
            k=l/prime[i];
            //l=20,k=20/3;k=6;k*=3;k=18 18<20 so (l%prime[i]) k++,then k=21
            if(l%prime[i]!=0)
                k++;

            k*=prime[i];
            if(k==prime[i])k+=prime[i];
        for(ll j=k;j<=r;j+=prime[i])
            a[j-l]=1;
    }
soja(i,0,a.size()-1)
{
    if(a[i]==0&&(i+l)>1)
    {
        v.pb(i+l);
    }
}
}
int main()
{
    seive();
ll l,r;
ll t;
vector<ll>v;
cin>>l>>r;
segseive(l,r,v);
soja(i,0,v.size()-1)
cout<<v[i]<<"\n";
}
