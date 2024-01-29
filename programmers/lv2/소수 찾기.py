import math
from itertools import permutations


def solution(numbers):
    answer = set()
    n = 10 ** (len(numbers))
    prime = [True for i in range(n)]
    prime[1] = False

    for i in range(2, int(math.sqrt(n))):
        if prime[i]:
            j = 2
            while i * j < n:
                prime[i*j] = False
                j += 1

    nums = list(numbers)
    perms = []
    for i in range(1, len(numbers) + 1):
        perms += list(permutations(nums, i))

    m = [int("".join(p)) for p in perms]
    for i in m:
        if i != 0 and prime[i]:
            answer.add(i)

    return len(answer)


print(solution("011"))
