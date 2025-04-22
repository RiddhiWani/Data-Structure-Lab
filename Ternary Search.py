names = [] 
n = int(input("Enter total number of students in club: ")) 
for l in range(0, n): 
    ele = input("Name of student: ") 
    names.append(ele) 
print(names) 
 
roll_Number = [] 
for i in names: 
    print("Enter roll no. of ", i) 
    m = int(input()) 
    roll_Number.append(m) 
print(roll_Number) 
 
def Sorting(array):  # Corrected the function name
    for i in range(len(array)): 
        for j in range(len(array)): 
            if array[i] < array[j]: 
                array[j], array[i] = array[i], array[j] 
    return array 
 
def ternary(a, x): 
    start = 0 
    end = len(a) - 1 
    while start <= end: 
        mid1 = (end - start) // 3 + start 
        mid2 = 2 * (end - start) // 3 + start 
        if x == a[mid1]: 
            return mid1 
        elif x == a[mid2]: 
            return mid2 
        elif x < a[mid1]: 
            end = mid1 - 1 
        elif x > a[mid2]: 
            start = mid2 + 1 
        else: 
            start = mid1 + 1 
            end = mid2 - 1 
    return -1 
count = 1 
X = Sorting(roll_Number)  # Calling the corrected function name
print("The sorted list of roll numbers is:", X) 
 
while count == 1: 
    Y = int(input("Enter the roll number you want to find: ")) 
    Z = ternary(X, Y) 
    if Z == -1: 
        print("Element not found") 
    else: 
        print(f"Roll no. {Y} is found at {Z}th index") 
 
    key = input("Continue? (y/n): ")  
    if key == 'n': 
        count = 0 
