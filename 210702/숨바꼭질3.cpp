#include <iostream>
#include <deque>
using namespace std;
const int MAX = 100002;
int n, k;
int dis[MAX];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;

    fill(dis, dis + MAX, -1);
    deque <int> dq;
    dq.push_back(n);
    dis[n] = 0;

    while(!dq.empty()){
        auto cur = dq.front();
        dq.pop_front();

        if (2*cur >= 0 && 2*cur < MAX && dis[2*cur] == -1){
            dq.push_front(2*cur);
            dis[2*cur] = dis[cur];
        }
        if (cur - 1 >= 0 && cur - 1 < MAX && dis[cur - 1] == -1){
            dq.push_back(cur - 1);
            dis[cur - 1] = dis[cur] + 1;
        }
        if (cur + 1 >= 0 && cur + 1 < MAX && dis[cur + 1] == -1){
            dq.push_back(cur + 1);
            dis[cur + 1] = dis[cur] + 1;
        }
    }
    cout << dis[k];
    return 0;
}