def bucket_sort(arr):
    n = len(arr)
    buckets = [[] for _ in range(n)]

    # Put array elements into buckets
    for num in arr:
        index = int(n * num)
        buckets[index].append(num)

    # Sort individual buckets
    for bucket in buckets:
        bucket.sort()

    # Concatenate buckets
    sorted_arr = []
    for bucket in buckets:
        sorted_arr.extend(bucket)
    return sorted_arr

arr = [0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51]
print("Original array:", arr)
sorted_arr = bucket_sort(arr)
print("Sorted array:", sorted_arr)
