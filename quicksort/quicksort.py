def qSort(arr):
    if len(arr) < 2:
        return arr
    else:
        mid = arr[0]
        less = [i for i in arr[1:] if i <= mid]
        high = [i for i in arr[1:] if i > mid]
        return qSort(less) + [mid] + qSort(high)

print(qSort([4, 2, 2, 6, 9, 10, 5, 3, 179, 65]))