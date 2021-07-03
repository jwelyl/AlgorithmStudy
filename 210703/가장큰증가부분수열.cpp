#include <iostream>
#include <algorithm>
using namespace std;
int N;
int arr[1001], dp[1001];

int recur(int n=0){
  int &res=dp[n];
  if(res!=-1)return res;
  
  res=arr[n];
  for(int i=n+1; i<N; i++)if(arr[n]<arr[i]){
    res=max(res,arr[n]+recur(i));
  }
  return res;
}

int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin>>N;
  fill(dp,dp+N,-1);
  for(int i=0; i<N; i++)cin>>arr[i];
  int ans=0;
  for(int i=0; i<N; i++)
    ans=max(ans,recur(i));
  cout<<ans;
}
