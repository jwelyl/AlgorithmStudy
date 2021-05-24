using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

long long solution(int w, int h) {
    return (long long)w * h - w - h + gcd(w, h);
}

// 전체 사각형 갯수에서 가로,세로를 빼고 가로세로의 최대공약수를 더해준다