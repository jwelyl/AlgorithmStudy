#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int > > v;
int mosquito;
pair<int, int> answer;
void input() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }
}

void pro() {
    sort(v.begin(), v.end());

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    for(int i = 0; i < v.size(); i++) {
        // 모기가 나갈 때되면 내보내자!
        while(!pq.empty() && pq.top().first <= v[i].first) pq.pop();
    
        pq.push({v[i].second, v[i].first});

        // 모기의 수는 유지되며, 모기가 교체되는 경우
        if(pq.size() == mosquito && answer.second == v[i].first) {
            // answer = {v[i].first, v[i].second}; > 안되는 이유 => 교체되어도 모기 수는 유지되니 범위 시작은 그대로 유지...
            answer.second = pq.top().first;
        }

        // 모기의 수가 증가하는 경우
        if(pq.size() > mosquito) {
            mosquito = pq.size();
            answer = {v[i].first, pq.top().first};
        }
    }
    cout << mosquito << '\n' << answer.first << ' ' << answer.second << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    pro();
}