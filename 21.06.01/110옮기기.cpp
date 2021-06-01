#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> s) {
    vector<string> answer;
    
    for(int i = 0; i < s.size(); i++) {
        int count = 0;
        string tmp = "";
        for(int j = 0; j < s[i].size(); j++) {
            tmp += s[i][j];
            if(tmp.size() >= 3) {
                if(tmp.substr(tmp.size() - 3, 3) == "110"){
                    count++;
                    tmp.erase(tmp.size() -3, 3);
                }
            }
        }
        
        int location = -1;
        for(int i = tmp.size() - 1; i >= 0; i--) {
            if(tmp[i] == '0') {
                location = i;
                break;
            }
        }
        
        // 0이 없는경우
        if(location == -1) {
            while(count > 0) {
                tmp.insert(0, "110");
                count--;
            }
            answer.push_back(tmp);
        }
        // 1인 경우
        else {
            while(count > 0) {
                tmp.insert(location + 1, "110");
                count--;
            }
            answer.push_back(tmp);
        }
    }
    return answer;
}
