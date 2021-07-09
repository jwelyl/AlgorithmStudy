#include <iostream>
#include <algorithm>
using namespace std;
struct Post{
  int s,e,v;
  Post(){Post(0,0,0);}
  Post(int s, int e, int v){this->s=s;this->e=e;this->v=v;}
  bool operator<(const Post& p)const{
    return e<p.e;
  }
};

Post post[10001];
int weight[2001];
int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int N,W; cin>>N>>W;
  for(int i=1; i<=N; i++)weight[i]=W;
  int M; cin>>M;
  for(int i=0; i<M; i++){
    int s,e,v; cin>>s>>e>>v;
    post[i]=Post(s,e,v);
  }
  sort(post,post+M);
  int ans=0;
  for(int i=0; i<M; i++){
    int s=post[i].s, e=post[i].e, v=post[i].v, tmp=weight[e-1];
    
    for(int j=e-1; j>=s ;j--){
      if(weight[j]<tmp){tmp=weight[j];}
      else weight[j]=tmp;
    }
    v=min(v,weight[s]);
    for(int j=s; j<e; j++)weight[j]-=v;
    ans+=v;
  }
  cout<<ans;
}
