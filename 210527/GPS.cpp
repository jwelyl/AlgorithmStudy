#include <vector>
#include <algorithm>

using namespace std;
const int INF=9876;
vector<int> adj[201];
int dest,K;
int dp[201][101];

int recur(int curr, int cnt,const vector<int>& m){
    int &ret=dp[curr][cnt];
    if(ret!=-1)return ret;
    if(cnt==K){
        if(curr==dest){
            return ret=0;
        }
        else return ret=INF;
    }
    ret=INF;
    for(auto next : adj[curr])if(dp[next][cnt+1]<INF){
        int temp = recur(next,cnt+1,m);
        if(m[cnt+1]-1!=next)temp++;
        ret=min(ret,temp);
    }
    return ret;
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    int answer=INF;
    K=k-1;
    dest=gps_log[k-1]-1;
    for(int i=0; i<n; i++)adj[i].clear();
    
    for(int i=0; i<n; i++)for(int j=0; j<n;j++)dp[i][j]=-1;
    for(int i=0; i<n; i++)adj[i].push_back(i);
    for(auto n : edge_list){
        int s=n[0]-1, e=n[1]-1;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    answer=recur(gps_log[0]-1,0,gps_log);
    if(answer>=INF)answer=-1;
    return answer;
}