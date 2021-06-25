#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int G; cin>>G;
  long long n=1;
  unordered_map<long long,int> hm;
  vector<long long> v;
  while((n+1)*(n+1)-n*n<=G)n++;
  for(long long i=1; i<=n; i++)hm[i*i]=i;
  for(long long i=1; i<n; i++){
    long long temp = i*i+G;
    if(hm[temp]>0)v.push_back(hm[temp]);
  }
  if(v.size()==0)cout<<-1;
  else{
    for(auto i : v)cout<<i<<'\n';
  }
}
