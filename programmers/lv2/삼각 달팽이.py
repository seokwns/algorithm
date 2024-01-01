def solution(n):
    answer = [[0 for j in range(1, i + 1)] for i in range(1, n + 1)]

    number = 1
    x, y = -1, 0

    for i in range(n):
        for j in range(i, n):
            if i % 3 == 0:
                x += 1
            elif i % 3 == 1:
                y += 1
            else:
                x -= 1
                y -= 1

            answer[x][y] = number
            number += 1

    return sum(answer, [])


print(solution(4))
