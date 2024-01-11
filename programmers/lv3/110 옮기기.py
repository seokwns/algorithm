def solution(s):
    answer = []

    for string in s:
        count, idx, stack = 0, 0, ""
        while idx < len(string):
            if string[idx] == '0' and stack[-2:] == "11":
                count += 1
                stack = stack[:-2]
            else:
                stack += string[idx]
            idx += 1

        idx = stack.rfind('0')
        if idx != -1:
            stack = stack[:idx+1] + "110" * count + stack[idx+1:]
        else:
            idx = stack.find("11")
            stack = stack[:idx] + "110" * count + stack[idx:]

        answer.append(''.join(stack))

    return answer


print(solution(["1110", "100111100", "0111111010"]))
