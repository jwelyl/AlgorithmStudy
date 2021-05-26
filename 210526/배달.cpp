#include <vector>
#include <queue>
using namespace std;
const int INF=300000000;
typedef pair<int,int> p;
int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<vector<p>> adj(N,vector<p>(N,p(0,0)));
    for(auto v : road){
        int s=v[0]-1,e=v[1]-1,c=v[2];
        adj[s].push_back({e,c});
        adj[e].push_back({s,c});
    }
    vector<int> cost(N,INF);
    vector<bool> visit(N,false);
    priority_queue<p,vector<p>,greater<p>> pq;
    cost[0]=0;
    pq.push({0,0});
    while(!pq.empty()){
        int curr;
        do{
            curr=pq.top().second;
            pq.pop();
        }while(!pq.empty()&&visit[curr]);
        if(visit[curr])break;
        visit[curr]=true;
        for(auto n : adj[curr]){
            int c=n.second,next=n.first;
            if(cost[next]>cost[curr]+c){
                cost[next]=cost[curr]+c;
                pq.push({cost[next],next});
            }
        }
    }
    for(int i : cost)if(i<=K)answer++;
    return answer;
}