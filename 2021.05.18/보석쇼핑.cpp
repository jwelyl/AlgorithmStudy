#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer = {1, 999999};
    set<string> s;
    for(string str: gems) s.insert(str);
    int size = s.size();

    int left = 0, right = -1;
    map<string, int> jewel;

    while(right != gems.size()) {
        if(jewel.size() < size) {
            if(right == gems.size() - 1) break;
            jewel.insert({gems[++right], 0});
            jewel[gems[right]]++;
        }
        else {
            if(right - left < answer[1] - answer[0]) {
                answer = {left + 1, right + 1};
            }
            if(--jewel[gems[left]] == 0) {
                jewel.erase(gems[left]);
            }
            left++;
        }
    }

    return answer;
}