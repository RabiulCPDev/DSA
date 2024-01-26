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

int dp[3003][3003];

string funn(string s,string t){
    for(int i=0;i<s.size()+1;i++){
        for(int j=0;j<t.size()+1;j++)
        {
          if(i==0 || j==0) dp[i][j]=0;
          else if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1]+1;
          else{
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
          }
        }
    }
    string ans;
    int i=s.size(),j=t.size();
    while (i>0 && j>0)
    {
        if(s[i-1]==t[j-1]){
            ans.pb(s[i-1]);
            i--;
            j--;
        }else{
            if(dp[i-1][j]>dp[i][j-1]) i--;
            else{
                j--;
            }
        }
    }
    
   return ans;
}

 
void solve()
{
    string s,t;
    cin>>s>>t;
    
   string ans= funn(s,t);
   reverse(ans.begin(),ans.end());
   cout<<ans<<endl;
  
    
    
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

