#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fr(s,n) for(int i=s;i<n;i++)
#define frr(n) for(int i=n-1;i>=0;i--)
#define pb push_back

const ll MAX = 1e5+5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

ll dp[101][MAX];
ll wt[MAX];
ll val[MAX];

ll fun(ll v,ll n){
        if(v==0) return 0;
        if(n<0) return 1e14;
        
        if(dp[n][v]!=-1) return dp[n][v];
        ll ans=fun(v,n-1);
        if(v>=val[n]){
            ans=min(ans,wt[n]+fun(v-val[n],n-1));
        }
        return dp[n][v]=ans;
    }


void solve()
{
    ll w;
    ll n;
    cin>>n>>w;
     memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        cin>>wt[i]>>val[i];
    }
   
    
    for(ll i=1e5+3;i>=0;--i)
    {
        ll a=fun(i,n-1);
        if(a<=w){
            cout<<i<<endl;
            break;
        }
    }   
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

