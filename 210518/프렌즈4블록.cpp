#include <string>
#include <vector>
using namespace std;

int dx[4]={0,0,1,1},dy[4]={0,1,0,1};
vector<char> map[31];
bool del[31][31];

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    for(int i=0; i<n; i++)for(int j=m-1; j>=0; j--)map[i].push_back(board[j][i]);
    int ans=0;
    do{
        ans=0;
        for(int i=0; i<n; i++)for(int j=0; j<map[i].size(); j++){
            int num=0;
            for(int a=0; a<4; a++){
                int y=i+dy[a],x=j+dx[a];
                if(y>=n||x>=map[y].size())continue;
                if(map[i][j]==map[y][x])num++;
            }
            if(num==4){
                for(int a=0; a<4; a++){
                    int y=i+dy[a],x=j+dx[a];
                    del[y][x]=true;
                }
            }
        }
        for(int i=0; i<n; i++)for(int j=0; j<map[i].size(); j++)
            if(del[i][j])map[i][j]='0',del[i][j]=false;
        for(int i=0; i<n; i++)for(int j=0; j<map[i].size(); j++)
            while(j<map[i].size()&&map[i][j]=='0')map[i].erase(map[i].begin()+j),ans++;
        answer+=ans;
    }while(ans);
    return answer;
}