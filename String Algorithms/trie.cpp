
/// trie can work with prefix for searchig number of prefix and strings
// searching and inserting complexity O(string size)
#include<bits/stdc++.h>
using namespace std;
#define ll  long long int
#define soja(i,a,n) for(ll i=a;i<=n;i++)
#define ulta(i,n,a) for(ll i=n;i>=a;i--)
#define pb push_back
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(NULL)

ll mod=1e9+7;
struct node{
	ll words,prefixs;
	node* edges[30];
	node()
	{
		words=0;
		prefixs=0;
		for(ll i=0;i<26;i++)
			edges[i]=NULL;
	}
}*root;
void insertstring(string s)
{
	node* curr=root;// starting from the root node
	for(ll i=0;i<s.size();i++)
	{
		ll val=s[i]-'a';
		if(curr->edges[val]==NULL)// if no edges is there
			curr->edges[val]=new node(); //create new node 
		curr= curr->edges[val]; //going to the next node 
		curr->prefixs++;
	}
	curr->words++;// if the the string traverse is finish mark the last node endmark as 1
}
ll searchwords(string s)
{
	node* curr=root;// starting from the root node
	for(ll i=0;i<s.size();i++)
	{
		ll val=s[i]-'a';
		if(curr->edges[val]==NULL)// if no edges is there
			return 0; //string traverse in not complete send false
		curr= curr->edges[val]; //going to the next node 
	}
	return curr->words;// if the last node endmark is 1 then the string is found
}
ll searchprefix(string s)
{
	node* curr=root;// starting from the root node
	for(ll i=0;i<s.size();i++)
	{
		ll val=s[i]-'a';
		if(curr->edges[val]==NULL)// if no edges is there
			return 0; //string traverse in not complete send false
		curr= curr->edges[val]; //going to the next node 
	}
	return curr->prefixs;// if the last node endmark is 1 then the string is found
}

void del(node* curr)// destroing the trie after every test case
{
	for(int i=0;i<26;i++)
	{
		if(curr->edges[i])
			del(curr->edges[i]);
	}
	delete(curr);
}
int main()
{
		fast;
		root=new node();
		ll n,m,k,t,sum=0,q;
			string s;
		cin>>n;// number of words;
		soja(i,1,n)
		{
			cin>>s;
			insertstring(s);//inserting into trie;
		}
		cin>>q;//query for search the words
		soja(i,1,q)
		{
			cin>>s;
			cout<<searchwords(s)<<endl;
			cout<<searchprefix(s)<<endl;
		}
		del(root);//destroing trie

 		return 0;

}
