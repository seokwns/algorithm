def solution(s):
    answer = []
    words = s.split(' ')
    for word in words:
        buf = ''
        for i in range(len(word)):
            if i == 0 or i % 2 == 0:
                buf += word[i].upper()
            else:
                buf += word[i].lower()
        answer.append(buf)

    return ' '.join(answer)

