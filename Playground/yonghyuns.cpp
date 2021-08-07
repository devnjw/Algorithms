#include <string>
#include <vector>
#include <time.h>

using namespace std;

int arr[1000001];

int solution(int n) {
    int answer = 0;
    int digit = 0;

    for (int i = 0; i < n; i++)
    {
        digit += i;
        int share = n - digit;
        int div = i + 1;

        if (share >= div && share % div == 0) answer++;
    }

    return answer;
}

int jinwoo(int n) {
    int answer = 0;

    arr[1] = 1;
    for(int i=2; i<=n; ++i)
        arr[i] = arr[i-1] + i;

    int l = n-1, r = n;
    while(l >= 0){
        if(arr[r] - arr[l] == n){
            answer++;
            l--;
        }
        while(arr[r] - arr[l] > n) r--;
        while(arr[r] - arr[l] < n) l--;
    }

    return answer;
}

int yonghyun(int k) {
    int answer = 0;

    for(int n=1; ; ++n){
      int tmp = k - n * (n-1) / 2;
      if(tmp<=0) break;
      if(tmp%n==0) answer++;
    }

    return answer;
}

int main(){
  clock_t start, end;

  start = clock();
  printf("Jinwoo's Answer: %d\n",jinwoo(1000000));
  end = clock();
  double time = double(end - start); //초단위 변환
  printf("경과시간 : %0.3lf\n\n", time); //소수점 셋째 자리까지

  start = clock();
  printf("Yonghyun's Answer: %d\n",yonghyun(1000000));
  end = clock();
  time = double(end - start); //초단위 변환
  printf("경과시간 : %0.3lf\n", time); //소수점 셋째 자리까지


  return 0;
}
