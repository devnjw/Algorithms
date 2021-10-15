#include <iostream>
#include <vector>

using namespace std;

int N, square, h, w;
int board[20][20];
int polys[5][4][4];
vector<pair<int, int> > scale;

bool search(int poly);
bool is_empty_space(int poly, int r, int c);
void put_block(int poly, int r, int c);
void remove_block(int poly, int r, int c);
void print_board();

int main(){
  cin >> N;
  for(int i=0; i<N; ++i){
    cin >> h >> w;
    scale.push_back(make_pair(h, w));
    for(int r=0; r<h; ++r){
      for(int c=0; c<w; ++c){
        cin >> polys[i][r][c];
        if(polys[i][r][c])
          square++;
      }
    }
  }

  for(int i=1; i<=square; ++i){
    if(i*i==square){
      square = i;
      break;
    }
  }

  if(search(0)==true)
    print_board();
  else
    printf("No solution possible");

  return 0;
}

bool search(int poly){
  if(poly==N){
    return true;
  }

  for(int r=0; r<=square-scale[poly].first; ++r){
    for(int c=0; c<=square-scale[poly].second; ++c){
      if(is_empty_space(poly, r, c)){
        put_block(poly, r, c);
        if(search(poly+1))
          return true;
        remove_block(poly, r, c);
      }
    }
  }

  return false;
}

bool is_empty_space(int poly, int r, int c){
  for(int y=0; y<scale[poly].first; ++y){
    for(int x=0; x<scale[poly].second; ++x){
      if(polys[poly][y][x]==1){
        if(board[r+y][c+x]){
          return false;
        }
      }
    }
  }
  return true;
}

void put_block(int poly, int r, int c){
  for(int y=0; y<scale[poly].first; ++y){
    for(int x=0; x<scale[poly].second; ++x){
      if(polys[poly][y][x]==1){
        board[r+y][c+x]=poly+1;
      }
    }
  }
}

void remove_block(int poly, int r, int c){
  for(int y=0; y<scale[poly].first; ++y){
    for(int x=0; x<scale[poly].second; ++x){
      if(polys[poly][y][x]==1){
        board[r+y][c+x]=0;
      }
    }
  }
}

void print_board(){
  for(int i=0; i<square; ++i){
    for(int j=0; j<square; ++j){
      cout << board[i][j] << " ";
    }
    cout << "\n";
  }
}
