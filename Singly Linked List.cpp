#include<iostream> 
#include<string> 
#include<cstdlib> 
using namespace std; 
class node 
{ 
public: 
int prn; 
string name; 
node* link; 
node() : prn(0), link(nullptr) {} 
}; 
class linkedlist 
{ 
node *start; 
public: 
linkedlist() : start(nullptr) {} 
void insert_President() 
{ 
node *tmp = new node(); 
int pr; 
string nm; 
cout << "Enter PRN and Name:\n"; 
cin >> pr >> nm; 
tmp->prn = pr; 
tmp->name = nm; 
tmp->link = nullptr; 
if (start == nullptr) 
start = tmp; 
else 
{ 
tmp->link = start; 
start = tmp;  
} 
display(); 
} 
void insert_Secretary() 
{ 
node *tmp = new node(); 
int pr; 
string nm; 
cout << "Enter PRN and Name:\n"; 
cin >> pr >> nm; 
tmp->prn = pr; 
tmp->name = nm; 
tmp->link = nullptr; if (start == nullptr) 
start = tmp; 
else 
{ 
node *q = start; 
while (q->link != nullptr) 
q = q->link; 
q->link = tmp; 
} 
display(); 
} 
void insert_Member() 
{ 
int pr, index; 
string nm; 
cout << "Enter PRN and Name:\n"; 
cin >> pr >> nm; 
node *tmp = new node(); 
tmp->prn = pr; 
tmp->name = nm; 
tmp->link = nullptr; 
if (start == nullptr) 
{ 
start = tmp; 
} 
else 
{ 
cout << "Enter index a er which element to be inserted:\n"; 
cin >> index; 
node *q = start; 
for (int i = 0; i < index; ++i) 
{ 
if (q == nullptr) 
{ 
cout << "There are less elements\n"; 
delete tmp; 
return; 
} 
q = q->link; 
} 
tmp->link = q->link; 
q->link = tmp; 
} 
display(); 
} 
void del_President() 
{ 
if (start == nullptr) 
{ 
cout << "No members to delete.\n"; 
return; 
} 
node *tmp = start; 
start = start->link; 
delete tmp; 
display(); 
} 
void del_Secretary() 
{ 
if (start == nullptr) 
{ 
cout << "No members to delete.\n"; 
return; 
} 
node *tmp = start; 
node *q = nullptr; 
while (tmp->link != nullptr) 
{ 
q = tmp; 
tmp = tmp->link; 
} 
if (q != nullptr) q->link = nullptr; 
delete tmp; 
display(); 
} 
void del_Member()
{ 
int pr; 
cout << "Enter PRN to be deleted: "; 
cin >> pr; 
node *tmp = start; 
node *q = nullptr; 
while (tmp != nullptr) 
{ 
if (tmp->prn == pr)
{ 
if (q != nullptr) 
q->link = tmp->link; 
else 
start = tmp->link; 
delete tmp; 
display(); 
return; 
} 
q = tmp; 
tmp = tmp->link; 
} 
cout << "Member not found.\n"; 
} 
void display() 
{ 
if (start == nullptr) 
{ 
cout << "Club is empty!!\n"; 
} 
else 
{ 
cout << "**** Members in Club ****\n"; 
node *q = start; 
while (q != nullptr) 
{ 
cout << q->prn << " " << q->name << endl; 
q = q->link; 
} 
} 
} 
void count() 
{ 
int i = 0; 
node *q = start; 
while (q != nullptr) 
{ 
i++; 
q = q->link; 
} 
cout << "Total number of members in club: " << i << endl; 
} 
void reverse() 
{ 
node *prev = nullptr, *current = start, *next = nullptr; 
while (current != nullptr) 
{ 
next = current->link; 
current->link = prev; 
prev = current; 
current = next; 
} 
start = prev; 
display(); 
} 
void concat(linkedlist &l1, linkedlist &l2) 
{ 
if (l1.start == nullptr) 
{ 
l1.start = l2.start; 
} 
else 
{ 
node *ptr = l1.start; 
while (ptr->link != nullptr) 
ptr = ptr->link; 
ptr->link = l2.start; 
} 
l1.display(); 
} 
}; 
int main()
{ 
linkedlist l1, l2; 
int ch; 
while (true) 
{ 
cout << "\nLinked List Menu \n"; 
cout << "1. Insert President\n"; 
cout << "2. Insert Secretary\n"; 
cout << "3. Insert Member\n"; 
cout << "4. Delete President\n"; 
cout << "5. Delete Secretary\n"; 
cout << "6. Delete Member\n"; 
cout << "7. Display\n"; 
cout << "8. Count\n"; 
cout << "9. Concat\n"; 
cout << "10. Exit\n"; 
cout << "Enter your choice: "; 
cin >> ch; 
cin.ignore();  // Clear the input buffer 
switch (ch) 
{ 
case 1: 
l1.insert_President(); 
break; 
case 2: 
l1.insert_Secretary(); 
break; 
case 3: 
l1.insert_Member(); 
break; 
case 4: 
l1.del_President(); 
break; 
case 5: 
l1.del_Secretary(); 
break; 
case 6: 
l1.del_Member(); 
break; 
case 7: 
l1.display(); 
break; 
case 8: 
l1.count(); 
break; 
case 9: 
l1.concat(l1, l2); 
break; 
case 10: 
cout << "Exiting the program.\n"; 
return 0;  // Exit the program 
default: 
cout << "Invalid choice.\n"; 
break; 
} 
} 
return 0; 
} 
 