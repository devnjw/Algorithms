def solution(absolutes, signs):
    answer = 0
    for num, sign in zip(absolutes, signs):
        if not sign:
            num *= -1;
        answer += num;
    return answer
