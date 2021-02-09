#include <vector>
#include <iostream>
#include <algorithm>
#include <time.h>

using namespace std;

int cnt_swap_my = 0;
int cnt_swap_heap = 0;

void Print(vector<int> v){
  for(int i=0; i<v.size(); ++i){
    printf("%d ",v[i]);
  }
  printf("\n");
}

void HeapsAlgorithm(int Size, vector<int> Array)
{
    if (Size == 1)
    {
        Print(Array);
        return;
    }
    else
    {
        HeapsAlgorithm(Size - 1, Array);

        for (int i = 0; i < Size - 1; ++i)
        {
            if (Size % 2 == 1)
                swap(Array[i], Array[Size - 1]);
            else
                swap(Array[0], Array[Size - 1]);
            cnt_swap_heap++;
            HeapsAlgorithm(Size - 1, Array);
        }
    }
}

void Permutation(vector<int> v, int index){

  if(index==v.size()){
    Print(v);
    return;
  }
  else{
    Permutation(v, index+1);

    for(int i=index+1; i<v.size(); ++i){
      cnt_swap_my++;
      swap(v[index], v[i]);
      Permutation(v, index+1);
    }
  }
}

int main(){
  clock_t start, end;
  double result;

  vector<int> v = {1, 2, 3, 4};

  cout << endl;

  start = clock();
  Permutation(v, 0);
  end = clock(); //시간 측정 끝
  result = (double)(end - start);
  printf("Time:%f, #Swap:%d\n", result, cnt_swap_my);

  start = clock();
  HeapsAlgorithm(v.size(), v);
  end = clock(); //시간 측정 끝
  result = (double)(end - start);
  printf("Time:%f, #Swap:%d\n", result, cnt_swap_heap);



  return 0;
}
