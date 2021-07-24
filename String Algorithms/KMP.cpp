#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define soja(i,a,n) for(ll i=a;i<=n;i++)
#define ulta(i,n,a) for(ll i=n;i>=a;i--)
#define pb push_back
int main()
{
    ll n,m,k,t,sum=0;
    string text,pattern;
    cin>>text>>pattern;
    n=text.size();
    ///making the failure array with prefix and suffix of the pattern
    m=pattern.size();
    ll fail[m+2];
    fail[0]=0;
    ll x=0;
    soja(i,1,m-1)
    {
        while(1)
        {
            if(pattern[x]==pattern[i])
            {
                fail[i]=x+1;
                x++;
                break;
            }
            else if(x==0)
                {
                    fail[i]=0;
                    break;
                    }
            else
                x=fail[x-1];
        }

    }
    ///KMP begins
        x=0;
        bool fg=0;
        ll y=0;
        while(1)
        {
            if(y==m)
            {
                fg=1;
                break;
            }
            if(x==n)
                break;
            if(text[x]==pattern[y])
            {
                x++,y++;
            }
            else
            {
                if(y==0)
                    x++;
                else
                    y=fail[y-1];
            }
        }
    if(fg)
    {
        cout<<"YES\n";
        cout<<x-m<<" "<<x-1<<endl;
    }
    else
    {
        cout<<"NO";
    }
    return 0;
}
