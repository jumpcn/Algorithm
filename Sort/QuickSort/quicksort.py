def quicksort(a, l, r):
    left, right = l, r
    t = a[l]
    while l < r:
        while l < r and a[r] >= t: r -= 1
        a[l] = a[r]
        while l < r and a[l] <= t: l += 1
        a[r] = a[l]
    a[l] = t
    print a
    if left < l - 1: quicksort(a, left, l - 1)
    if l + 1 < right: quicksort(a, l + 1, right)

a = [3, 5, 1, 4, 9, 6, 0, 1]

quicksort(a, 0, len(a) - 1)

