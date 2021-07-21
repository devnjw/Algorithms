#include <iostream>
#include <string>

using namespace std;

int main(){
  string numbers[2];
  numbers[0] = '0';
  numbers[1] = '1';

  cout << "Enter Decimal Number: ";
  int n;
  cin >> n;
  string s = "";
  while(n>0){
    s = numbers[n%2] + s;
    n /= 2;
  }
  cout << "Binary Numner: " << s;
  return 0;
}
