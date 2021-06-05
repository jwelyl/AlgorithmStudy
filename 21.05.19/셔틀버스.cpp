#include <bits/stdc++.h>

using namespace std;
priority_queue<int, vector<int>, greater<int>> arriveTime;
int convert(string tmp) {
    string hour = tmp.substr(0, 2);
    string min = tmp.substr(3, 2);
    return (stoi(hour) * 60 + stoi(min));
}

string solution(int n, int t, int m, vector<string> timetable) {
    int answer = 0;
    
    int answerTime = 0;
    
    for(int i = 0; i < timetable.size(); i++) {
        int time = convert(timetable[i]);
        arriveTime.push(time);
    }
    
    vector<int> bus;
    int startTime = 540;
    for(int i = 0; i < n; i++) {
        bus.push_back(startTime + t * i);
    }
    
    // 마지막 운영 시간 전까지 대기열 지우기
    int idx;
    for(idx = 0; idx < bus.size() - 1; idx++) {
        for(int j = 0; j < m; j++) {
            if(!arriveTime.empty()) {
                if(bus[idx] >= arriveTime.top()) {
                    arriveTime.pop();
                }
            }
        }
    }
    
    // 마지막 버스가 가득 찼는지
    bool isEmpty = true;
    
    // 마지막 운영 시간
    for(int i = 0; i < m; i++) {
        if(!arriveTime.empty()) {
            if(bus[idx] >= arriveTime.top()) {
                answer = arriveTime.top();
                arriveTime.pop();
            }
            else {
                answer = bus[idx];
                isEmpty = false;
                break;
            }
        }
        else {
            answer = bus[idx];
            isEmpty = false;
            break;
        }
    }
    // 버스가 가득 찼을 경우 제일 마지막에 탄 사람보다 1 작은 경우가 정답
    if(isEmpty) answer = answer - 1;
    
    // 시간 변환
	string ansHour = answer / 60 > 9 ? to_string(answer / 60) : '0' + to_string(answer / 60);
	string ansMinute = answer % 60 > 9 ? to_string(answer % 60) : '0' + to_string(answer % 60);
	string ansStr = ansHour + ':' + ansMinute;
    
    return ansStr;
}