#include <iostream>

using namespace std;

int main(){
  int num1, num2;
  cin >> num1 >> num2;

  int lcm = num1;
  int gcm = num1;

  while(num1%lcm!=0 || num2%lcm!=0)
    lcm--;

  while(gcm%num1!=0 || gcm%num2!=0)
    gcm++;

  cout << lcm << "\n" << gcm;

  return 0;
}


// 신기한 답안
// #include <stdio.h>
//
// int gcd(int x,int y){
//     return x%y==0?y:gcd(y,x%y);
// }
//
// int main(){
//     int a,b,c;
//     scanf("%d %d",&a,&b);
//     c=a>b?gcd(a,b):gcd(b,a);
//     printf("%d\n%d",c,a*b/c);
// }
