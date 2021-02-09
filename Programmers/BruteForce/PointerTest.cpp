#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void test(vector<int> &v){
  swap(v[0], v[2]);
  printf("%p %p %d %d\n", &v[0], &v, v[0], v[2]);

  //printf("size of vector: %u\n", v.size());

  for (const auto it : v)
      cout << it << "  " << &it << " " << endl;

  for (const auto &it : v)
      cout << it << "  " << &it << " " << endl;
}

void test2(int &a, int &b){
  swap(a, b);
  printf("%p %p %d %d\n", &a, &b, a, b);
}



int main(){

  int a = 1;
  int b = 3;

  printf("---------Integer Pointer---------\n");
  printf("%p %p %d %d\n", &a, &b, a, b);
  test2(a, b);
  printf("%p %p %d %d\n", &a, &b, a, b);
  printf("\n");

  vector<int> v = {1, 2, 3};;

  printf("----------Vector Pointer----------\n");
  printf("%p %p %d %d\n", &v[0], &v, v[0], v[2]);
  test(v);
  printf("%p %p %d %d\n", &v[0], &v, v[0], v[2]);



  //Permutation(v, 0);

  return 0;
}
