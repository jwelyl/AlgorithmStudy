#include <iostream>
using namespace std;

const int MAX = 987654321;
int n, m;
int dis[202][202];
int path[202][202];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dis[i][j] = MAX;
            if (i == j) dis[i][j] = 0;
        }
    }
    while(m--){
        int x,y,z;
        cin >> x >> y >> z;
        dis[x][y] = dis[y][x] = z;
        path[x][y] = y;
        path[y][x] = x;
    }
    for(int k = 1;k <= n;k++)
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++) {
                if(dis[i][j] > dis[i][k]+dis[k][j]){
                   dis[i][j] = dis[i][k]+dis[k][j];
                   if(i != k) path[i][j] = path[i][k];
                }
            }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if (path[i][j]) cout << path[i][j] << ' ';
            else cout << '-' << ' ';
        }
        cout << '\n';
    }
    return 0;    
}