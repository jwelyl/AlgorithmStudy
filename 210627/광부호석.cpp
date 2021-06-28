#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef pair<int,long long> p;
const int MAX=100001;
struct Node{
  int y,x; ll c;
  Node(){Node(0,0,0);}
  Node(int yy,int xx,int cc):y(yy),x(xx),c(cc){}
  bool operator<(const Node& t)const{
    if(y!=t.y)return y<t.y;
    else if(x!=t.x)return x<t.x;
    else return c<t.c;
  }
};
unordered_map<int,int> Y,X;
int sy=0,sx=0,N,C,S=1<<17;
vector<int> y,x;
vector<Node> node,axidY[MAX];
p seg[1<<18];
ll ans;
ll segment(int s, int e, int n, int ss, int ee){
  if(e<ss||ee<s) return 0;
  if(s<=ss&&ee<=e) return seg[n].second;
  int mid=(ss+ee)/2;
  return segment(s,e,n*2,ss,mid)+segment(s,e,n*2+1,mid+1,ee);
}
int segnum(int s, int e, int n, int ss, int ee){
  if(e<ss||ee<s) return 0;
  if(s<=ss&&ee<=e) return seg[n].first;
  int mid=(ss+ee)/2;
  return segnum(s,e,n*2,ss,mid)+segnum(s,e,n*2+1,mid+1,ee);
}
void update(int n){
  while(n>1){
    n/=2;
    seg[n].first=seg[n*2].first+seg[n*2+1].first;
    seg[n].second=seg[n*2].second+seg[n*2+1].second;
  }
}

int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin>>N>>C;
  for(int i=0; i<N; i++){
    int yy,xx; ll cc; cin>>yy>>xx>>cc;
    yy--;xx--;
    y.push_back(yy); x.push_back(xx);
    node.push_back(Node(yy,xx,cc));
  }
  sort(y.begin(),y.end()); 
  sort(x.begin(),x.end());
  y.erase(unique(y.begin(),y.end()),y.end());
  x.erase(unique(x.begin(),x.end()),x.end());
  sort(node.begin(),node.end());
  for(auto n : y)Y[n]=sy++;
  for(auto n : x)X[n]=sx++;
  for(auto n : node) axidY[Y[n.y]].push_back(n);
  for(int i=0; i<sy; i++)
    for(auto n : axidY[i]){
        seg[S+X[n.x]].first++;
        seg[S+X[n.x]].second+=n.c;
    }
  for(int i=S-1; i>0; i--){
    seg[i].first=seg[i*2].first+seg[i*2+1].first;
    seg[i].second=seg[i*2].second+seg[i*2+1].second;
  }
  for(int i=sy-1; i>=0; i--){
    int lo=0, hi=sx;
    while(lo+1<hi){
      int mid=(lo+hi)/2;
      if(segnum(0,mid,1,0,S-1)<=C)lo=mid;
      else hi=mid;
    }
    ans=max(ans,segment(0,lo,1,0,S-1));
    for(auto n :axidY[i]){
      seg[S+X[n.x]].first--;
      seg[S+X[n.x]].second-=n.c;
      update(S+X[n.x]);
    }
  }
  cout<<ans;
}
