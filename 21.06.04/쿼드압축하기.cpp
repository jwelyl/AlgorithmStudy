#include <string>
#include <vector>

using namespace std;
vector<vector<int> > graph;
vector<int> ans;
void go(int x, int y, int size) {
    bool zero = true, one = true;
    
    for(int i = x; i < x + size; i++) {
        for(int j = y; j < y + size; j++) {
            if(graph[i][j] == 0) one = false;
            else if(graph[i][j] == 1) zero = false;
        }
    }
    
    if(zero == true) {
        ans[0]++;
        return;
    }
    if(one == true) {
        ans[1]++;
        return;
    }
    
    go(x, y, size / 2);
    go(x, y + size/2, size / 2);
    go(x + size/2, y, size / 2);
    go(x + size/2, y + size/2, size / 2);
}

vector<int> solution(vector<vector<int>> arr) {
    ans.resize(2);
    graph = arr;
    
    go(0, 0, graph.size());
    return ans;
}
