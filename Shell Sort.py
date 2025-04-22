def shell_sort(a):
    # Start with a big gap, then reduce the gap
    n = len(a)
    gap = n // 2

    # Do a gapped insertion sort for this gap size.
    while gap > 0:
        # Perform insertion sort with the current gap
        for i in range(gap, n):
            # Store the current element in temp
            temp = a[i]

            # Shift elements that are greater than temp to the right
            j = i
            while j >= gap and a[j - gap] > temp:
                a[j] = a[j - gap]
                j -= gap

            # Place temp in the correct location
            a[j] = temp

        # Reduce the gap for the next pass
        gap //= 2

    return a

# Example usage:
arr = [5, 2, 9, 1, 5, 6]
sorted_arr = shell_sort(arr)
print(sorted_arr)
