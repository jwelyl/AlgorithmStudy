#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int answer;
vector<int> vec;
void input() {
    cin >> n;
    vec.resize(n);
    for(int i = 0; i < n; i++) cin >> vec[i];
}

void pro() {
    sort(vec.begin(), vec.end());
    do {
        int temp = 0;
        for(int i = 1; i < n; i++)
            temp += abs(vec[i] - vec[i - 1]);
        answer = max(answer, temp);
    } while(next_permutation(vec.begin(), vec.end()));
    cout << answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    input();
    pro();
}