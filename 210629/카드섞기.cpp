#include <iostream>
using namespace std;
int N, k[2];
int init[1001], temp[1001][3];

bool recur(int n=0){
	if(n==2){
		for(int i=0; i<N; i++)if(temp[i][n]!=init[i])return false;
		return true;
	}
	for(int i=1; i<10; i++){
		if((1<<i)>N)break;
		int idx=i, num=N;
		int index=1<<i, t=num-index, tt=0;
		while(idx>=0){
			for(int j=0; j<t; j++){
				temp[j+index][n+1]=temp[j+tt][n];
			}
			tt+=t;
			t=index>>1;
			if(idx>0)index=1<<(--idx);
			else idx--;
		}
		temp[0][n+1]=temp[tt][n];
		k[n]=i;
		if(recur(n+1)) return true;
	}
	return false;
}

int main(void){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>N;
	for(int i=0; i<N; i++){cin>>init[i];temp[i][0]=i+1;}
	recur();
	for(int i=0; i<2; i++)cout<<k[i]<<" ";
}