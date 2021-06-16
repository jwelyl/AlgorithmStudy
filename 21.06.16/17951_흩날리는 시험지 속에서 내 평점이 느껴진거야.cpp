/*
Problem : https://www.acmicpc.net/problem/14852
Comment : 1차원 배열로 하게 되면 시간초과발생... 
*/
#include <bits/stdc++.h>
using namespace std;

int N, K, sum;
int answer;
vector<int> vec;
void input() {
    cin >> N >> K;
    vec.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> vec[i];
        sum += vec[i];
    }
}

void pro() {
    long long left = 0; long long right  = sum;

    while(left <= right) {
        int cnt = 0, now = 0;
        long long mid = (left + right) / 2;

        // 점수의 크기로 그룹으로 나누기
        for(int i = 0; i < N; i++) {
            now += vec[i];
            if (now >= mid) {
                now = 0;
                cnt++;
            }
        }
        // 가능한 경우이기에, 점수를 증가해서 진행해보기
        if(cnt >= K) {
            left = mid + 1;
            answer = max(answer, mid);
        }
        // 아니니깐 줄여보자 점수를
        else right = mid - 1;
    }
    cout << answer << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    pro();
    return 0;
}