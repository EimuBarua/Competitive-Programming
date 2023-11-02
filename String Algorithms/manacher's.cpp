/// use for all kind of palindrom related problems
#include<bits/stdc++.h>
using namespace std;
#define ll  long long int
#define soja(i,a,n) for(ll i=a;i<=n;i++)
#define ulta(i,n,a) for(ll i=n;i>=a;i--)
#define pb push_back
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(NULL)
const ll mx=2e6;
ll p[mx+5]; /// for the palindrome count
string hh; /// string with #
void manachers(string ss)
{
    string s;
    s.pb('#'); /// inserting # in the middle of charctes;
    soja(i,0,ss.size()-1)
    {
        s.pb(ss[i]);
        s.pb('#');

    }
    hh=s;
    soja(i,0,s.size())p[i]=1;
    ll l=1,r=1;
    soja(i,1,s.size()-1)
    {
        p[i]=max(0LL,min(r-i,p[l+r-i]));
        while((i+p[i])<s.size()&&(i-p[i])>=0&&s[i+p[i]]==s[i-p[i]])
       p[i]++;
       if((i+p[i])>r)
       {
        l=i-p[i];
        r=i+p[i];

       }
    }
//    soja(i,0,s.size()-1)
//    cout<<s[i]<<" ";
//    cout<<endl;


}
ll getlongest(int cen,bool odd) /// if there is element in centre there will char in centre otherwise #
{
    ll pos=2*cen+1+(!odd);
    return p[pos]-1;

}
bool checkpalin(ll l,ll r)
{
    if((r-l+1)<=getlongest((l+r)/2,l%2==r%2)) /// if both parity is same it will have odd length  len(2,4) == 3
    return true;
    else
    return false;

}
int main()
{
		fast;
		ll n,m,k,t,sum=0,x,y,q;
        string s; //babbabbabc
        cin>>s;
        manachers(s);
        ll index=0;
        soja(i,0,(ll)hh.size()-1)
        {
            if(sum<p[i])
            {
                index=i;
                sum=p[i];
            }
        }
        //substr()
        s=hh.substr(index-sum+1,sum*2-1);
        soja(i,0,s.size()-1)
        {
            if(s[i]=='#')continue;
            cout<<s[i];
        }
        cout<<"\n";
 		return 0;

}
