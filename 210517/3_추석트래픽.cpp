#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<string> lines) {
    int answer = 0;                 // 최대처리량
    vector<pair<int, int>> parsed;  // 시작,종료시간 밀리세컨드
    for (string& str : lines) {
        stringstream ss(str);
        int h, m, s, ms, duration;
        h = stoi(str.substr(11, 2)) * 60 * 60 * 1000;
        m = stoi(str.substr(14, 2)) * 60 * 1000;
        s = stoi(str.substr(17, 2)) * 1000;
        ms = stoi(str.substr(20, 3));
        duration = stof(str.substr(24)) * 1000;

        int endTime = h + m + s + ms;
        int startTime = endTime - duration + 1;
        parsed.push_back({startTime, endTime});
    }

    for (int i = 0; i < parsed.size(); ++i) {
        int cnt = 0;
        int end = parsed[i].second + 1000;  // end~end+1000 사이에 시작하는 다른 처리 카운트
        for (int j = i; j < parsed.size(); ++j) {
            int start = parsed[j].first;
            if (start < end) cnt++;
        }

        if (answer < cnt) {
            answer = cnt;
        }
    }

    return answer;
}