def solution(h1, m1, s1, h2, m2, s2):
    
    dh, dm, ds = 360/12/3600 , 360/60/60 , 360/360*6

    answer = 0
    
    ss = 3600*h1 + 60*m1 + s1
    es = 3600*h2 + 60*m2 + s2
    
    if ss == 0*3600 or ss == 12*3600:
        answer += 1
    
    while ss < es :
        ah, am, asec = (dh*ss)%360, (dm*ss)%360, (ds*ss)%360
        
        #360도를 넘어가서 0도로 변환되어 비교되는 경우 방지
        nah = 360 if (dh*(ss+1))%360 == 0 else (dh*(ss+1))%360
        nam = 360 if (dm*(ss+1))%360 == 0 else (dm*(ss+1))%360
        nasec = 360 if (ds*(ss+1))%360 == 0 else (ds*(ss+1))%360
        
        if ah > asec and nah <= nasec :
            answer += 1
        if am > asec and nam <= nasec :
            answer += 1
            
        if nah == nam == nasec : answer -= 1
        ss += 1

    return answer