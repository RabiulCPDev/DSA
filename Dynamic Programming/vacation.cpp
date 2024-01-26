#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fr(s,n) for(ll i=s;i<n;i++)

const ll MAX = 1e5+5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
ll ans=INT_MAX;
ll dp[MAX][4];
int h[MAX][4];
ll n;
int fun(int i,int state)
{
   int pnt=INT_MIN;
   if(i==n) return 0; 
   if(dp[i][state]!=-1) return dp[i][state];
   if(state==0){
      pnt=max(pnt,h[i][1]+fun(i+1,1));
      pnt=max(pnt,h[i][2]+fun(i+1,2));
   }else if(state==1){
      pnt=max(pnt,h[i][0]+fun(i+1,0));
      pnt=max(pnt,h[i][2]+fun(i+1,2));
   }else if(state==2){
      pnt=max(pnt,h[i][0]+fun(i+1,0));
      pnt=max(pnt,h[i][1]+fun(i+1,1));
   }else{
      pnt=max(pnt,h[i][0]+fun(i+1,0));
      pnt=max(pnt,h[i][2]+fun(i+1,2));
      pnt=max(pnt,h[i][1]+fun(i+1,1));
   }
   return dp[i][state]=pnt;
}

void solve()
{
   memset(dp,-1,sizeof(dp));
    ll k;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
      for(ll j=0;j<3;j++)
      {
       cin>>h[i][j]; 
      }
    }
    
   
    cout<<fun(0,3)<<endl;
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
