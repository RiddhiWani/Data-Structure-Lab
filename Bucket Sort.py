def bucket_sort(Percentage):
    largest = max(Percentage)
    length = len(Percentage)
    size = largest / length

    # Create buckets
    buckets = [[] for _ in range(length)]

    # Distribute the elements into buckets
    for i in range(length):
        j = int(Percentage[i] / size)
        if j != length:
            buckets[j].append(Percentage[i])
        else:
            buckets[length - 1].append(Percentage[i])

    # Sort each bucket using insertion sort
    for i in range(length):
        insertion_sort(buckets[i])

    # Concatenate the sorted buckets into result
    result = []
    for i in range(length):
        result = result + buckets[i]

    return result


def insertion_sort(Percentage):
    for i in range(1, len(Percentage)):
        temp = Percentage[i]
        j = i - 1
        while j >= 0 and temp < Percentage[j]:
            Percentage[j + 1] = Percentage[j]
            j = j - 1
        Percentage[j + 1] = temp


# Main block to input student percentages and use sorting
def main():
    Percentage = []
    number = int(input("Enter the Total Number of Students:\n"))
    
    # Input percentages
    for i in range(number):
        value = float(input("Enter the Percentage:\n"))
        Percentage.append(value)
    
    # Sorting percentages using bucket sort
    sorted_percentages = bucket_sort(Percentage)
    
    # Display sorted percentages
    print("Sorted Percentages:", sorted_percentages)

    # Display top 5 scores
    print("The Top five scores are:", sorted_percentages[-5:])
    minimum = len(sorted_percentages) - 6
    maximum = len(sorted_percentages) - 1
    index = 1
    for i in range(maximum, minimum, -1):
        if i >= 0:
            print(f"{index} Top Scorer: {sorted_percentages[i]}\n")
            index += 1

# Run the main block
if __name__ == "__main__":
    main()
