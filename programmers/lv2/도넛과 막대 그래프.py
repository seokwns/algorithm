def solution(edges):
    answer = [0, 0, 0, 0]

    counter = {}
    for src, dst in edges:
        if not counter.get(src):
            counter[src] = [0, 0]
        if not counter.get(dst):
            counter[dst] = [0, 0]

        counter[src][0] += 1
        counter[dst][1] += 1

    for key, value in counter.items():
        if value[0] >= 2 and value[1] == 0:
            answer[0] = key
        elif value[0] == 0 and value[1] > 0:
            answer[2] += 1
        elif value[0] >= 2 and value[1] >= 2:
            answer[3] += 1

    answer[1] = counter[answer[0]][0] - answer[2] - answer[3]

    return answer


print(solution([[2, 3], [4, 3], [1, 1], [2, 1]]))
