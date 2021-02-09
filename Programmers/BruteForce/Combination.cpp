#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void Print(vector<int> v, int len){
  for(int i=0;i<len;++i)
    printf("%d ",v[i]);
  printf("\n");
}

void Combination(vector<int> v, int goal, int curr){

  if(curr==goal-1){
    Print(v, goal);
    for(int i=curr+1; i<v.size(); ++i){
      swap(v[curr], v[i]);
      Print(v, goal);
    }
  }
  else{
    Combination(v, goal, curr+1);
    for(int i = curr; i < v.size()-curr; ++i){
      swap(v[curr], v[v.size()-1]);
      swap(v[curr], v[i+1]);
      Combination(v, goal, curr+1);
    }
  }

}

int main(){
  vector<int> v = {1, 2, 3, 4};

  Combination(v, 2, 0);

  return 0;
}
