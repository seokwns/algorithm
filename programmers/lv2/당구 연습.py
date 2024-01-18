from sys import maxsize


def get_distance(src, dst):
    dx = src[0] - dst[0]
    dy = src[1] - dst[1]

    return dx ** 2 + dy ** 2


def get_min_distance(m, n, start, ball):
    [x, y] = ball
    candidates = []

    if not (start[0] == ball[0] and start[1] > ball[1]):
        candidates.append([x, -y])
    if not (start[1] == ball[1] and start[0] > ball[0]):
        candidates.append([-x, y])
    if not (start[1] == ball[1] and start[0] < ball[0]):
        candidates.append([m + (m - x), y])
    if not (start[0] == ball[0] and start[1] < ball[1]):
        candidates.append([x, n + (n - y)])

    min_distance = maxsize
    for candidate in candidates:
        current_distance = get_distance(start, candidate)
        if current_distance < min_distance:
            min_distance = current_distance

    return min_distance


def solution(m, n, startX, startY, balls):
    answer = []
    start = [startX, startY]

    for ball in balls:
        answer.append(get_min_distance(m, n, start, ball))

    return answer


print(solution(10, 10, 3, 7, [[7, 7], [2, 7], [7, 3]]))
