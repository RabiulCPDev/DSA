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
int fun(int i,int k)
{
   
   if(i==0) return 0;
    int cost=INT_MAX;
   if(dp[i]!=-1) return dp[i];
   for(int j=1;j<=k;j++){
      if(i-j>=0) cost = min(cost,fun(i-j,k)+abs(h[i]-h[i-j]));
   }
   return dp[i]=cost;
}

void solve()
{
   memset(dp,-1,sizeof(dp));
    ll n,k;
    cin>>n>>k;
    for(ll i=0;i<n;i++)
    {
      cin>>h[i]; 
    }
   
    cout<<fun(n-1,k)<<endl;
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
