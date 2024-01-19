def solution(n, l, r):
    answer = 0

    def check(number):
        if number % 5 == 2:
            return False
        if number < 5:
            return True

        return check(number // 5)

    for i in range(l-1, r):
        if check(i):
            answer += 1

    return answer


print(solution(2, 4, 17))
