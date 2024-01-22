def solution(arr):
    answer = [0, 0]

    def check(x, y, size):
        itr = arr[y][x]
        for dy in range(y, y + size):
            for dx in range(x, x + size):
                if arr[dy][dx] != itr:
                    return False

        return True

    def divide_and_conquer(x, y, size):
        if check(x, y, size):
            idx = 0 if arr[y][x] == 0 else 1
            answer[idx] += 1
        else:
            size = size // 2
            divide_and_conquer(x, y, size)
            divide_and_conquer(x + size, y, size)
            divide_and_conquer(x, y + size, size)
            divide_and_conquer(x + size, y + size, size)

    divide_and_conquer(0, 0, len(arr))

    return answer


print(solution([[1, 1, 0, 0], [1, 0, 0, 0], [1, 0, 0, 1], [1, 1, 1, 1]]))
print(solution([[1, 1, 1, 1, 1, 1, 1, 1], [0, 1, 1, 1, 1, 1, 1, 1], [0, 0, 0, 0, 1, 1, 1, 1], [0, 1, 0, 0, 1, 1, 1, 1],
                [0, 0, 0, 0, 0, 0, 1, 1], [0, 0, 0, 0, 0, 0, 0, 1], [0, 0, 0, 0, 1, 0, 0, 1],
                [0, 0, 0, 0, 1, 1, 1, 1]]))
