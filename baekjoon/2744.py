answer = [c.upper() if c.islower() else c.lower() for c in input()]
print(''.join(answer))
