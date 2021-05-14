#include <bits/stdc++.h> 
using namespace std;

int solution(string s) {
    int answer = s.size();

    for(int cnt = 1; cnt <= s.size(); cnt++){  
        vector<string> v;  
        int j = 0;
        
        while(j + cnt <= s.size()) {
            v.push_back(s.substr(j, cnt));
            j = j + cnt;            
        }
        v.push_back(s.substr(j, s.size() - j));
        
        
        int ret = s.size();
        string prev = v[0];
        int count = 1;  // a a b b a c c c
        for(int i = 1; i < v.size(); i++){
            if(prev == v[i]) count++;
            else{
                if(count != 1) ret = ret - (prev.size() * (count - 1)) + to_string(count).size();
                count = 1; 
                prev = v[i];
            }
            if(i == v.size() - 1 && count != 1) ret = ret - (prev.size() * (count - 1)) + to_string(count).size(); 
        }
        
        answer = min(answer, ret);
    }
    return answer;
}
