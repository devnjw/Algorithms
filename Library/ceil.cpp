#include <iostream>

using namespace std;

int Ceil_f(float num){
  if((float)(int)num==num)
    return (int)num;
  return (int)num + 1;
}

int Floor(float num){
  return (int)num;
}

int main(){
  float N;
  cout << "Enter Test Number: " << endl;
  cin >> N;

  cout << "Ceiled Result: " << Ceil_f(N) << endl;
  cout << "Floored Result: " << Floor(N) << endl;
  return 0;
}
