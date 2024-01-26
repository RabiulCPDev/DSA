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
int wt[MAX];
int val[MAX];

ll fun(int w,int n){
        if(w==0) return 0;
        if(n<0) return 0;
        
        if(dp[n][w]!=-1) return dp[n][w];
        ll ans=fun(w,n-1);
        if(w>=wt[n]){
            ans=max(ans,val[n]+fun(w-wt[n],n-1));
        }
        return dp[n][w]=ans;
    }


void solve()
{
    int n,w;
    cin>>n>>w;
    for(int i=0;i<n;i++)
    {
        cin>>wt[i]>>val[i];
    }
    memset(dp,-1,sizeof(dp));
   cout<< fun(w,n-1)<<endl;
    
    
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

