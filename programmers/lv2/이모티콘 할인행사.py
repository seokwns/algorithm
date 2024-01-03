def solution(users, emoticons):
    sales = [10, 20, 30, 40]
    discounts = []

    def dfs(temp, depth):
        if depth == len(temp):
            discounts.append(temp[:])
            return

        for sale in sales:
            temp[depth] += sale
            dfs(temp, depth + 1)
            temp[depth] -= sale

    dfs([0] * len(emoticons), 0)

    answer = [0, 0]
    for discount in discounts:
        plus = 0
        price = 0

        for user in users:
            user_discount = user[0]
            user_limit = user[1]
            user_price = 0

            for i in range(len(emoticons)):
                if discount[i] >= user_discount:
                    user_price += emoticons[i] * (100 - discount[i]) / 100
                    if user_price >= user_limit:
                        user_price = 0
                        plus += 1
                        break

            price += user_price

        if answer[0] < plus:
            answer = [plus, price]
        elif answer[0] == plus:
            if answer[1] < price:
                answer = [plus, price]

    return answer


print(solution(
    [[40, 10000], [25, 10000]],
    [7000, 9000]
))
