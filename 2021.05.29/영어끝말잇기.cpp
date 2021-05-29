#include <vector>
#include <unordered_map>
#include <cstring>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    unordered_map<string, int> mp;
    
    mp[words[0]] = 1;
    for(int i = 1; i < words.size(); i++) {
        if(mp[words[i]]) {
            answer.push_back(i % n + 1);
            answer.push_back(i / n + 1);
            return answer;
        }
        if(words[i][0] != words[i - 1].back()) {
            answer.push_back(i % n + 1);
            answer.push_back(i / n + 1);
            return answer;
        }
        mp[words[i]] = 1;
    }
    answer.push_back(0);
    answer.push_back(0);
    return answer;
}