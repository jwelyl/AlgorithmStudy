
using namespace std;

int solution(int n)
{
    if(n==1)return 1;
    int ans = 0;
    
    while(n){
        if(n%2==0)n/=2;
        else {n-=1;ans++;}
    }
    

    return ans;
}