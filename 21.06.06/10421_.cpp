#include<bits/stdc++.h>

using namespace std;
vector<int> stars;
vector<int> number;
int bitmask;
int answer;
int firstNumber;

bool check(int value, int idx) {
    bool f = to_string(value).size() == stars[idx];
    if(!f) return f;

    while(value) {
        int cur = value % 10;
        value /= 10;
        if(bitmask & (1 << cur)) f = true;
        else return false;
    }
    return f;
}

void dfs2(int cnt, int v) {
    if(stars[1] == cnt) {
        bool f = check(firstNumber * v, stars.size() - 1);
        if(!f) return;

        for(int i = 2; i < stars.size() - 1; i++) {
            f &= check(firstNumber * (v % 10), i);
            v /= 10;
        }
        if(f) answer++;
        return;
    }
    for(auto &i: number) dfs2( cnt + 1, v * 10 + i );
}

void dfs(int cnt, int v) {
    if(stars[0] == cnt) {
        firstNumber = v;
        dfs2(0, 0);
        return;
    }
    for(auto &i: number) dfs( cnt + 1, v * 10 + i );
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N; cin >> N;
    stars = vector<int>(N); 
    for(int i = 0; i < N; i++) cin >> stars[i];
    int K; cin >> K;
    number = vector<int>(K); 
    for(int i = 0; i < K; i++) cin >> number[i];
    for(auto &i: number) bitmask |= (1 << i);
    dfs(0, 0);
    cout << answer;

    return 0;
}