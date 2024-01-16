table = [[(r, c) for c in range(51)] for r in range(51)]
values = [["EMPTY" for c in range(51)] for r in range(51)]


def find(r, c):
    if (r, c) == table[r][c]:
        return r, c
    (nr, nc) = table[r][c]
    table[r][c] = find(nr, nc)
    return table[r][c]


def find_all(src, dst):
    for r in range(51):
        for c in range(51):
            if values[r][c] == src:
                values[r][c] = dst


def merge(sp):
    ir, ic = int(sp[1]), int(sp[2])
    r, c = find(ir, ic)
    dr, dc = int(sp[3]), int(sp[4])
    r2, c2 = find(dr, dc)

    if (ir, ic) == (dr, dc):
        return

    value1 = values[r][c]
    value2 = values[r2][c2]

    for pr in range(51):
        for pc in range(51):
            if table[pr][pc] == (r2, c2):
                table[pr][pc] = (r, c)

    if value1 == "EMPTY" and value2 != "EMPTY":
        values[r][c] = values[r2][c2]

    table[r2][c2] = (r, c)


def unmerge(sp):
    ir, ic = int(sp[1]), int(sp[2])
    r, c = find(ir, ic)
    value = values[r][c]
    for pr in range(51):
        for pc in range(51):
            if table[pr][pc] == (r, c):
                table[pr][pc] = (pr, pc)
                values[pr][pc] = "EMPTY"
    table[ir][ic] = (ir, ic)
    values[ir][ic] = value


def solution(commands):
    answer = []

    for line in commands:
        sp = line.split(" ")
        command = sp[0]

        if command == "UPDATE":
            if len(sp) == 4:
                ir, ic = int(sp[1]), int(sp[2])
                r, c = find(ir, ic)
                values[r][c] = sp[3]
            elif len(sp) == 3:
                find_all(sp[1], sp[2])
        elif command == "MERGE":
            merge(sp)
        elif command == "UNMERGE":
            unmerge(sp)
        elif command == "PRINT":
            ir, ic = int(sp[1]), int(sp[2])
            r, c = find(ir, ic)
            answer.append(values[r][c])

    return answer


print(solution(["UPDATE 1 1 menu", "UPDATE 1 2 category", "UPDATE 2 1 bibimbap", "UPDATE 2 2 korean", "UPDATE 2 3 rice", "UPDATE 3 1 ramyeon", "UPDATE 3 2 korean", "UPDATE 3 3 noodle", "UPDATE 3 4 instant", "UPDATE 4 1 pasta", "UPDATE 4 2 italian", "UPDATE 4 3 noodle", "MERGE 1 2 1 3", "MERGE 1 3 1 4", "UPDATE korean hansik", "UPDATE 1 3 group", "UNMERGE 1 4", "PRINT 1 3", "PRINT 1 4"]))
