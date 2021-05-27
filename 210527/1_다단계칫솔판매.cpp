#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
map<string, int> m;
int par[10001];
int haveMoney[10001];

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    for (int i = 0; i < enroll.size(); i++) {
        string str = enroll[i];
        m[str] = i + 1;
    }

    for (int i = 0; i < enroll.size(); i++) {
        int c = m[enroll[i]];
        int p;
        string s = referral[i];
        if (s == "-")
            p = 0;
        else
            p = m[referral[i]];
        par[c] = p;
    }

    for (int i = 0; i < seller.size(); i++) {
        int money = amount[i] * 100;
        int cur = m[seller[i]];
        while (cur > 0) {
            int p = par[cur];
            if (money < 10) {
                haveMoney[cur] += money;
                break;
            }
            int tenPer = money / 10;
            haveMoney[cur] += (money - tenPer);
            money = tenPer;
            cur = p;
        }
    }
    for (int i = 0; i < enroll.size(); i++) {
        string str = enroll[i];
        answer.push_back(haveMoney[m[str]]);
    }
    return answer;
}