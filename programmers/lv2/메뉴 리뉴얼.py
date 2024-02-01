from itertools import combinations


def solution(orders, course):
    answer = []
    start = min(course)
    end = max(course)

    for i in course:
        menu_comb = {}

        for order in orders:
            order_combs = combinations(order, i)

            for order_comb in order_combs:
                comb_str = ''.join(sorted(order_comb))
                if menu_comb.get(comb_str):
                    menu_comb[comb_str] += 1
                else:
                    menu_comb[comb_str] = 1

        if len(menu_comb.values()) == 0:
            continue

        max_count = max(menu_comb.values())

        answer.extend([k for k, v in menu_comb.items() if (v == max_count and v >= 2)])

    return sorted(answer)


print(solution(["ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"], [2, 3, 4]))

print(solution(["ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"], [2, 3, 5]))

print(solution(["XYZ", "XWY", "WXA"], [2, 3, 4]))
