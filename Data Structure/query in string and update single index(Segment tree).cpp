#include<bits/stdc++.h>
using namespace std;
#define  ll long long int
#define soja(i,a,n) for(ll i=a;i<=n;i++)
#define ulta(i,n,a) for(ll i=n;i>=a;i--)
#define pb push_back
ll seg[1000000][26];
ll v[30];
string s;
void build(ll x,ll y,ll p)
{
    if(x==y)
    {
        seg[p][s[x]-'a']++;
        return;
    }
    ll k=(x+y)/2;
    build(x,k,p*2+1);
    build(k+1,y,p*2+2);
    soja(i,0,25)
        {
            if(seg[p*2+1][i]>0||seg[p*2+2][i]>0)
                seg[p][i]=1;
        }
}
void check(ll x,ll y,ll qx,ll qy,ll p)
{
    ll k=(x+y)/2;
    if((qy<x)||(y<qx))
        return;
    if(qx<=x&&qy>=y)
    {
        soja(i,0,25)
        {
            if(seg[p][i]>0)
                v[i]=1;
        }
        return;
    }
     check(x,k,qx,qy,p*2+1);
    check(k+1,y,qx,qy,p*2+2);
}
void update(ll x,ll y,ll qx,ll p ,char c)
{
    if(qx<x||qx>y)
        return;
   if(x==y)
    {
        ///cout<<x<<endl;
        seg[p][s[x]-'a']=0;
        s[x]=c;
        seg[p][c-'a']=1;
        return;
    }
    ll k=(x+y)/2;
    update(x,k,qx,p*2+1,c);
    update(k+1,y,qx,p*2+2,c);
    soja(i,0,25)
        {
            if(seg[p*2+1][i]>0||seg[p*2+2][i]>0)
                seg[p][i]=1;
            else
                 seg[p][i]=0;
        }
}
int main()
{
    ll n,m,k,t,sum=0,qx,qy,q;
    cin>>s;
    char c;
    build(0,s.size()-1,0);
    cin>>t;
    while(t--)
    {
        cin>>q;
        if(q==1)
        {cin>>qx>>c;
        update(0,s.size()-1,qx-1,0,c);

        }
        else
        {
            cin>>qx>>qy;
        memset(v,0,sizeof(v));
        check(0,s.size()-1,qx-1,qy-1,0);
        sum=0;
        soja(i,0,25)
            sum+=v[i];
            cout<<sum<<endl;
        }
    }
    return 0;
}
