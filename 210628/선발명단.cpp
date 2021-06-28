#include <iostream>
#include <cstring>
using namespace std;
int player[11][11];
int T, answer=0;

void recur(int step=0,int visit=0, int cost=0){
  if(step==11){
    answer=max(answer,cost);
    return;
  }
  for(int i=0; i<11; i++)if(player[step][i]>0&&!(visit&1<<i)){
    recur(step+1,visit|1<<i,cost+player[step][i]);
  }
}

int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin>>T;
  while(T--){
    answer=0;
    for(int i=0; i<11; i++)
      for(int j=0; j<11; j++)cin>>player[i][j];
    recur();
    cout<<answer<<'\n';
  }
}
