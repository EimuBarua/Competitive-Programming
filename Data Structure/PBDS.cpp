//help https://ideone.com/EeV7L0
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long int
#define soja(i,a,n) for(ll i=a;i<=n;i++)
#define ulta(i,n,a) for(ll i=n;i>=a;i--)
#define pb push_back
/*******  
*s.find_by_order(i) ith index from 0
s.order_of_key(k) values stricly less than k
s.size() - s.order_of_key(k) values greater equal than k  
 ****************/
template<class T> using oset= tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;///ascending
template<class T> using ooset= tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;///duplicate values count
int main()
{
    ll n,m,k,t,sum=0;
    ooset<ll>s;
    cin>>n;
    soja(i,0,n-1)
    {cin>>k;
    s.insert(k);}
    k=*s.find_by_order(1);
    cout<<s.order_of_key(2)<<endl;
   cout<<k<<endl;
}
