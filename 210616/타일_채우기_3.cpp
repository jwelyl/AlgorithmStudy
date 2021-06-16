#include <iostream>
using namespace std;
const int MAX=1000001;
const int MOD=1000000007;
long long dp[MAX], extra[MAX];
int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int N; cin>>N;
  dp[1]=2; dp[2]=7;
  extra[1]=1;
  for(int i=3; i<=N; i++){
    extra[i-1]=(dp[i-2]%MOD+extra[i-2]%MOD)%MOD;
    dp[i]=((3*dp[i-2]%MOD+2*dp[i-1]%MOD)%MOD+extra[i-2]*2%MOD)%MOD;
  }
  cout<<dp[N];
}
