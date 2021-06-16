#include <iostream>
using namespace std;

int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int N;cin>>N;
  for(int i=0; i<N-1; i++){
    if(i%2==0)cout<<1<<" ";
    else cout<<2<<" ";
  }
  if(N%2==0)cout<<2;
  else cout<<3;
}
