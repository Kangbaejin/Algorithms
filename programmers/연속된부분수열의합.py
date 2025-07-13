def solution(sequence, k):
    
    len_seq = len(sequence)
    answer = [0, len_seq]
    total = sequence[0]
    
    
    s,e = 0, 0
    while s < len_seq:
        if total < k :
            e += 1
            if e == len_seq : break
            total += sequence[e]
        else:
            if total == k:
                if e-s < answer[1]-answer[0]:
                    answer = [s,e]
                    
            total -= sequence[s]
            s += 1

    
    return answer