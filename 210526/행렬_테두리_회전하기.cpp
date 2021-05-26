#include <string>
#include <vector>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {

    int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
    vector<int> answer;
    vector<vector<int>> m(rows,vector<int>(columns,0));
    for(int i=0; i<rows; i++)for(int j=0; j<columns; j++)m[i][j]=i*columns+j+1;
    
    for(auto v : queries){
        int y=v[0]-1,x=v[1]-1,y1=v[2]-1,x1=v[3]-1;
        int dt[2]={x1-x,y1-y};
        int temp=m[y][x];
        int res=100000;
        for(int i=0; i<4; i++){
            int dd=dt[i%2];
            for(int j=0; j<dd; j++){
                y+=dy[i];x+=dx[i];
                int tt=m[y][x];
                res=min(res,temp);
                res=min(res,tt);
                m[y][x]=temp;
                temp=tt;
            }
        }
        answer.push_back(res);
    }
    return answer;
}