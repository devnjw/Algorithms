#include <iostream>
#include <vector>

using namespace std;

int N, num;
int placed[22][22];
int numBF[22][22];
int numBlank[22][22];

int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int BFs[21][4];

void search(int r, int c){
  for(int i=0; i<4; ++i){
    for(int j=0; j<4; ++j){
      if(placed[r+dir[i][0]][c+dir[i][1]] == BFs[num][j])
        numBF[r][c]++;
    }
    if(r+dir[i][0]>0 && r+dir[i][0]<=N && c+dir[i][1]>0 && c+dir[i][1]<=N)
      if(placed[r+dir[i][0]][c+dir[i][1]] == 0)
        numBlank[r][c]++;
  }
}

void place(){
  for(int r=1; r<=N; ++r)
    for(int c=1; c<=N; ++c)
      if(placed[r][c]==0)
        search(r, c);

  int mx=0, mx_cnt=N*N;
  int mxR, mxC;
  for(int r=1; r<=N; ++r){
    for(int c=1; c<=N; ++c){
      if(placed[r][c]==0){
        if(numBF[r][c]>mx){
          mx=numBF[r][c];
          mx_cnt=1;
          mxR = r;
          mxC = c;
        }
        else if(numBF[r][c]==mx){
          mx_cnt++;
        }
      }
    }
  }

  if(mx_cnt==1){
    placed[mxR][mxC] = num;
    return;
  }

  int mxBlank = -1;
  int mxBlankR=0, mxBlankC=0;
  for(int r=1; r<=N; ++r){
    for(int c=1; c<=N; ++c){
      if(placed[r][c]==0){
        if(numBF[r][c]==mx && numBlank[r][c] > mxBlank){
          mxBlank = numBlank[r][c];
          mxBlankR = r;
          mxBlankC = c;
        }
      }
    }
  }

  placed[mxBlankR][mxBlankC] = num;

}

void clearAll(){
  for(int r=1; r<=N; ++r){
    for(int c=1; c<=N; ++c){
      numBF[r][c] = 0;
    }
  }
  for(int r=1; r<=N; ++r){
    for(int c=1; c<=N; ++c){
      numBlank[r][c] = 0;
    }
  }
}

int main(){
  cin >> N;

  for(int i=0; i<N*N; ++i){
    cin >> num >> BFs[num][0] >> BFs[num][1] >> BFs[num][2] >> BFs[num][3];
    place();
    clearAll();
  }

  int answer = 0;
  for(int r=1; r<=N; ++r){
    for(int c=1; c<=N; ++c){
      cout << placed[r][c] << " ";
      int cnt = 0;
      for(int i=0; i<4; ++i){
        for(int j=0; j<4; ++j){
          if(placed[r+dir[i][0]][c+dir[i][1]] == BFs[placed[r][c]][j])
            cnt++;
        }
      }
      if(cnt==1) answer+=1;
      else if(cnt==2) answer+=10;
      else if(cnt==3) answer+=100;
      else if(cnt==4) answer+=1000;
    }
    cout << "\n";
  }

  cout << answer;

  return 0;
}
