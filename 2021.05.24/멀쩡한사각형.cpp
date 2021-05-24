using namespace std;

long long gcd(int x, int y) {
    if(y == 0) return x;
    else return gcd(y, x % y);
}

long long solution(int w,int h) {
    long long answer = 0;
    int g = 0;
    long long temp = 0;
    
    g = gcd(w, h);
    temp = w + h - g;
    answer = ((long long)w * (long long)h) - temp;
    return answer;
}