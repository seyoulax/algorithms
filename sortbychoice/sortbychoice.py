def sortOne(arr):
    smallest = arr[0]
    index = 0
    for i in range(len(arr)):
        if arr[i] < smallest:
            smallest = arr[i]
            index = i
    return index

def sortByChoice(arr):
    newArr = []
    for i in range(len(arr)):
        smallest = sortOne(arr)
        newArr.append(arr[smallest])
        arr.pop(smallest)
    return newArr

print(sortByChoice([7, 6, 3, 10, 35, 3]))

