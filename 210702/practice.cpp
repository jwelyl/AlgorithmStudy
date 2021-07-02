#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
 
vector<int> graphList[100];
int n,m;
int main()
{
    //input
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++){
        int s,e;
        scanf("%d%d",&s,&e);
        graphList[s].push_back(e);
        graphList[e].push_back(s);
    }
    //output
    printf("\n==인접리스트 구현 완료==\n");
    for(int i=1; i<=n; i++){
        printf("%d : ",i);
        for(int j=0; j<graphList[i].size(); j++){
            printf("%d ",graphList[i][j]);
            printf("%ld" , graphList[i].size());           
        }
        printf("\n");
    }
 
    return 0;
}


