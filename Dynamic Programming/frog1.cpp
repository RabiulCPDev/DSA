#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fr(s,n) for(ll i=s;i<n;i++)

const ll MAX = 1e5+5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
ll ans=INT_MAX;
ll dp[MAX];
int h[MAX];
int fun(int i)
{
   
   if(i==0) return 0;
    int cost=INT_MAX;
   if(dp[i]!=-1) return dp[i];
   cost =min(cost,fun(i-1)+abs(h[i]-h[i-1]));
   
   if(i>1) cost=min(cost,fun(i-2)+abs(h[i]-h[i-2]));
   dp[i]=cost;
   return dp[i];
}

void solve()
{
   memset(dp,-1,sizeof(dp));
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
      cin>>h[i]; 
    }
   
    cout<<fun(n-1)<<endl;
}

int main()
{
    int t=1;
   // cin>>t;
    while (t--)
    {
       solve();
    }
    return 0;
}
