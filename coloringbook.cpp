#include <vector>
#include <queue>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};


vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    bool visit[101][101]={0};
    
    for(int i=0; i<m; i++)for(int j=0; j<n; j++)if(!visit[i][j]&&picture[i][j]>0){
        number_of_area++;
        int tnumsize=1;
        int tnumarea=picture[i][j];
        
        queue<pair<int,int>> q;
        q.push({i,j});
        visit[i][j]=true;
        
        while(!q.empty()){
            int y=q.front().first, x=q.front().second;
            q.pop();
            
            for(int i=0; i<4; i++){
                int xx= x+dx[i], yy=y+dy[i];
                if(xx<0||yy<0||xx>=n||yy>=m||picture[yy][xx]!=tnumarea||visit[yy][xx])continue;
                visit[yy][xx]=true;
                q.push({yy,xx});
                tnumsize++;
            }
        }
        
        max_size_of_one_area=max(max_size_of_one_area,tnumsize);
        
    }
    
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
