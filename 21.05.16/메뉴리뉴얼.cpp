#include <bits/stdc++.h>

using namespace std;

map<string, int> food[11];

void split(string s) {
    sort(s.begin(), s.end());
    for(int i = 2; i <= s.size(); i++) { // s개 중에서 1개를 뽑기
        vector<int> candidate;
        for(int j = i; j < s.size(); j++) candidate.push_back(0);
        for(int j = 0; j < i; j++) candidate.push_back(1);
        
        do {
            string tmp = "";
            for(int idx = 0; idx < s.size(); idx++) {
                if(candidate[idx] == 1) tmp += s[idx];
            }
            food[i][tmp]++;
            
        } while(next_permutation(candidate.begin(), candidate.end()));
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(string s: orders) split(s);
    
    for(int length: course) {
        vector<string> result;
        int maximum = 2;
        for(auto &node : food[length]) {
            if(maximum == node.second) result.push_back(node.first);
            else if(maximum < node.second) {
                result.clear();
                maximum = node.second;
                result.push_back(node.first);
            }
        }
        for(string s: result) answer.push_back(s);
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}