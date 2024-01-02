def solution(arr1, arr2):
    w = len(arr2[0])
    h = len(arr1)
    answer = [[0 * i for i in range(w)] for j in range(h)]

    for i in range(h):
        for j in range(w):
            for k in range(len(arr1[0])):
                answer[i][j] += arr1[i][k] * arr2[k][j]

    return answer


print(solution(
    [[1, 4], [3, 2], [4, 1]],
    [[3, 3], [3, 3]]
))
