def solution(m, n, puddles):
    arr = [[0]*(m+1) for i in range(n+1)]

    if puddles != [[]]:
        for a, b in puddles:
            arr[b][a] = -1

    arr[1][1] = 1

    for i in range(1, n+1):
        for j in range(1, m+1):
            if i*j==1:
                continue
            if arr[i][j] == -1:
                arr[i][j] = 0
                continue
            arr[i][j] = (arr[i-1][j] + arr[i][j-1])%1000000007

    return arr[n][m]
