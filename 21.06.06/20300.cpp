#include <bits/stdc++.h>
using namespace std;
long long answer;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> vec;
    int n; cin >> n;
    vec.resize(n);
    for(int i = 0; i < n; i++) cin >> vec[i];
    sort(vec.begin(), vec.end());
    if(n % 2) {
        answer = vec[n - 1];
        for(int i = 0; i < (n - 1) / 2; i++) {
            answer = max(answer, vec[i] + vec[n - 2 - i]);
        }
    }
    else {
        answer = vec[0] + vec[n - 1];
        for(int i = 1; i < n / 2; i++)
            answer = max(answer, vec[i] + vec[n - 1 - i]);
    }
    cout << answer;
}