def solution(n):
    answer = list(str(n))
    buffer = []
    for i in answer:
        buffer.append(int(i))

    buffer.reverse()

    return buffer


print(solution(12345))

