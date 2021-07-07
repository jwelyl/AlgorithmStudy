#include <iostream>
#include <cstring>
using namespace std;
int t, n;
int arr[22];
int dp[10002];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;

    while(t--){
        memset(dp,0,sizeof(dp));
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> arr[i];
        }
        int result;
        cin >> result;

        dp[0] = 1; // 0원을 만들 수 있는 가지 수: 1가지
        for(int i = 1; i <= n; i++){
            for(int j = arr[i]; j <= result; j++){
                dp[j] = dp[j] + dp[j - arr[i]];
            }
        }
        cout << dp[result] << '\n';
    }
    return 0;
}