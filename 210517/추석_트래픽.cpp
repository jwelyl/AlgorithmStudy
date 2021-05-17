#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
const int MAX=86401000;
int arr[MAX];

int tt1(const string & str){
    string h=str.substr(0,2);
    string m=str.substr(3,2);
    string s=str.substr(6,2);
    string x=str.substr(9,3);
    int hh=0,mm=0,ss=0,xx=0;
    for(int i=0; i<2; i++){
        hh*=10;mm*=10;ss*=10;xx*=10;
        hh+=h[i]-'0';mm+=m[i]-'0';ss+=s[i]-'0';xx+=x[i]-'0';
    }
    xx*=10;xx+=x[2]-'0';
    hh*=(60*60*1000);mm*=(60*1000);ss*=1000;
    return hh+mm+ss+xx;
}
int tt2(string str){
    int x=(str[0]-'0')*1000;
    int y=0;
    for(int i=0; i<3; i++){
        y*=10;
        if(i+2>=str.size()||str[i+2]=='s')continue;
        y+=str[i+2]-'0';
    }
    return x+y;
}
int solution(vector<string> lines) {
    int answer = 0,n=1;

    for(auto str : lines){
        int x = tt1(str.substr(11,12));
        int y = tt2(str.substr(24));
        for(int i=0; i<y; i++)
            if(x-i<=0){
                arr[0]++;
                break;
            }
            else arr[x-i]++;
        for(int i=1; i<1000; i++)
            arr[x+i]++;
    }
    for(int i=0; i<MAX; i++)answer=arr[i]>answer?arr[i]:answer;

    return answer;
}