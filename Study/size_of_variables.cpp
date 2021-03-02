#include <iostream>
#include <vector>
using namespace std;

int main(){
  vector<int> v;
  int istr = sizeof(v);
  cout << "Empty vector is " << istr << " bytes long" << endl;

  v.push_back(10);
  v.push_back(20);
  istr = sizeof(v);
  cout << "Vector with 2 elements is " << istr << " bytes long" << endl;

  int integer;
  istr = sizeof(integer);
  cout << "Empty integer is " << istr << " bytes long" << endl;

  string str;
  istr = sizeof(str);
  cout << "Empty string is " << istr << " bytes long" << endl;

  string str2(1, 'a');
  istr = sizeof(str2);
  cout << "1 character string is " << istr << " bytes long" << endl;

  string str3("Test string that is longer then 24 characters.");
  istr = sizeof(str3);
  cout << "the test string is " << istr << " bytes long" << endl;

  istr = sizeof(str3[1]);
  cout << "sizeof str3[1] is " << istr << " bytes long" << endl;

  cout << "Hello world!" << endl;
}
