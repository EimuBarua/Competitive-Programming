#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    //leftmost value insert index
    //lower bound
    ll n,key;
    cin>>n>>key;
    ll a[n];
    bool fg=0;
    ll index=-1;
    for(ll i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
   ll lo=0,hi=n-1;
   ll mid;
   while(lo<=hi)
   {
       mid=(lo+hi)/2;
       if(a[mid]==key)
       {
           hi=mid-1;
       }
       else if(a[mid]<key)
       {
           lo=mid+1;
       }
       else if(a[mid]>key)
       {
           hi=mid-1;
       }

   }
   cout<<lo<<endl;
    return 0;
}
