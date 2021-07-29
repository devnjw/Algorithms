#include <iostream>
using namespace std;

int Factorial(int n){
  if(n==1) return 1;
  return n*Factorial(n-1);
}

int Comb(int n, int r){
  // n! / (r! * (n-r)!)
  return Factorial(n)/(Factorial(r)*Factorial(n-r));
}

int main(){
  cout << Comb(4, 1) << endl;
  cout << Comb(5, 2) << endl;

  return 0;
}
