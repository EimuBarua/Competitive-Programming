//Range query finding the maximum value in the given range using Segment tree
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define soja(i,a,n) for(ll i=a;i<=n;i++)
#define ulta(i,n,a) for(ll i=n;i>=a;i--)
#define pb push_back
ll a[100123],seg[100123];
void build(ll x,ll y,ll index)
{
    ll k=(x+y)/2;
    if(x==y)
        {seg[index]=a[x];
        return;}
   build(x,k,index*2+1);
   build(k+1,y,index*2+2);
   seg[index]=max(seg[index*2+1],seg[index*2+2]);
}

ll q(ll x,ll y,ll index,ll qx,ll qy)
{
    if(x>=qx&&y<=qy)
        return seg[index];
    if(y<qx||x>qy)
        return INT_MIN;
        ll k=(x+y)/2;
    ll sum=max(q(x,k,index*2+1,qx,qy),q(k+1,y,index*2+2,qx,qy));
    return sum;
}
int main()
{
    ll n,m,k,t,sum=0,x,y;
    cin>>n;
    soja(i,0,n-1)
    cin>>a[i];
   cin>>t;
   build(0,n-1,0);
   while(t--)
   {
       cin>>x>>y;
       cout<<q(0,n-1,0,x,y)<<endl;
   }

    return 0;
}
