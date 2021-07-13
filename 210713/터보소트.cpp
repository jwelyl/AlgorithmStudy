#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX=1<<17;
typedef pair<int,int> p;
int arr[MAX], idx[MAX];

void update(int n, int v){
  while(n<MAX){
    arr[n]+=v;
    n+=n&-n;
  }
}
int sum(int n){
  int res=0;
  while(n){
    res+=arr[n];
    n-=n&-n;
  }
  return res;
}

int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int N; cin>>N;
  for(int i=1; i<=N; i++){
    int n; cin>>n;
    idx[n]=i; update(i,1);
  }
  int f=1, l=N;
  while(f<l){
    int id=idx[f++], id2=idx[l--];
    update(id,-1);cout<<sum(id)<<'\n';
    update(id2,-1);cout<<sum(N)-sum(id2)<<'\n';
  }
  if(f==l)cout<<0;
}
