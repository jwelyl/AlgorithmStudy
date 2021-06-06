#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int n, k;
vector<int> star;
vector<int> num;
vector<int> candid;
vector<int> candid2;
int first, second;
int answer;
void input() {
    cin >> n;
    star.resize(n);
    for(int i = 0; i < n; i++) cin >> star[i];
    cin >> k;
    num.resize(k);
    for(int i = 0; i < k; i++) cin >> num[i];
}

bool check() {
    string result = to_string(first * second); // 4884
    if(result.size() != star[star.size() - 1]) return false;
    unordered_map<int, bool> mp;
    for(int i = 0; i < num.size(); i++) mp[num[i]] = 1;

    string s = to_string(second);
    
    for(int i = 0; i < s.size(); i++) {
        string temp = to_string(first * (s[i] - '0'));
        if(temp.size() != star[i + 2]) return false;
        for(int j = 0; j < temp.size(); j++)
            if(!mp[temp[j] - '0']) return false;
    }

    for(int i = 0; i < result.size(); i++)
        if(!mp[result[i] - '0']) return false;
    
    return true;
}

void dfs2(int idx) {
    if(star[idx] == candid2.size()) {
        string s;
        for(auto i : candid2) s += to_string(i);
        second = atoi(s.c_str());

        if(check()) answer++;
        return;
    }

    for(int i = 0; i < num.size(); i++) {
        candid2.push_back(num[i]);
        dfs2(idx);
        candid2.pop_back();
    }
}

void dfs(int idx) {
    if(star[idx] == candid.size()) {
        string s;
        for(auto i : candid) s += to_string(i);
        first = atoi(s.c_str());
        dfs2(1);
        return;
    }

    for(int i = 0; i < num.size(); i++) {
        candid.push_back(num[i]);
        dfs(idx);
        candid.pop_back();
    }
}

void pro() {
    dfs(0);
    cout << answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    input();   
    pro();
}