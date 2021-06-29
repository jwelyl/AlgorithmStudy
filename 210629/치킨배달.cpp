#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>
#define RAN (ty<0||tx<0||ty>=N||tx>=N)
using namespace std;
const int INF=987654;
long long ans=1LL<<61;
int N,M;
int map[51][51];
int dy[4]={1,-1,0,0}, dx[4]={0,0,1,-1};
int dist[14][2501];
unordered_map<int,int> HOME,CHICKEN;
vector<int>home,chicken;
void bfs(int id){
	queue<int> q;
	q.push(id);
	bool visit[51][51]={0,};
	visit[id/N][id%N]=true;
	
	while(!q.empty()){
		int curr=q.front(); q.pop();
		
		for(int i=0; i<4; i++){
			int ty=curr/N+dy[i], tx=curr%N+dx[i];
			if(RAN||visit[ty][tx])continue;
			visit[ty][tx]=true;
			int next=ty*N+tx;
			dist[CHICKEN[id]][next]=dist[CHICKEN[id]][curr]+1;
			q.push(next);
		}
	}
}
void recur(int step=0, int n=0){
	long long tcost=0;
	for(int n : home) tcost+=HOME[n];
	ans=min(tcost,ans);
    if(step==M)return;
	for(int i=n; i<chicken.size(); i++){
		vector<pair<int,int>> t;
		for(int n : home){
			t.push_back({n,HOME[n]});
			HOME[n]=min(dist[CHICKEN[chicken[i]]][n],HOME[n]);
		}
		recur(step+1,i+1);
		for(auto n : t)HOME[n.first]=n.second;
	}
}
int main(int argc, char* argv[]) {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>N>>M;
	for(int i=0; i<N; i++)for(int j=0; j<N; j++){
		cin>>map[i][j];
		if(map[i][j]==1)home.push_back(i*N+j);
		else if(map[i][j]==2)chicken.push_back(i*N+j);
	}
	int cnt=0;
	for(int n : chicken)CHICKEN[n]=cnt++;
	for(auto n : chicken)bfs(n);
	for(int n : home)HOME[n]=INF;
	
	recur();
	
	cout<<ans;
	return 0;
}