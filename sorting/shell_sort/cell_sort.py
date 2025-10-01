def shell_sort(arr):
    n = len(arr)
    gap = n // 2  # Initial gap size
    
    # Keep reducing the gap
    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            # Shift elements that are greater than temp
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
        gap //= 2  # Reduce gap
    
    return arr

# Driver code
arr = [23, 12, 1, 8, 34, 54, 2, 3]
print("Original array:", arr)
print("Sorted array:", shell_sort(arr))
