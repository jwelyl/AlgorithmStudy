#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
	vector<int> answer;
	map<string, int> dict;
    
	int idx = 1;
    int now_idx;
    string temp;
    
    while(idx <= 26) {
        temp = 'A' + idx - 1;
        dict[temp] = idx++;
    }
    
    for(int i = 0; i < msg.size(); i++) {
        temp = "";
        now_idx = -1;
        for(int j = i; j < msg.size(); j++) {
            temp += msg[j];
            if(dict.find(temp) == dict.end()) {
                dict[temp] = idx++;
                temp = temp.substr(0, temp.size() - 1);
                --i;
                break;
            }
            now_idx = dict[temp];
            ++i;
        }
        answer.push_back(now_idx);
    }
    
	return answer;
}