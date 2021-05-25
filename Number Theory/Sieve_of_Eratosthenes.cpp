#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define soja(i,a,n) for(ll i=a;i<=n;i++)
vector<ll>prime;
void seive()
{
   ll  n=10000000;
    vector<bool>vis(n,0);
    //all prime divisors of a number is before the square root of a number
    // 25 =5 prime divisors of 1 - 25  must be in 2 3 4 5
    for(ll i=3;i*i<=n;i+=2)
    {
        if(vis[i]==0)
        {
//i*i because there 3 =9 if we do i+i then 6 but it will be cut down already in time of 2
        //2*i we can skip the even number
        for(ll j=i*i;j<n;j+=2*i)
        {
            vis[j]=1;
        }
        }
    }
 prime.pb(2);
    for(ll i=3;i<=n;i+=2)
    {
        if(vis[i]==0)
            prime.pb(i);
    }

}
int main()
{
    ll n;
    seive();
    soja(i,0,prime.size()-1)
    cout<<prime[i]<<" ";
    cout<<endl;

return 0;
}
