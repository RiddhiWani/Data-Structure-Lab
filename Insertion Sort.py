def accept_mark():
    mark = []
    no_of_students = int(input("Enter the number of students  : "))
    for i in range(no_of_students):
        mark.append(int(input("Enter mark of Student {0} : ".format(i+1))))
    return mark
def print_marks(mark):
    for i in range(len(mark)):
        print(mark[i],sep = "\n")
def insertion_sort(mark):
    for i in range(1,len(mark)):
        key = mark[i]
        j = i-1;
        while j >= 0 and key < mark[j]:
            mark[j+1] = mark[j]
            j -= 1
            mark[j+1] = key
    return mark

# Main
unsort_marks = []
sort_marks = []
flag = 1

while flag == 1:
        print("\nMENU")
        print("1. Accept Number of Students")
        print("2. Display the marks of Student")
        print("3. Sort marks from the list")
        print("4. Exit\n")

        ch = int(input("Enter your choice (from 1 to 4) : "))

        if ch == 1:
             unsort_marks = accept_mark()

        elif ch == 2:
            print_marks(unsort_marks)

        elif ch == 3:
            print("Elements after performing Insertion Sort : \n")
            sort_marks = insertion_sort(unsort_marks)
            print_marks(sort_marks)

       

        elif ch == 4:
            print("Thanks for using this program!!")
            flag=0

        else:
            print("Wrong choice!!")
            flag = 0