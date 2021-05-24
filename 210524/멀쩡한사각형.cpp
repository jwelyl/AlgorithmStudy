
using namespace std;
typedef long long ll;
int GCD(int a, int b){
    if(b!=0)return GCD(b,a%b);
    return a;
}

ll solution(int w,int h) {
    ll answer = (ll)w*h;
    int n=GCD(w,h);
    

    return answer-w-h+n;
}