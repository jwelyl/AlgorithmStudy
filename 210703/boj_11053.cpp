#include <iostream>
using namespace std;
int n;
int arr[1002];
int dp[1002];
int len = 0;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    for(int i = 0; i < n; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if (arr[j] < arr[i]){
                dp[i] = max(dp[i] , dp[j] + 1);
            }
        }
        if (len < dp[i])
            len = dp[i];
    }
    cout << len;
    return 0;
}