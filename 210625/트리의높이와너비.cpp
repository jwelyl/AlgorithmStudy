#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX=10001;

struct Tree{
  int l,r;
};
Tree tree[MAX];
vector<int> lv[MAX];
int par[MAX];
int getpar(int a){
  if(par[a]==-1)return a;
  return par[a]=getpar(par[a]);
}
int N, x=0;
void middle(int n, int dep){
  if(tree[n].l>=0)
    middle(tree[n].l,dep+1);
  lv[dep].push_back(x++);
  if(tree[n].r>=0)
    middle(tree[n].r,dep+1);
}

int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin>>N;
  fill(par,par+MAX,-1);
  for(int i=0; i<N; i++){
    int n,l,r; cin>>n>>l>>r; n--; l--;r--;
    tree[n].l=l; tree[n].r=r;
    if(l>=0)par[l]=n;if(r>=0)par[r]=n;
  }
  middle(getpar(0),1);
  int ans=0,ans2=0;
  for(int i=1; i<MAX; i++)if(lv[i].size()>0){
    sort(lv[i].begin(),lv[i].end());
    if(lv[i].back()-lv[i][0]+1>ans2){
      ans2=lv[i].back()-lv[i][0]+1;
      ans=i;
    }
  }
  cout<<ans<<" "<<ans2;
}
