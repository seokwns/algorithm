def solution(h1, m1, s1, h2, m2, s2):
    answer = -1

    def get_count(h, m, s):
        # 분침은 정각에서 1번씩 덜 마주치기 때문에 1시간마다 59번을 마주치고
        # 시침은 항상 고정적으로 1분당 한번씩 마주치기 때문에 60번
        # 그리고 분마다 1번씩 더해준다
        m_count = h * 59 + m
        h_count = h * 60 + m

        result = 0

        # 12:00 에서 겹칠 때 한번만 울리는데
        # 이때는 시침도 1번 덜 울리고
        # 분침은 울리지 않기 때문에 2개를 빼야한다
        # 왜냐하면 12시라서 울리면 다음 한바퀴 동안은 시침도 안마주치고 분침도 안마주치기 때문이다
        if h >= 12:
            h_count -= 1
            m_count -= 1

        current_minute_degree = m * 6
        current_hour_degree = 30 * (h % 12) + 0.5 * m

        # 1초마다 분침은 1/10도 움직인다 (6 / 60)
        # 1초마다 시침은 1/120 도 움직인다 (30 / 3600)
        minute_pass = current_minute_degree + 0.1 * s <= 6 * s
        hour_pass = current_hour_degree + 1 / 120 * s <= 6 * s

        if minute_pass:
            m_count += 1
        if hour_pass:
            h_count += 1

        return m_count + h_count

    answer = get_count(h2, m2, s2) - get_count(h1, m1, s1)

    # 시작이 0분 0초면 시작할 때 1번 울리기 때문에 1 더하기
    if m1 == s1 == 0:
        answer += 1

    return answer


print(solution(0, 5, 30, 0, 7, 0))
print(solution(0, 0, 0, 23, 59, 59))
