#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void Print(vector<int> v){
  for(int i=0; i<v.size(); ++i){
    printf("%d ",v[i]);
  }
  printf("\n");
}

void Permutation(vector<int> v, int index){

  if(index!=v.size())
    Permutation(v, index+1);
  else
    Print(v);

  for(int i=index+1; i<v.size(); ++i){
    swap(v[index], v[i]);
    Permutation(v, index+1);
  }
}

void Combination()

int main(){
  vector<int> v = {1, 2, 3, 4};

  Permutation(v, 0);

  return 0;
}
