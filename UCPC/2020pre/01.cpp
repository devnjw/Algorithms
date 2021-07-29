#include <iostream>

using namespace std;

int main(){
  float a, b, c, d, e, f;
  float x, y;
  
  cin >> a >> b >> c >> d >> e >> f;

  x = (e*c - b*f)/(e*a - d*b);
  y = (a*f - d*c)/(a*e - d*b);

  cout << (int)x << " " << (int)y;

  return 0;
}
