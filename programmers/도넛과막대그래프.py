def solution(edges):


    max_node_num = 0
    for edge in edges :
        max_node_num = max(max_node_num, edge[0], edge[1])
        
    
    graph = [[] for _ in range(max_node_num+1)]
    end_node_count = [0] * (max_node_num+1)
    
    
    for edge in edges :
        start = edge[0]
        end = edge[1]
        end_node_count[end] += 1
        
        graph[start].append(end)
        


    
    answer = [0,0,0,0]
    
    
    for i in range(len(graph)) :
        #새로 추가한 정점 찾기
        if len(graph[i]) >= 2  and end_node_count[i] == 0 :
            answer[0] = i
        #막대모양 그래프 찾기
        elif len(graph[i]) == 0 and end_node_count[i] > 0 :
            answer[2] += 1
        #8자모양 그래프 찾기
        elif len(graph[i]) >= 2 and end_node_count[i] >= 2 :
            answer[3] += 1
            
    #새로 생긴 노드는 각 그래프에 간선을 연결한다.
    #따라서 도넛 모양 그래프 = 모든 그래프(새로 생긴 노드의 간선들 수) - 막대 모양 그래프 - 8자모양 그래프 
    answer[1] = len(graph[answer[0]]) - answer[2] - answer[3]
    
    
    
    return answer