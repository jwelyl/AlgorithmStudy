#include <string>
#include <vector>
#include <iostream>
using namespace std;
typedef pair<int,int> p;
const int INF= 200000000;
int cost[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fare) {
    int answer = INF;
    s--,a--,b--;
    for(int i=0; i<201; i++)for(int j=0; j<201; j++)
        if(i!=j){
            cost[i][j]=INF;
        }
    
    for(int i=0; i<fare.size(); i++){
        int ss=fare[i][0], ee=fare[i][1], cc=fare[i][2];
        ss--,ee--;
        cost[ss][ee]=cc;
        cost[ee][ss]=cc;
    }
    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
    for(int i=0; i<n; i++)
        answer=min(answer,cost[s][i]+cost[i][a]+cost[i][b]);
        
    
    return answer;
}