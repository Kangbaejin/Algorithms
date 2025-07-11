from itertools import combinations, permutations, product

def solution(n: int, q: list, ans: list) -> int:
    answer = 0
    q = [set(i) for i in q]
    candidates = [set(i) for i in combinations([i for i in range(1, n+1)], 5)]
    for candidate in candidates:
        for target, r in zip(*[q, ans]):
            if len(target & candidate) != r:
                break
        else:
            answer += 1
    
    return answer