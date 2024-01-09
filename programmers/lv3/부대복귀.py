from collections import deque


def solution(n, roads, sources, destination):
    answer = []
    costs = [-1 for i in range(n+1)]
    neighbors = [[] for _ in range(n+1)]

    for src, dst in roads:
        neighbors[src].append(dst)
        neighbors[dst].append(src)

    que = deque([destination])
    costs[destination] = 0

    while que:
        cursor = que.popleft()
        for neighbor in neighbors[cursor]:
            if costs[neighbor] == -1:
                costs[neighbor] = costs[cursor] + 1
                que.append(neighbor)

    for source in sources:
        answer.append(costs[source])

    return answer


print(solution(3, [[1, 2], [2, 3]], [2, 3], 1))
