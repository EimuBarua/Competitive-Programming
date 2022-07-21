// KMP for substring search 
// complexity O(n+m) sizeof text and pattern

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define soja(i,a,n) for(ll i=a;i<=n;i++)
#define ulta(i,n,a) for(ll i=n;i>=a;i--)
#define pb push_back
const ll mx=2e5;//size of pattern string
ll lps[mx+5];
void temparray(string pattern)//making lps array with suffix and prefix match
{
    ll index=0;
    for(ll i=1;i<pattern.size();i++)
    {
        if(pattern[i]==pattern[index])
        {
            lps[i]=++index;
        }
        else
        {
            if(index!=0)
            {index=lps[index-1];
            i--;}
        }
    }
}
bool kmp(string text,string pattern)
{
    ll index=0;
    for(ll i=0;i<text.size();i++)
    {
        if(text[i]==pattern[index])
            index++;
        else
        {
            if(index!=0)
            {
                index=lps[index-1];
                i--;
            }
        }
        if(index==pattern.size())
            {cout<<i-pattern.size()+1<<" "<<i<<endl;
       // index=lps[index-1]; do this for occurences 
            return true;//it is found in the ith index of the text
         }
    }
    return false;// not found
}
int main()
{
    ll n,m,k,t,sum=0,x,y,now;
    string text,pattern;
    cin>>text>>pattern;
    temparray(pattern);
   	// soja(i,0,pattern.size()-1)
   	// cout<<lps[i]<<" ";
   	// cout<<endl;
    if(kmp(text,pattern))
        cout<<"Yes";
    else
        cout<<"NO";
    return 0;
}
