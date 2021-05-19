#include <iostream>

using namespace std;

int main(){
  string A;
  string B;
  cin >> A >> B;

  string answer1 = "";
  string answer2 = "";
  string answer3 = "";
  string answer4 = "";
  string answer5 = "";

  for(int i=0; i<A.size(); ++i){
    answer1 += A[i] & B[i];
    answer2 += A[i] | B[i];
    answer3 += A[i] != B[i] ? '1' : '0';
    answer4 += A[i] == '1' ? '0' : '1';
    answer5 += B[i] == '1' ? '0' : '1';
  }

  cout << answer1 << endl;
  cout << answer2 << endl;
  cout << answer3 << endl;
  cout << answer4 << endl;
  cout << answer5 << endl;

  return 0;
}
