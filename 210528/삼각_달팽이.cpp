#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> temp(n,vector<int>(n,0));
    int dr[3]={1,0,-1},dc[3]={0,1,-1}, row=-1,column=0, num=1;
    while(n){
        for(int j=0; j<3; j++){
            for(int k=0;k<n; k++){
                row+=dr[j], column+=dc[j];
                temp[row][column]=num++;
            }
            n--;
            if(n<1)break;
        }
    }
    
    for(int i=0; i<temp.size(); i++)
        for(int j=0; j<temp.size(); j++){
            if(temp[i][j]==0)break;
            answer.push_back(temp[i][j]);
        }
    return answer;
}