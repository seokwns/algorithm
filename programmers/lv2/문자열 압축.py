def solution(s):
    strlen = len(s)
    answer = strlen

    for i in range(1, strlen):
        buffer = ""
        j = 0

        while j < strlen:
            count = 1
            itr = s[j:j+i]

            while True:
                j += i
                sub = s[j:j+i]
                if sub == itr:
                    count += 1
                else:
                    break

            j -= i

            if count > 1:
                buffer += str(count) + itr
            else:
                buffer += itr

            j += i

        if len(buffer) < answer:
            answer = len(buffer)

    return answer


print(solution("ababcdcdababcdcd"))
