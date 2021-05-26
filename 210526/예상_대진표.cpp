
using namespace std;

int solution(int n, int a, int b)
{
    int tnum=0,num=0,lo=0,hi=n;
    while(lo+1<hi){
        int mid=(lo+hi)/2;
        if(a>mid&&b>mid)lo=mid;
        else if(a<=mid&&b<=mid)hi=mid;
        else break;
        num++;
    }
    while(n>1){
        n/=2;tnum++;
    }
    return tnum-num;
}