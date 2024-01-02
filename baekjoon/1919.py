a = input()
b = input()

ma = {}
mb = {}

for i in a:
    ma[str(i)] = ma.get(str(i), 0) + 1

for j in b:
    mb[str(j)] = mb.get(str(j), 0) + 1

answer = 0
for k in set(ma.keys()) | set(mb.keys()):
    va = ma.get(k, 0)
    vb = mb.get(k, 0)
    answer += abs(va - vb)

print(answer)
