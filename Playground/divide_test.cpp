#include <iostream>

using namespace std;

float Plot(int bx, int ax, float by, float ay, int target){
    cout << bx << " " << ax << " " << by << " " << ay << endl;
    float inclination = (by - ay) / (bx - ax);
    return target * inclination + by - (inclination * bx);
}

int main(){
  cout << Plot(500, 100, 15.5, 18.0, 1999);
  return 0;
}
