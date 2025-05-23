#include <iostream> 
using namespace std; 
class node 
{ 
bool n; 
node *next, *prev; 
public: 
node() 
{ 
prev = NULL; 
next = NULL; 
} 
node(bool b) 
{ 
n = b; 
prev = NULL; 
next = NULL; 
} 
friend class binary; 
}; 
class binary 
{ 
node *start, *end; 
void prep(bool);  // Add bit at the beginning 
public: 
binary() 
{ 
start = NULL; 
end = NULL; 
} 
void ones_comp(); 
void twos_comp(); 
void disp(); 
void DtoB(int); 
int BtoD(); 
binary operator+(binary); 
}; 
void binary::DtoB(int n) 
{ 
int rem; 
rem = n % 2; 
node* p; 
start = new node(rem); 
end = start; 
n = n / 2; 
while (n != 0) { 
rem = n % 2; 
n = n / 2; 
p = new node(rem); 
start->prev = p; 
p->next = start; 
start = p; 
} 
} 
int binary::BtoD() 
{ 
node *temp = end; 
int i = 0, p = 1, s = 0; 
while (temp != NULL) 
{ 
if (temp->n == 1) 
{ 
p = 1; 
for (int j = 1; j <= i; j++) 
p *= 2; 
s += p; 
} 
i += 1; 
temp = temp->prev; 
} 
return s; 
} 
void binary::disp() 
{ 
node* temp = start; 
while (temp != NULL) 
{ 
cout << temp->n; 
temp = temp->next; 
} 
} 
void binary::ones_comp() 
{ 
node* temp = start; 
while (temp != NULL) 
{ 
if (temp->n == 1) 
temp->n = 0; 
else 
temp->n = 1; 
temp = temp->next; 
} 
} 
void binary::twos_comp() 
{ 
node* temp = end; 
ones_comp(); 
int c = 1; 
while (temp != NULL)
{ 
if (temp->n == 1 && c == 1) 
{ 
temp->n = 0; 
c = 1; 
} 
else if (temp->n == 1 && c == 0) 
temp->n = 1; 
else if (temp->n == 0 && c == 1) 
{ 
temp->n = 1; 
c = 0; 
} 
else 
temp->n = 0; 
temp = temp->prev; 
} 
if (c == 1) 
prep(1); 
} 
void binary::prep(bool b) 
{  // Add bit at the beginning 
if (start == NULL) 
{ 
start = new node(b); 
end = start; 
} 
else 
{ 
node* p = new node(b); 
start->prev = p; 
p->next = start; 
start = p; 
} 
} 
binary binary::operator+(binary b) 
{ 
binary c; 
bool cry = 0;  // Carry 
node *temp1 = end, *temp2 = b.end; 
while (temp1 != NULL && temp2 != NULL) 
{ 
bool sum = temp1->n + temp2->n + cry;  // sum includes carry 
if (sum == 0) 
{ 
c.prep(0); 
cry = 0; 
} 
else if (sum == 1) 
{ 
c.prep(1); 
cry = 0; 
} 
else if (sum == 2) 
{ 
c.prep(0); 
cry = 1; 
} 
else if (sum == 3) 
{ 
c.prep(1); 
cry = 1; 
} 
temp1 = temp1->prev; 
temp2 = temp2->prev; 
} 
while (temp1 != NULL) 
{ 
bool sum = temp1->n + cry; 
if (sum == 0) 
{ 
c.prep(0); 
cry = 0; 
} 
else if (sum == 1) 
{ 
c.prep(1); 
cry = 0; 
}
else if (sum == 2) 
{ 
c.prep(0); 
cry = 1; 
} 
temp1 = temp1->prev; 
} 
while (temp2 != NULL) 
{ 
bool sum = temp2->n + cry; 
if (sum == 0) 
{ 
c.prep(0); 
cry = 0; 
} 
else if (sum == 1) 
{ 
c.prep(1); 
cry = 0; 
} 
else if (sum == 2) 
{ 
c.prep(0); 
cry = 1; 
} 
temp2 = temp2->prev; 
} 
if (cry == 1) 
{ 
c.prep(1); 
} 
return c; 
} 
int main() 
{ 
bool f = true; 
while (f) 
{ 
int ch; 
int n; 
binary b, d; 
cout << "\n\nEnter your choice : \n"; 
cout << "1)Generate binary from decimal\n2)1's complement\n3)2's complement\n4)Add 2 binary numbers\n5)Exit" << endl; 
cin >> ch; 
cout << endl; 
switch (ch) 
{ 
case 1: 
cout << "Enter the decimal number to generate binary: "; 
cin >> n; 
b.DtoB(n); 
cout << "The binary equivalent of no is: "; 
b.disp(); 
break; 
case 2: 
cout << "Enter the decimal number to generate binary and display 1's complement: "; 
cin >> n; 
b.DtoB(n); 
cout << "Equivalent binary is: "; 
b.disp(); 
b.ones_comp(); 
cout << "\nThe 1's complement of given binary number is: "; 
b.disp(); 
break; 
case 3: 
cout << "Enter the decimal number to generate binary and display 2's complement: "; 
cin >> n; 
b.DtoB(n); 
cout << "The binary equivalent is: "; 
b.disp(); 
b.twos_comp(); 
cout << "\nThe 2's complement of given binary number is: "; 
b.disp(); 
break; 
case 4: 
cout << "Enter first decimal number: "; 
cin >> n; 
b.DtoB(n); 
cout << "The binary equivalent is: "; 
b.disp(); 
cout << "\nEnter second decimal number: "; 
cin >> n; 
d.DtoB(n); 
cout << "The binary equivalent is: "; 
d.disp(); 
b = b + d; 
cout << "\nThe addi on of numbers is: "; 
b.disp(); 
cout << " (" << b.BtoD() << ")"; 
break; 
case 5: 
f = false; 
break; 
} 
} 
return 0; 
} 