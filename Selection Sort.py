marks = [] 
n = int(input("Enter number of students whose marks are to be displayed: ")) 
print(f"Enter marks for {n} students: ") 

for i in range(0, n): 
    ele = int(input()) 
    marks.append(ele) 

# Function for Selection Sort 
def Selection_Sort(marks): 
    for i in range(len(marks)): 
        min_idx = i 
        for j in range(i + 1, len(marks)): 
            if marks[min_idx] > marks[j]: 
                min_idx = j 
        marks[i], marks[min_idx] = marks[min_idx], marks[i] 
    return marks 



# Menu-driven program 
flag = 1 
while flag == 1: 
    print("Menu") 
    print('''1) Selection Sort 
2) Top 5 Marks''') 

    no = int(input("Choose option number: ")) 

    if no == 1: 
        mark = Selection_Sort(marks) 
        print("Sorted array using selection sort is:", mark) 
        v = input("Continue? (y/n): ") 
        if v == 'y': 
            flag = 1 
        elif v == 'n': 
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
