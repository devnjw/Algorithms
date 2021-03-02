//https://programmers.co.kr/learn/courses/30/lessons/42839#
//프로그래머스 완전탐색 소수 찾기 문제

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool is_prime(int num){
    if(num<=1) return false;
    for(int i=2; i<num; ++i)
        if(num%i==0) return false;
    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<int> primes;

    for(int size=1; size<=numbers.size(); ++size){
        vector<int> comb(numbers.size());
        for(int i=0; i<size; ++i){
            comb[i] = i+1;
        }
        sort(comb.begin(), comb.end());
        do{
            int num = 0;
            for(int i=0; i<comb.size(); i++){
                num += (numbers[i] - '0') * pow(10, comb[i]-1);
            }
            if(is_prime(num))
                primes.push_back(num);
        }while(next_permutation(comb.begin(),comb.end()));
    }

    sort(primes.begin(), primes.end());
    primes.erase(unique(primes.begin(),primes.end()),primes.end());

    return primes.size();
}
