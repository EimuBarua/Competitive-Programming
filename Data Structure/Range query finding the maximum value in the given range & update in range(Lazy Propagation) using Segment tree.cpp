//Range query finding the maximum value in the given range & update in range(Lazy Propagation) using Segment tree
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define soja(i,a,n) for(ll i=a;i<=n;i++)
#define ulta(i,n,a) for(ll i=n;i>=a;i--)
#define pb push_back
ll a[100123],seg[100123],lazy[100123];
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

ll check(ll x,ll y,ll index,ll qx,ll qy)
{
    if(x>=qx&&y<=qy)
        return seg[index];
    if(y<qx||x>qy)
        return INT_MIN;
        ll k=(x+y)/2;
    ll sum=max(check(x,k,index*2+1,qx,qy),check(k+1,y,index*2+2,qx,qy));
    return sum;
}
void update(ll x,ll y,ll qx,ll qy,ll index,ll c)
{
   seg[index]+=lazy[index];
   if(x!=y)
    {lazy[index*2+1]+=lazy[index];
    lazy[index*2+2]+=lazy[index];
    }
        lazy[index]=0;
    if(y<qx||x>qy)
        return ;
    if(x>=qx&&y<=qy)
         {seg[index]+=c;
         if(x!=y)
         {lazy[index*2+1]+=c;
         lazy[index*2+2]+=c;
         }
         return;
         }
        ll k=(x+y)/2;
   update(x,k,qx,qy,index*2+1,c);
   update(k+1,y,qx,qy,index*2+2,c);
    seg[index]=max(seg[index*2+1],seg[index*2+2]);
}
int main()
{
    ll n,m,k,t,sum=0,x,y,q,c;
    cin>>n;
    soja(i,0,n-1)
    cin>>a[i];
   cin>>t;
   build(0,n-1,0);
   while(t--)
   {
       cin>>q>>x>>y;
       if(q==1)
       cout<<check(0,n-1,0,x-1,y-1)<<endl;
       else
       {
           cin>>c;
        update(0,n-1,x-1,y-1,0,c);
       }
   }

    return 0;
}
