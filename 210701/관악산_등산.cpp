#include <iostream>
#include <vector>
using namespace std;
vector <int> adj[5002];
int n, m;
int dp[5002];
int height[5002];

int dfs(int cur){
    int &ret = dp[cur];
    if (ret)
        return ret;
    for(int i = 0; i < adj[cur].size(); i++){
        ret = max(ret, dfs(adj[cur][i]));
    }
    return ++ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> height[i];
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        if (height[a] < height[b])
            adj[a].push_back(b);
        else
            adj[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        cout << dfs(i) << '\n';
    }
    return 0;
}