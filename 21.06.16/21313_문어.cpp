#include <bits/stdc++.h>
using namespace std;

int N;
void input() {
    cin >> N;
}
void pro() {
    bool flag = false;
    if(N % 2) {
        flag = true; // 홀수 인경우 flag : false
        N--;
    }

    while(N) {
        if(N % 2 == 0) cout << "1" << " ";
        else cout << "2" << " ";
        N--;
    }
    if(flag) cout << "3" << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    pro();
    return 0;
}