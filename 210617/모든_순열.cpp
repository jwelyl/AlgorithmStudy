#include <iostream>
using namespace std;
int arr[10];
void recur(const int& N, int visit, int n=0){
  if(n==N){
    for(int i=0; i<N; i++)cout<<arr[i]<<" ";
    cout<<'\n';
    return;
  }
  for(int i=0; i<N; i++)if(!(visit&1<<i)){
    arr[n]=i+1;
    recur(N,visit|1<<i,n+1);
  }
}
int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int N;cin>>N;
  recur(N,0);
}

