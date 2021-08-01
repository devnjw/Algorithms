#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef Stone{
  int color;
  int point;
}

int N;
vector<Stone> v;

int main(){
  cin >> N;
  for(int i=0; i<N; ++i){
    Stone stone = new Stone();
    char color;
    cin >> color;
    if(color=='W') stone->color = 1;
    else stone->color = 0;
    v.push_back(stone);
  }

  for(int i=0; i<N; ++i){
    int 
  }

  return 0;
}
