def solution(land):
    answer = 0
    n = len(land)
    m = len(land[0])
    
    result = [0 for i in range(m+1)]
    visited = [[False for i in range(m)] for j in range(n)]
    
    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]
    
    def bfs(bx, by):
        buffer = [[bx, by]]
        count = 0
        min_y, max_y = by, by
        visited[bx][by] = 1
        
        while len(buffer) != 0:
            count += 1
            x, y = buffer.pop()
            min_y = min(min_y, y)
            max_y = max(max_y, y)
            
            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]
                
                if nx < 0 or ny < 0 or nx >= n or ny >= m:
                    continue
                
                if visited[nx][ny] == 0 and land[nx][ny] == 1:
                    visited[nx][ny] = 1
                    buffer.append([nx, ny])
        
        for i in range(min_y, max_y+1):
            result[i] += count

    for x in range(n):
        for y in range(m): 
            if not visited[x][y] and land[x][y] == 1:
                bfs(x, y)
            
    answer = max(result)
    return answer
