#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define soja(i,a,n) for(ll i=a;i<=n;i++)
int main()
{
    ll node,edge,a,b,k;
    cin>>node>>edge>>k;
    vector<vector<bool>> adj(node+1 , vector<bool> (node+1, 0));
    soja(i,0,edge-1)
    {
        cin>>a>>b;
        adj[a][b]=1;
        adj[b][a]=1;
    }
        soja(j,0,node-1)
        {
if(adj[k][j]==1)
            cout<<j<<" ";
        }
        cout<<endl;

}
