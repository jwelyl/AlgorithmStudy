#include <iostream>
#include <cmath>
using namespace std;
int N,R;
int dr[4]={0,0,1,1},dc[4]={0,1,0,1};
int arr[1<<8][1<<8], temp[1<<8][1<<8];
void dosomething(int r, int c, int size, int num){
  if(num==1){
    for(int i=r; i<r+size/2; i++)
      for(int j=c; j<c+size; j++){
        int temp=arr[i][j];
        arr[i][j]=arr[size+r-1-(i-r)][j];
        arr[size+r-1-(i-r)][j]=temp;
      }
  }
  else if(num==2){
    for(int i=r; i<r+size; i++)
      for(int j=c; j<c+size/2; j++){
        int temp=arr[i][j];
        arr[i][j]=arr[i][size+c-1-(j-c)];
        arr[i][size+c-1-(j-c)]=temp;
      }
  }
  else{
    for(int i=r; i<r+size; i++)
      for(int j=c; j<c+size; j++)temp[i][j]=arr[i][j];
    if(num==3){
      for(int i=r; i<r+size; i++)
        for(int j=c; j<c+size; j++){
          arr[j-c+r][c+size-1-(i-r)]=temp[i][j];
        }
    }
    else{
    for(int i=r; i<r+size; i++)
      for(int j=c; j<c+size; j++)
        arr[i][j]=temp[j-c+r][c+size-1-(i-r)];
    }
  }
}

void divide(int size, int num, int nsize=N, int r=0, int c=0){
  if(size==nsize){
    dosomething(r,c,size,num);
    return;
  }
  for(int i=0; i<4; i++) divide(size,num,nsize/2,r+dr[i]*nsize/2,c+dc[i]*nsize/2);
}

void doothers(int size, int num){
  if(num==5){
    for(int i=0; i<N/2; i+=size)
      for(int j=0; j<size; j++){
        for(int k=0; k<N; k++){
          int temp=arr[i+j][k];
          arr[i+j][k]=arr[N-i-size+j][k];
          arr[N-size-i+j][k]=temp;
        }
      }
  }
  else if(num==6){
    for(int i=0; i<N/2; i+=size)
      for(int j=0; j<size; j++){
        for(int k=0; k<N; k++){
          int temp=arr[k][i+j];
          arr[k][i+j]=arr[k][N-i-size+j];
          arr[k][N-size-i+j]=temp;
        }
      }
  }
  else{
    for(int i=0; i<N; i++)
      for(int j=0; j<N; j++)temp[i][j]=arr[i][j];
    if(num==7){
      for(int i=0; i<N; i+=size)
        for(int l=0; l<N; l+=size)
          for(int j=0; j<size; j++)
            for(int k=0; k<size; k++){
              arr[l+j][N-size-i+k]=temp[i+j][l+k];
            }
    }
    else{
      for(int i=0; i<N; i+=size)
        for(int l=0; l<N; l+=size)
          for(int j=0; j<size; j++)
            for(int k=0; k<N; k++){
              arr[i+j][l+k]=temp[l+j][N-size-i+k];
            }
    }
  }
}

int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin>>N>>R; N=pow(2,N);
  for(int i=0; i<N; i++)for(int j=0; j<N; j++)cin>>arr[i][j];
  for(int i=0; i<R; i++){
    int k,l; cin>>k>>l;
    l=pow(2,l);
    if(k>=1&&k<=4)divide(l,k);
    else doothers(l,k);
  }

  for(int i=0; i<N; i++){for(int j=0; j<N; j++)cout<<arr[i][j]<<" ";
  cout<<'\n';}
}
