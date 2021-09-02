#include <string>
#include <time.h>

using namespace std;

int solution(int n) {
    clock_t start, end;
    start = clock();

    // your code

    end = clock();

    printf("Timer : %.2f",((float)(end - start) / CLOCKS_PER_SEC));

    return 0;
}
