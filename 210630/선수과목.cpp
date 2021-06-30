#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector <int> adj[1002];
int inDegree[1002];
int result[1002];
queue <int> Q;


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    int x, y;
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        adj[x].push_back(y);
        inDegree[y]++;
    }

    for(int i = 1; i <= n; i++){
        if(inDegree[i] == 0)
            Q.push(i);
        result[i] = 1;
    }
    
    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        for(int i = 0; i < adj[cur].size(); i++){
            int next = adj[cur][i];
            inDegree[next]--;
            if (inDegree[next] == 0){
                Q.push(next);
                result[next] = max(result[next] , result[cur] + 1);
            }
        }
    }
    for(int i = 1; i <= n; i++)
        cout << result[i] << " ";
    return 0;
}