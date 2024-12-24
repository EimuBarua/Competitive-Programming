//Range query finding the sum in the given range & update in range(Lazy Propagation) using Segment tree
#include<bits/stdc++.h>
using namespace std;
#define ll  long long int
#define soja(i,a,n) for(ll i=a;i<=n;i++)
#define ulta(i,n,a) for(ll i=n;i>=a;i--)
#define pb push_back
#define endl "\n"
const ll mx=2e5+5;
ll a[mx],seg[10*mx],lazy[10*mx];   //4*array size
void build(ll x,ll y,ll index)
{
    ll k=(x+y)/2;
    if(x==y)
        {seg[index]=a[x];
        return;}
   build(x,k,index*2);
   build(k+1,y,index*2+1);
   seg[index]=seg[index*2]+seg[index*2+1];
}

ll check(ll x,ll y,ll index,ll qx,ll qy)
{
    seg[index]+=lazy[index];
    lazy[index*2] += lazy[index];
    lazy[index*2+1] += lazy[index];
    lazy[index] = 0;
    if(x>=qx&&y<=qy)
    {
   //  cout<<x<<" tttt "<<y<<endl;
        return seg[index];

    }
    if(y<qx||x>qy)
        return 0;
        ll k=(x+y)/2;
    ll sum=check(x,k,index*2,qx,qy)+check(k+1,y,index*2+1,qx,qy);
    return sum;
}
void update(ll x,ll y,ll qx,ll qy,ll index,ll c)
{
   seg[index]+=lazy[index];
   if(x!=y)
    {lazy[index*2]+=lazy[index];
    lazy[index*2+1]+=lazy[index];
    }
        lazy[index]=0;
    if(y<qx||x>qy)
        return ;
    if(x>=qx&&y<=qy)
         {seg[index]+=c;
         if(x!=y)
         {lazy[index*2]+=c;
         lazy[index*2+1]+=c;
         }
         return;
         }
        ll k=(x+y)/2;
   update(x,k,qx,qy,index*2,c);
   update(k+1,y,qx,qy,index*2+1,c);
    seg[index]=seg[index*2]+seg[index*2+1];
}
int main()
{

    ll n,m,k,t,sum=0,x,y,q,c;
    cin>>n>>t;
    soja(i,1,n)
    cin>>a[i];
   build(1,n,1);
   while(t--)
   {
       cin>>q>>x>>y;
       if(q==2)
       {
       cout<<check(1,n,1,x,y)<<endl;
       }
       else
       {
           cin>>y>>c;
        update(1,n,x,y,1,c);
       }
   }

    return 0;
}
