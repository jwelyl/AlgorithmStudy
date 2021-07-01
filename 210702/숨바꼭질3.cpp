#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX=100001;
int loc[MAX];

int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  fill(loc, loc+MAX, MAX);
  int s,e; cin>>s>>e;
  if(e<=s){
    cout<<s-e; return 0;
  }
   loc[s]=0;
  if(s==0){
    s=1; loc[s]=1;
  }
  queue<int> q;
  q.push(s);
  
  while(!q.empty()){
    int curr=q.front(); q.pop();
    int c=curr;
    while(curr<MAX){
      loc[curr]=min(loc[curr],loc[c]);
      if(curr-1>0 && loc[curr-1]>loc[c]+1){
        q.push(curr-1);
        loc[curr-1]=loc[c]+1;
      }
      if(curr+1<MAX && loc[curr+1]>loc[c]+1){
        q.push(curr+1);
        loc[curr+1]=loc[c]+1;
      }
      curr*=2;
    }
  }
  cout<<loc[e];
}

