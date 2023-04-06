# def binary_search(sorted, n):
#     high = len(sorted) - 1
#     low = 0
#     while high >= low:
#         mid = (low + high) // 2
#         guess = sorted[mid]
#         if guess == n:
#             return mid
#         elif guess > n:
#             high = mid - 1
#         else:
#             low = mid + 1
#     return None

def binary_search(arr, l, r, x):
    if r >= l:
        mid = (l + r) // 2
        if arr[mid] == x:
            return mid
        elif arr[mid] > x:
            return binary_search(arr, l, mid - 1, x)
        else:
            return binary_search(arr, mid + 1, r, x)
    else:
        return None

print(binary_search([0, 2, 5, 6, 7, 67, 109], 0, 6, 109))

