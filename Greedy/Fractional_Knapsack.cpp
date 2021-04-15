#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define soja(i,a,n) for(ll i=a;i<=n;i++)
#define ulta(i,n,a) for(ll i=n;i>=a;i--)
#define pb push_back
ll weight[100005],cost[100005];
vector<pair<double,ll>>v;
double knapsack(ll n,ll container)
{
    double sum=0;
    sort(v.rbegin(),v.rend());
soja(i,0,n-1)
{
    if(container==0)
        break;
    if(container>=weight[v[i].second])
    {
        container-=weight[v[i].second];
        sum+=cost[v[i].second];
    }
    else
    {
        sum+=v[i].first*container;
        container=0;
    }

}
return sum;
}
int main(){
ll n,container;
cin>>n>>container;
soja(i,0,n-1)
cin>>cost[i]>>weight[i];
soja(i,0,n-1)
{
    v.pb({(double)cost[i]/(double)weight[i],i});
}
cout<<knapsack(n,container)<<endl;
    return 0;
}
