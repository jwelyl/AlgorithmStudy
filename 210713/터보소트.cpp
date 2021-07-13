#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX=1<<18;
typedef pair<int,int> p;
vector<p> arr;
int seg[MAX], S=MAX/2;
void update(int n){
  while(n>1){
    n/=2;
    seg[n]=seg[n*2]+seg[n*2+1];
  }
}
int sum(int s, int e, int n, int ss, int ee){
  if(e<ss||ee<s)return 0;
  if(s<=ss&&ee<=e)return seg[n];
  int mid=(ss+ee)/2;
  return sum(s,e,n*2,ss,mid)+sum(s,e,n*2+1,mid+1,ee);
}
int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int N; cin>>N;
  for(int i=0; i<N; i++){
    seg[S+i]=1;
    int n; cin>>n; arr.push_back({n,i});
  }
  for(int i=S-1; i>0; i--)seg[i]=seg[i*2]+seg[i*2+1];
  sort(arr.begin(),arr.end());
  int f=0, l=N-1;
  while(f<l){
    int idx=arr[f++].second, id=arr[l--].second;
    seg[S+idx]=0; update(S+idx);
    cout<<sum(0,idx,1,0,S-1)<<'\n';
    seg[S+id]=0; update(S+id);
    cout<<sum(id,N-1,1,0,S-1)<<'\n';
  }
  if(f==l)cout<<0;
}
