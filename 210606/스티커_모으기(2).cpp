#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int MAX=100000;
int dp[MAX][2];

int solution(vector<int> sticker)
{
    int answer=0, n=sticker.size()-1;
    if(sticker.size()==1)return sticker[0];
    else if(sticker.size()==2)return max(sticker[0],sticker[1]);
    
    dp[0][0]=sticker[0],dp[2][0]=dp[0][0]+sticker[2];
    answer=max(answer,max(dp[0][0],dp[2][0]));
    for(int i=3; i<sticker.size()-1; i++){
        dp[i][0]=max(dp[i-2][0],dp[i-3][0])+sticker[i];
        answer=max(answer,dp[i][0]);
    }
    
    dp[1][1]=sticker[1],dp[2][1]=sticker[2];
    answer=max(answer,max(dp[1][1],dp[2][1]));
    for(int i=3; i<sticker.size(); i++){
        dp[i][1]=max(dp[i-2][1],dp[i-3][1])+sticker[i];
        answer=max(answer,dp[i][1]);
    }
    return answer;
}