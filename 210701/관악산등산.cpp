#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int MAX=5001;
vector<int> adj[MAX];
int height[MAX], dp[MAX];
int recur(int curr, int prev=-1){
	int &res=dp[curr];
	if(res!=-1)return res;
	res=1;
	for(int next : adj[curr])if(height[next]>height[curr]&&next!=prev){
		res=max(res,recur(next,curr)+1);
	}
	return res;
}

int main(void){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	memset(dp,-1,sizeof(dp));
	int N,M; cin>>N>>M;
	for(int i=0; i<N; i++)cin>>height[i];
	for(int i=0; i<M; i++){
		int s,e; cin>>s>>e; s--;e--;
		adj[s].push_back(e);
		adj[e].push_back(s);
	}
	for(int i=0; i<N; i++)cout<<recur(i)<<'\n';
}

