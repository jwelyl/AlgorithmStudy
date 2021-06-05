#include <string>
#include <vector>

using namespace std;

bool isOk(int dir, vector<vector<int>>& v, int x, int y) {
    if (dir == 0) { // 아래
        if (y + 1 < v.size()) {
            if (v[y + 1][x] == 0) return true;
        }
    }
    else if (dir == 1) { //우측
        if (x + 1 < v[y].size())
            if (v[y][x + 1] == 0) return true;
    }
    else if (dir == 2) { //위
        if (x - 1 >= 0 && y - 1 >= 0) {
            if (v[y - 1][x - 1] == 0)
                return true;
        }
    }
    return false;
}
void go(vector<vector<int>>& v, int x, int y, int dir, int value) {

    v[y][x] = value;
    if (dir == 0) {
        if (isOk(dir, v, x, y)) go(v, x, y + 1, 0, value + 1);
            //아래로 갈수 있다.
        else {
            //우측 갈 수 있는지 검사후  우측
            if (isOk(1, v, x, y)) go(v, x+1, y , 1, value + 1);
        }
    }
    else if (dir == 1) {
        //우측 갈 수 있는지 검사후  우측
        if (isOk(1, v, x, y)) go(v, x + 1, y, 1, value + 1);
        else {
            //우측이 안되면 위 검사 후 위
            if (isOk(2, v, x, y)) go(v, x-1, y-1, 2, value + 1);
        }
    }
    else if (dir == 2) {
        //위로
        if (isOk(dir, v, x, y)) go(v, x - 1, y - 1, 2, value + 1);
        else { //안되면 아래로
            if (isOk(0, v, x, y)) go(v, x, y+1, 0, value + 1);
        }   
    }
}
    
vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> v(n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            v[i].push_back(0);

    go(v, 0, 0, 0, 1);
    for (int i = 0; i < v.size(); i++)
        for (int j = 0; j < v[i].size(); j++)
            answer.push_back(v[i][j]);

    return answer;
}