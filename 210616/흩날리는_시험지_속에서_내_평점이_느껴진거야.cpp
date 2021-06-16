#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> prefix;
int N,K;

bool check(int limit){
  int k=0, prev=0;
  while(k<K){
    int n=lower_bound(prefix.begin(),prefix.end(),limit+prev)-prefix.begin();
    if(n<prefix.size())
      prev=prefix[n];
    else return false;
    k++;
  }
  return true;
}

int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin>>N>>K;
  int n; cin>>n; prefix.push_back(n);
  for(int i=1; i<N; i++){
    int n; cin>>n;
    prefix.push_back(prefix.back()+n);
  }
  int lo=0, hi=prefix.back()+1;
  
  while(lo+1<hi){
    int mid=(lo+hi)/2;
    if(check(mid))lo=mid;
    else hi=mid;
  }
  cout<<lo;
}
