#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
long long sum[1000001];
int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  unordered_map<int,long long> hm;
  int N,M; cin>>N>>M;
  for(int i=1; i<=N; i++){
    int n; cin>>n; sum[i]=(sum[i-1]%M+n%M)%M;
    hm[sum[i]]++;
  }
  long long ans=hm[0];
  for(int i=0; i<1000; i++)if(hm[i]>1){
    ans+=(hm[i]*(hm[i]-1))/2;
  }
  cout<<ans;
}
