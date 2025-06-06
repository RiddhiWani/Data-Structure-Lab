marks = [] 
n = int(input("Enter number of students whose marks are to be displayed: ")) 
print(f"Enter marks for {n} students: ") 

for i in range(0, n): 
    ele = int(input()) 
    marks.append(ele) 
def Bubble_Sort(array): 
    for i in range(len(array)): 
        for j in range(len(array) - 1 - i):  # Corrected range for Bubble Sort 
            if array[j] > array[j + 1]:  # Corrected the condition for sorting 
                array[j], array[j + 1] = array[j + 1], array[j] 
    return array 

# Menu-driven program 
flag = 1 
while flag == 1: 
    print("Menu") 
    print('''1) Bubble Sort 
2) Top 5 Marks''') 

    no = int(input("Choose option number: ")) 

    if no == 1: 
        mark = Bubble_Sort(marks) 
        print("Sorted marks using bubble sort are:", mark) 
        w = input("Continue? (y/n): ") 
        if w == 'y': 
            flag = 1 
        elif w == 'n': 
            flag = 0 
            break 
        else: 
            print("INVALID OPTION") 

    elif no == 2: 
        print("Top 5 marks are:") 
        mark = Selection_Sort(marks) 
        for i in range(n - 1, n - 6, -1): 
            print(mark[i]) 
        v = input("Continue? (y/n): ") 
        if v == 'y': 
            flag = 1 
        elif v == 'n': 
            flag = 0 
            break 
        else: 
            print("INVALID OPTION") 

    else: 
        print("Option not available")
