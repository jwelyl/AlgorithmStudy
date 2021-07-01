#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
int N,M;
ll dp[11][2001];
ll ans=0;

ll recur(int n, int curr){
  ll &res= dp[n][curr];
  if(res!=-1)return res;
  res=0;
  int t=2*curr;
  if(n==1)t=1;
  if(n==N){
	  if(M>=t)
	  	return res=M-t+1;
	  else return 0;
  }
  for(int i=t; i<=M; i++){
    ll temp=recur(n+1,i);
    if(temp==0)break;
    res += temp;
  }
  return res;
}

int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int T;cin>>T;
  while(T--){
    ans=0;
    memset(dp,-1,sizeof(dp));
    cin>>N>>M;
    recur(1,1);
    for(int i=1; i<=M; i++)if(dp[1][i]>0)ans+=dp[1][i];
    cout<<ans<<'\n';
  }
}