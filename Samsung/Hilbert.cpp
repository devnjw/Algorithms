#include <iostream>
#include <algorithm>

using namespace std;

struct Point{
    int x;
    int y;
};

Point Transform(int n, int num) {
  Point p = {0, 0};

  num--;
  int c = 1;

  while(n>0){
    n--;
    int div = pow(4, n);

    if(c!=3){
      switch (num/div) {
        case 1:
          if(c==0)
            p.y += pow(2, n);
          else
            p.x += pow(2, n);
          c = 1;
          break;
        case 2:
          p.x += pow(2, n);
          p.y += pow(2, n);
          c = 2;
          break;
        case 3:
          if(c==0)
            p.x += pow(2, n);
          else
            p.y += pow(2, n);
          c = 3;
          break;
        default:
          c = 0;
      }
    }
    else {
      switch (num/div) {
        case 1:
          p.x = pow(2, n);
          c = 1;
          break;
        case 0:
          p.x += pow(2, n);
          p.y += pow(2, n);
          c = 2;
          break;
        case 3:
          p.y += pow(2, n);
          c = 3;
          break;
        default:
          c = 0;
      }
    }

    num %= div;
  }

  p.x *= 10;
  p.y *= 10;

  return p;
}

int Length(Point p1, Point p2) {
  float result = sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
  return floor(result + 0.5);
}

int TS, N, A, B;

int main() {
  cin >> TS;
  for(int i=0; i<TS; ++i){
    cin >> N >> A >> B;
    Point p1 = Transform(N, A);
    Point p2 = Transform(N, B);
    printf("%d %d | %d %d\n", p1.x, p1.y, p2.x, p2.y);
    printf("#%d %d\n", i+1, Length(p1, p2));
  }
  return 0;
}
