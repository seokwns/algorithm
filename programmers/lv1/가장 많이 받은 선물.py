def solution(friends, gifts):
    answer = 0
    n = len(friends)
    table = [[0 for j in range(n)] for i in range(n)]

    idx = {}
    point = [0 for i in range(n)]
    for i in range(n):
        idx[friends[i]] = i
        point[i] = 0

    for gift in gifts:
        sp = gift.split(' ')
        src = sp[0]
        dst = sp[1]
        src_idx = idx[src]
        dst_idx = idx[dst]
        table[src_idx][dst_idx] += 1
        point[src_idx] += 1
        point[dst_idx] -= 1

    for y in range(n):
        count = 0
        for x in range(n):
            if x == y:
                continue
            give = table[y][x]
            receive = table[x][y]

            if give > receive:
                count += 1
            elif give == receive:
                if point[y] > point[x]:
                    count += 1
        if count > answer:
            answer = count

    return answer


print(solution(
    ["muzi", "ryan", "frodo", "neo"],
    ["muzi frodo", "muzi frodo", "ryan muzi", "ryan muzi", "ryan muzi", "frodo muzi", "frodo ryan", "neo muzi"]
))

print(solution(
    ["joy", "brad", "alessandro", "conan", "david"],
    ["alessandro brad", "alessandro joy", "alessandro conan", "david alessandro", "alessandro david"]
))