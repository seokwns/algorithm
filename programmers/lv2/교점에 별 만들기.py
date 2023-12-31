from itertools import combinations


def calculation(line1, line2):
    a1, b1, c1 = line1
    a2, b2, c2 = line2

    if a1 * b2 - a2 * b1 == 0:
        return

    x = (b1 * c2 - c1 * b2) / (a1 * b2 - b1 * a2)
    y = (c1 * a2 - a1 * c2) / (a1 * b2 - b1 * a2)

    if x == int(x) and y == int(y):
        return [int(x), int(y)]


def solution(line):
    answer = []
    dots = []

    for line1, line2 in combinations(line, 2):
        dot = calculation(line1, line2)
        if dot:
            dots.append(dot)

    min_x, max_x = min(dots, key=lambda mx: mx[0])[0], max(dots, key=lambda mx: mx[0])[0] + 1
    min_y, max_y = min(dots, key=lambda mx: mx[1])[1], max(dots, key=lambda mx: mx[1])[1] + 1

    answer = [['.'] * (max_x - min_x) for _ in range(max_y - min_y)]

    for x, y in dots:
        answer[y - min_y][x - min_x] = '*'

    answer.reverse()
    return [''.join(a) for a in answer]


print(solution([[2, -1, 4], [-2, -1, 4], [0, -1, 1], [5, -8, -12], [5, 8, 12]]))
