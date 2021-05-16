#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int a[11];
unordered_map<string, int> umapArr[11];

void makeCombi(string s, int idx, string result) {
    if (idx >= s.length()) {
        int len = result.length();
        if (len >= 2) {
            umapArr[len][result]++;
            a[len] = max(a[len], umapArr[len][result]);
        }
        return;
    }

    makeCombi(s, idx + 1, result + s[idx]);
    makeCombi(s, idx + 1, result);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    for (string& s : orders) {
        sort(s.begin(), s.end());
        makeCombi(s, 0, "");
    }

    vector<string> answer;
    for (int len : course) {
        for (pair<string, int> i : umapArr[len]) {
            if (i.second >= 2 && i.second == a[len]) {
                answer.push_back(i.first);
            }
        }
    }

    sort(answer.begin(), answer.end());
    return answer;
}
