def counting_sort(arr):
    max_val = max(arr)
    count = [0] * (max_val + 1)

    # Count occurrences
    for num in arr:
        count[num] += 1

    # Build sorted array
    sorted_arr = []
    for i in range(len(count)):
        sorted_arr.extend([i]*count[i])
    return sorted_arr

arr = [4, 2, 2, 8, 3, 3, 1]
print("Original array:", arr)
sorted_arr = counting_sort(arr)
print("Sorted array:", sorted_arr)
