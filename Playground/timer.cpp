#include <stdio.h>
#include <time.h>

int main() {

    clock_t start = clock();

    for (;;) {
        clock_t end = clock();
        double time = double(end - start); //초단위 변환
        printf("경과시간 : %0.3lf\n", time); //소수점 셋째 자리까지
    }
}
