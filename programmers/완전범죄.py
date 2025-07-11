def solution(info, n, m):
    L = len(info)
    INF = float('inf')
    # dp[i][b]: 첫 i개 아이템을 처리했을 때, B의 누적 흔적이 b일 때 A의 최소 누적 흔적
    dp = [[INF] * m for _ in range(L + 1)]
    dp[0][0] = 0

    for i in range(L):
        a_cost, b_cost = info[i]
        for b in range(m):
            if dp[i][b] == INF:
                continue
            # Case 1: 아이템 i를 A가 맡는 경우
            new_a = dp[i][b] + a_cost
            if new_a < n:  # A의 흔적이 n 미만이어야 함
                dp[i + 1][b] = min(dp[i + 1][b], new_a)
            # Case 2: 아이템 i를 B가 맡는 경우
            new_b = b + b_cost
            if new_b < m:  # B의 흔적이 m 미만이어야 함
                dp[i + 1][new_b] = min(dp[i + 1][new_b], dp[i][b])

    ans = min(dp[L])
    return ans if ans != INF else -1