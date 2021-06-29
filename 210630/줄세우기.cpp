#include <iostream>
#include <queue>
using namespace std;
typedef pair<int,int> p;
int seg[1<<9], S=1<<8, ans=0;



int segment(int s, int e, int n, int ss, int ee){
  if(e<ss||ee<s)return 0;
  if(s<=ss&&ee<=e)return seg[n];
  int mid=(ss+ee)/2;
  return max(segment(s,e,n*2,ss,mid),segment(s,e,n*2+1,mid+1,ee));
}
void update(int n){
  while(n>1){
    n/=2;
    seg[n]=max(seg[n*2],seg[n*2+1]);
  }
}
int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int N,t; cin>>N; t=N;
  priority_queue<p,vector<p>,greater<p>> pq;
  for(int i=0; i<N; i++){
    int c; cin>>c;
    pq.push({c,i});
  }
  while(!pq.empty()){
    int curr=pq.top().second;
    int n=pq.top().first;
    pq.pop();
    seg[S+curr]=segment(0,curr,1,0,S-1)+1;
    update(S+curr);
  }
  cout<<N-segment(0,N-1,1,0,S-1);
}
