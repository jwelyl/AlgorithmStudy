#include <iostream>
#include <string>
using namespace std;
int dp[1001][1001];

int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  string src,dest; cin>>src>>dest;
  for(int j=0; j<dest.size(); j++)
    for(int i=0; i<src.size(); i++){
      if(dest[j]==src[i])dp[j+1][i+1]=dp[j][i]+1;
      else dp[j+1][i+1]=max(dp[j+1][i],dp[j][i+1]);
    }
  cout<<dp[dest.size()][src.size()];
}
