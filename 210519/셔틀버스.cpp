#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int tt(const string & str){
    int h=0,m=0;
    string hh=str.substr(0,2), mm=str.substr(3,2);
    for(int i=0; i<2; i++){
        h*=10,m*=10;
        h+=hh[i]-'0',m+=mm[i]-'0';
    }
    return h*60+m;
}
string tt2(const int& n){
    char hh[3],mm[3];hh[2]='\0',mm[2]='\0';
    int h=n/60,m=n%60;
    for(int i=1; i>=0; i--){
        hh[i]=h%10+'0',mm[i]=m%10+'0';
        h/=10,m/=10;
    }
    return(string)hh+":"+(string)mm;
}
string solution(int n, int t, int m, vector<string> timetable) {
    sort(timetable.begin(),timetable.end());
    vector<int> timeset,bus[11];
    int stime=tt("09:00"), con=0;
    for(int i=0; i<n; i++){
        timeset.push_back(stime+t*i);
    }

    for(auto str : timetable){
        int time=tt(str);
        int n=lower_bound(timeset.begin(),timeset.end(),time)-timeset.begin();
        while(bus[n].size()==m&&n<10)n++;
        bus[n].push_back(time);
    }
    
    if(bus[n-1].size()<m)con=timeset.back();
    else con=bus[n-1][m-1]-1;

    return tt2(con);
}