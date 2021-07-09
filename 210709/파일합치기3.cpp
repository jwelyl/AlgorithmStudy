#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int T;cin>>T;
  while(T--){
    int N; cin>>N;
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    for(int i=0; i<N; i++){
      int n; cin>>n; pq.push(n);
    }
    ll sum=0,n1,n2;
    while(pq.size()>1){
      n1=pq.top(); pq.pop();
      n2=pq.top(); pq.pop();
      pq.push(n1+n2);sum+=(n1+n2);
    }
    cout<<sum<<'\n';
  }
}
