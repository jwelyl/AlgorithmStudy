#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<string> data) {
    int answer = 0;
    vector<char> friends = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
	
    do {
        bool isOk = true;
        for(int i = 0; i < data.size(); i++) {
            char left = data[i][0];
            char right = data[i][2];
            char sign = data[i][3];
            int dist = data[i][4] - '0';
            int left_idx, right_idx;
            
            for(int j = 0; j < 8; j++) {
                if(friends[j] == left) left_idx = j;
                if(friends[j] == right) right_idx = j;
            }
            
            if(sign == '=') {
                if(abs(left_idx - right_idx) - 1 != dist)
                    isOk = false;
            }
            else if(sign == '<') {
                if(abs(left_idx - right_idx) - 1 >= dist)
                	isOk = false;
            }
            else if(sign == '>') {
                if(abs(left_idx - right_idx) - 1 <= dist)
                    isOk = false;
            }
            if(!isOk) break;
        }
        if(isOk) answer++;
    } while(next_permutation(friends.begin(), friends.end()));
    
    
    
    return answer;
}