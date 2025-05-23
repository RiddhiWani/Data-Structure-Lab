stud_list = [] 
N = int(input("Enter total number of students in the class: ")) 
stud = input("Enter names of students: ") 
stud_list = stud.split(' ') 
print("list of students who appeared for the exam: ", stud_list) 

dict = {} 
marks = [] 
for name in stud_list: 
    mark = int(input(f"\nEnter marks obtained by {name}: ")) 
    dict[name] = mark 
    marks.append(mark) 

def sum(lst): 
    val = 0 
    for i in lst: 
        val += i 
    return val 

def len(lst): 
    count = 0 
    for i in lst: 
        count += 1 
    return count 

def avg(lst): 
    average = sum(lst) / len(lst) 
    return average 

def highest_score(lst): 
    current_max = lst[0] 
    for i in lst: 
        if i > current_max: 
            current_max = i 
    return current_max 

def lowest_score(lst): 
    current_min = lst[0] 
    for i in lst: 
        if i < current_min: 
            current_min = i 
    return current_min 

def absent(): 
    abs = N - int(len(stud_list)) 
    return abs 

def highest_freq(lst): 
    max = 0 
    highest_freq = lst[0] 
    for i in lst: 
        freq = lst.count(i) 
        if freq > max: 
            max = freq 
            highest_freq = i 
    return highest_freq 

flag = 1  
while flag != 0: 
    print("\n-----operations-----") 
    user_input = int(input(""" 
1 the average score of class 
2 highest score of class 
3 count of students who were absent for the test 
4 display mark with highest frequency 
5 exit 
>> """)) 
    if user_input == 1: 
        print("avg of the class", avg(marks)) 
    elif user_input == 2: 
        print("highest score", highest_score(marks)) 
        print("Lowest score", lowest_score(marks)) 
    elif user_input == 3: 
        print(f"{absent()} students were absent") 
    elif user_input == 4: 
        print(f"Highest frequency of score is: {highest_freq(marks)}")
        print(f"{highest_freq(marks)} were obtained by {marks.count(highest_freq(marks))} students") 
    elif user_input == 5: 
        flag = 0 
    else:
        print("Enter valid input")
