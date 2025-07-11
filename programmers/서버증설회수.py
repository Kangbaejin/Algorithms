def solution(players, m, k):
    
    answer = 0
    server_state = [0]*24
    
    q = 0
    for i in range(24):
        q = players[i]//m
        if q >= server_state[i] :
            diff = q - server_state[i]
            answer += diff
            for j in range(i,i+k):
                if j >= 24 : break
                server_state[j] += diff
        
        
        
    return answer