#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;
ll t, n, m, dp[12][2002];

int main(){
    cin >> t;
    while(t--){
        cin >> n >> m;
        memset(dp, 0, sizeof(dp));
        for(ll k = 0; k <= 2000; k++){
            dp[0][k] = 1;
        }

        for(ll x = 1; x <= n; x++){
            for(ll y = 1; y <= m; y++){
                dp[x][y] = dp[x-1][y/2] + dp[x][y-1];
            }
        }
        cout << dp[n][m] << '\n';
    }
    return 0;
}