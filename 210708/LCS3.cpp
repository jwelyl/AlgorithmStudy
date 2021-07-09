#include <iostream>
#include <string>
using namespace std;

int dp[101][101][101];
int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  string src, dest, dest2; cin>>src>>dest>>dest2;
  for(int k=0; k<dest2.size(); k++)
    for(int i=0; i<dest.size(); i++)
      for(int j=0; j<src.size(); j++){
        if(dest[i]==src[j]&&src[j]==dest2[k])dp[i+1][j+1][k+1]=dp[i][j][k]+1;
        else {
            dp[i+1][j+1][k+1]=max(dp[i][j+1][k+1],dp[i+1][j][k+1]);
            dp[i+1][j+1][k+1]=max(dp[i+1][j+1][k+1],dp[i+1][j+1][k]);
        }
      }
  cout<<dp[dest.size()][src.size()][dest2.size()];
}


