#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int N; cin>>N;
  priority_queue<int,vector<int>> pq;
  for(int i=0; i<N; i++){
    int n;cin>>n;
    if(n==0){
      if(!pq.empty()){
        n=pq.top();
        pq.pop();
      }
      cout<<n<<'\n';
    }
    else{
      pq.push(n);
    }
  }
}
