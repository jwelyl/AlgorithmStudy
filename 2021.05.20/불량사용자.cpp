#include <bits/stdc++.h>

using namespace std;
vector<string> user;
vector<string> banned;
bool visited[10];
set<string> s;

void go(int idx) {
    // 모든 불량 사용자 아이디 탐색 완료 시
    if(idx == banned.size()) {
        string temp = "";
        for(int i = 0; i < user.size(); i++) {
            if(visited[i]) {
                temp += user[i];
            }
        }
        s.insert(temp);
        return;
    }
    
    // 불량 사용자 아이디마다 가능한 제제 아이디 찾기
    for(int i = 0; i < user.size(); i++) {
        bool isOk = true;
        
        if(visited[i]) continue;
        if(user[i].size() != banned[idx].size()) continue;
        
        // 문자 비교하기
        for(int j = 0; j < user[i].size(); j++) {
            if(banned[idx][j] == '*') continue;
            if(banned[idx][j] != user[i][j]) {
                isOk = false;
                break;
            }
        }
        // 제재가 된다면
        if(isOk) {
            visited[i] = 1;
            go(idx + 1);
            visited[i] = 0;
        }
    }
    return;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    user = user_id;
    banned = banned_id;
    go(0);
    answer = s.size();
    return answer;
}