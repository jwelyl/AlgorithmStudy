#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

vector<int> split(string& s) {  // "4,2,3" => {4,2,3}
    vector<int> v;
    stringstream ss(s);
    string num;
    while (getline(ss, num, ',')) {
        v.push_back(stoi(num));
    }

    return v;
}

bool cmp(vector<int>& a, vector<int>& b) {
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<vector<int>> parsed;
    string tmp;
    for (int i = 1; i < s.length() - 1; ++i) {
        if (s[i] == '{')
            continue;
        else if (s[i] == '}') {
            vector<int> v = split(tmp);  // tmp에 담은 string 파싱 4,2,3
            parsed.push_back(v);
            tmp.clear();
        } else if (s[i] == ',' && s[i - 1] == '}')
            continue;
        else
            tmp += s[i];
    }
    sort(parsed.begin(), parsed.end(), cmp);

    vector<int> answer;
    unordered_set<int> uset;
    answer.push_back(parsed[0][0]);
    uset.insert(parsed[0][0]);
    for (int i = 1; i < parsed.size(); ++i) {
        for (int j = 0; j < parsed[i].size(); ++j) {
            int element = parsed[i][j];
            if (uset.find(element) == uset.end()) {
                uset.insert(element);
                answer.push_back(element);
            }
        }
    }

    return answer;
}
