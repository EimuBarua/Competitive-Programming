#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define soja(i,a,n) for(ll i=a;i<=n;i++)
#define ulta(i,n,a) for(ll i=n;i>=a;i--)
#define pb push_back
const ll inf =1e18;
ll n,m,k,t,sum=0,node,edge,cost,src,minnode,u,w;
vector<pair<ll,pair<ll,ll>>>adj;
ll dis[100005];
ll par[100005];
void bellmanford(ll src)
{
        soja(i,1,node)
        {dis[i]=inf;
        par[i]=-1;
        }
        dis[src]=0;
        ll xx;
        /// n-1 time for short dis and nth time for neg cycle detect
        soja(j,1,node)
        {
            xx=-1;
            soja(i,0,edge-1)
            {
                ll x=adj[i].first,y=adj[i].second.first,cost=adj[i].second.second;
                   
                    if(dis[x]<inf&&(dis[x]+cost)<dis[y])
                    {
                    par[y]=x;
                    dis[y]=max(-inf,dis[x]+cost);/// because of negative cycle it can have negative overflow
                    xx=y;
                     }
                      
            }
        }
            if(xx==-1)
            {
                cout<<"No Negative Cycle"<<endl;
                soja(i,1,node)
                    {
                         cout<<"Distance from "<<src<<" to "<<i<<" = ";
                        cout<<dis[i]<<" "<<endl;
                    }
            }
           else
           {
                ll y=xx;//it will go into the cycle after n times back
                soja(i,1,node)
                y=par[y];
               vector<ll>path;
               for(ll cur=y;;cur=par[cur])
               {
                path.pb(cur);
                if(cur==y&&path.size()>1)
                    break;
               }
               reverse(path.begin(),path.end());
               cout<<"Negative Cycle: "<<endl;
               soja(i,0,path.size()-1)
               {
                cout<<path[i]<<" ";
               }
               
           }


}

int main()
{
    cin>>node>>edge;
    src=1;
    soja(i,0,edge-1)
    {
        cin>>n>>m>>cost;
    adj.pb({n,{m,cost}});
    }

    bellmanford(src);
}


/*


7 10
1 2 6
1 3 5
1 4 5
2 5 -1
3 2 -2
3 5 1
4 3 -2
4 6 -1
5 7 3
6 7 3


4 5
3 2 -10
4 3 3
1 4 5
1 2 4
2 4 5

*/
