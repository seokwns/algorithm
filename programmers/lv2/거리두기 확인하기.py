def check_place(place):
    for x in range(5):
        for y in range(5):
            if place[x][y] != 'P':
                continue

            for dx in range(-2, 3):
                for dy in range(-2, 3):
                    if not (0 <= x + dx < 5 and 0 <= y + dy < 5) or (dx == 0 and dy == 0):
                        continue

                    if place[x + dx][y + dy] == 'P':
                        diff = abs(dx) + abs(dy)
                        if diff > 2:
                            continue
                        elif diff == 2:
                            if abs(dx) == 2:
                                cursor = place[x + int(dx / 2)][y]
                                if cursor == 'O':
                                    return 0
                            elif abs(dy) == 2:
                                cursor = place[x][y + int(dy / 2)]
                                if cursor == 'O':
                                    return 0
                            else:
                                cursor1, cursor2 = place[x][y + dy], place[x + dx][y]
                                if not (cursor1 == 'X' and cursor2 == 'X'):
                                    return 0
                        elif diff == 1:
                            return 0

    return 1


def solution(places):
    answer = []

    for place in places:
        sp = [[char for char in row] for row in place]
        result = check_place(sp)
        answer.append(result)

    return answer


print(solution(
    [["POOOO", "XPOOO", "OOOOO", "OOOOO", "OOOOO"], ["OOOOO", "OOOOO", "OOOOO", "OOOOO", "OOOOO"], ["PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"], ["OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"], ["PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"]]
))
