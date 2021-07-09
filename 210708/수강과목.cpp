#include <iostream>
using namespace std;
int priority[1003], tim[1003];
int dp[1002][10003];
int N,K, ans;
int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin>>N>>K;
  for(int i=1; i<=K; i++){
    cin>>priority[i]>>tim[i];
  }
  for(int i=1; i<=K; i++){
    for(int j=0; j<=N; j++)if(j-tim[i]>=0){
      dp[i][j]=max(dp[i-1][j],dp[i-1][j-tim[i]]+priority[i]);
    }
    for(int j=0; j<=N; j++)dp[i+1][j]=dp[i][j];
  }
  cout<<dp[K][N];
}
