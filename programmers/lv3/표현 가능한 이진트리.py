def check_tree(bin_str):
    root = len(bin_str) // 2

    if root == 0:
        return True

    if bin_str[root] == '0':
        if '1' not in bin_str:
            return True
        return False

    left = bin_str[:root]
    right = bin_str[root + 1:]

    return check_tree(left) and check_tree(right)


def solution(numbers):
    answer = []
    bss = [1, 3, 7, 15, 31, 63]

    for number in numbers:
        bin_str = str(bin(number))[2:]
        length = len(bin_str)

        for bs in bss:
            if length == bs:
                break
            elif length < bs:
                bin_str = "0" * (bs - length) + bin_str
                break

        answer.append(1 if check_tree(bin_str) else 0)

    return answer


print(solution([7, 42, 5]))
