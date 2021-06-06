#include <iostream>
#include <vector>
using namespace std;
const int MAX=100000;
typedef pair<int,int> p;
vector<p> adj[MAX];
int N;
p dfs(int curr, int cost, int excep=-1, int prev=-1){
  p ret={curr,cost};
  for(auto next:adj[curr])if(prev!=next.first&&excep!=next.first){
    p temp = dfs(next.first,cost+next.second,excep,curr);
    if(temp.second>ret.second){
      ret=temp;
    }
  }
  return ret;
}

int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin>>N;
  for(int i=0; i<N-1; i++){
    int s,e,c;cin>>s>>e>>c;
    s--,e--;
    adj[s].push_back({e,c});
    adj[e].push_back({s,c});
  }
  p f=dfs(0,0);
  p s=dfs(f.first,0);
  cout<<max(dfs(f.first,0,s.first).second,dfs(s.first,0,f.first).second);
}
