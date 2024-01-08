n, m = map(int, input().split())
arr = [list(input()) for i in range(n)]

a = 0
b = 0

for i in range(n):
    if 'X' not in arr[i]:
        a += 1

for i in range(m):
    if 'X' not in [arr[j][i] for j in range(n)]:
        b += 1

print(max(a, b))
