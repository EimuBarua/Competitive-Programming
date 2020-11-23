int main()
{    ll node,edge,a,b; 
    cin>>node>>edge;  
    vector<vector<bool>> adj(node+1 , vector<bool> (node+1, 0)); 
   soja(i,0,edge-1) 
    {   
    cin>>a>>b;     
    adj[a][b]=1;   
    adj[b][a]=1;
    } 
soja(i,0,node-1)
        {       
    soja(j,0,node-1)    
    {    
    cout<<adj[i][j]<<" ";
    }
    cout<<endl;
    }
    return 0;
}
