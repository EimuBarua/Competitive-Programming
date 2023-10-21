#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define soja(i,a,n) for(ll i=a;i<=n;i++)
#define ulta(i,n,a) for(ll i=n;i>=a;i--)
#define pb push_back
const int mx = 1e6+5;

ll a[mx], res[mx], fre[mx], n, q, block,sum=0; /// MO's finding the distinct elements in the given range  O((q+n)sqrt(n))

struct Query{
    ll index, left, right;
    bool operator<(const Query& x){
        return left/block < x.left/block ||
        (left/block == x.left/block && right<x.right);
    }
}query[mx];


void add(ll x){
    fre[a[x]]++;
    if(fre[a[x]]==1)
        sum++;
}
void del(ll x){
    fre[a[x]]--;
    if(fre[a[x]]==0)
       sum--;
}
int main()
{
    cin>>n;

   soja(i,1,n)cin>>a[i];

    block = sqrt(n);

    cin>>q;

   soja(i,1,q){
        cin>>query[i].left>>query[i].right;
        query[i].index = i;
    }

    sort(query+1, query+q+1);

    int curl = 1, curr = 0;
    sum=0;

   soja(i,1,q){
        ll index = query[i].index;
        ll l = query[i].left;
        ll r = query[i].right;
        while(curl<l)
            del(curl++);
        while(curl>l)
            add(--curl);
        while(curr<r)
            add(++curr);
        while(curr>r)
            del(curr--);
        res[index] = sum;
    }

    soja(i,1,q){
        cout<<res[i]<<"\n";
    }
    return 0;
}
