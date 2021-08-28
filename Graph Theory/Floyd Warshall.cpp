#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define soja(i,a,n) for(ll i=a;i<=n;i++)
#define ulta(i,n,a) for(ll i=n;i>=a;i--)
#define pb push_back
///(Floyd Warshall)For Directed Graph
const ll inf=1e16;
ll node,edge,x,y,cost;
ll dp[1000][1000];
void floyd()
{
    soja(z,1,node)
    {
    soja(i,1,node)
    {
        soja(j,1,node)
        dp[i][j]=min(dp[i][j],dp[i][z]+dp[z][j]);///putting the element in middle
    }
    }
}
int main()
{
   cin>>node>>edge;
    soja(i,1,node)
    {
        soja(j,1,node)
            dp[i][j]=inf;
    }
    soja(i,0,edge-1)
    {
        cin>>x>>y>>cost;
        dp[x][x]=0;
        dp[x][y]=min(dp[x][y],cost);
    }
    floyd();

    soja(i,1,node)
    {
        soja(j,1,node)
        {
          cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }


}
