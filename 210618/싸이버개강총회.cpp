#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
bool visit[100001];

int changeTime(const string& str){
  string h=str.substr(0,2), m=str.substr(3,2);
  int hh=0,mm=0;
  for(int i=0; i<2; i++){
    hh*=10;mm*=10;
    hh+=h[i]-'0'; mm+=m[i]-'0';
  }
  return mm+hh*60;
}

bool compare(const string& src, const string& dest){
  int s=changeTime(src), d=changeTime(dest);
  if(s<=d)return true;
  return false;
}

int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  string start,end,finish; cin>>start>>end>>finish;
  string time,name;
  unordered_map<string,int> hm;
  int n=1;
  while(cin>>time>>name){
    if(compare(time,start)){
        if(hm[name]==0)hm[name]=n++;
    }
    else if(compare(end,time)&&compare(time,finish)){
      if(hm[name]>0)visit[hm[name]-1]=true;
    }
  }
  int ans=0;
  for(int i=0; i<n; i++)if(visit[i])ans++;
  cout<<ans;
}
