#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;
int parent[10001];
int profits[10001];

void go(int idx, int money) { 
    // 종료 조건
    if(idx == -1) return;

    int rest = money * 0.1;
    int result = money - rest;
    profits[idx] += result;
    go(parent[idx], rest);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;

    for(int i = 0; i < enroll.size(); i++) mp[enroll[i]] = i;
    for(int i = 0; i < referral.size(); i++) {
        if(referral[i] == "-") parent[i] = -1;
        else parent[i] = mp[referral[i]];
    }

    for(int i = 0; i < seller.size(); i++)
        go(mp[seller[i]], amount[i] * 100);

    for(int i = 0; i < enroll.size(); i++)
        answer.push_back(profits[i]);

    return answer;
}