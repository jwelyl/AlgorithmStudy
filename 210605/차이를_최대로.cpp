#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>temp;
int ans;
void permu(const int& N, const vector<int>& v, int visit){
  if(visit==((1<<N)-1)){
    int t=0;
    for(int i=0; i<N-1; i++)
      t+=abs(temp[i]-temp[i+1]);
    ans=max(t,ans);
    return;
  }

  for(int i=0; i<N; i++)if(!(visit&(1<<i))){
    temp.push_back(v[i]);
    permu(N,v,visit|1<<i);
    temp.pop_back();
  }
}

int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int N;cin>>N;
  vector<int> arr;
  for(int i=0; i<N; i++){
    int n; cin>>n;
    arr.push_back(n);
  }
  permu(N,arr,0);
  cout<<ans;
}

