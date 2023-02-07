
def phase4(x, lower, upper):
    mid = (upper - lower) // 2 + lower
    if x >= mid:
        if x <= mid:
            return 0
        else:
            return 1 + 2 * phase4(x, mid + 1, upper)
    else:
        return 2 * phase4(x, lower, mid - 1)

for i in range(15):
    res = phase4(i, 0, 14)
    print(f"phase4({i}, 0, 14) = {res}")
