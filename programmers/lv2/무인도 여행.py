import sys
sys.setrecursionlimit(10000)


def solution(maps):
    answer = []
    n = len(maps)
    m = len(maps[0])

    visited = [[0 for i in range(m)] for j in range(n)]

    def dfs(dx, dy, counter):
        if not (0 <= dx < m and 0 <= dy < n):
            return 0
        if maps[dy][dx] == 'X':
            return 0
        if visited[dy][dx] != 0:
            return 0
        visited[dy][dx] = 1

        counter += int(maps[dy][dx])
        counter += dfs(dx + 1, dy, 0)
        counter += dfs(dx - 1, dy, 0)
        counter += dfs(dx, dy + 1, 0)
        counter += dfs(dx, dy - 1, 0)

        return counter

    for y in range(n):
        for x in range(m):
            if maps[y][x] != 'X' and visited[y][x] == 0:
                count = dfs(x, y, 0)
                if count != 0:
                    answer.append(count)

    answer = sorted(answer)

    if len(answer) == 0:
        answer.append(-1)

    return answer


print(solution(["X591X", "X1X5X", "X231X", "1XXX1"]))
