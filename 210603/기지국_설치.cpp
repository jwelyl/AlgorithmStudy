#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int mod=2*w+1;
    if(stations[0]-w-1>0)answer+=(stations[0]-w-1)/mod+((stations[0]-w-1)%mod==0?0:1);
    for(int i=0; i<stations.size()-1; i++){
        int nn=stations[i+1]-stations[i]-2*w-1;
        if(nn>0){
            answer+=nn/mod+(nn%mod==0?0:1);
        }
    }    
    if(n-(stations.back()+w)>0)
        answer+=(n-(stations.back()+w))/mod+((n-(stations.back()+w))%mod==0?0:1);

    return answer;
}