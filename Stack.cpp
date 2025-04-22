#include <iostream> 
using namespace std; 
 class stack 
{ 
char s[25]; 
int top; 
public: 
    void push(char val); 
    char pop(); 
    bool isempty(); 
    bool isfull(); 
    void display(); 
    stack() { top = -1; } 
}; 
bool stack::isempty() 
{ 
return top == -1; // Stack is empty if top == -1 
} 
 void stack::push(char val) 
{ 
if (top < 24) // Check if the stack is full 
{ 
top++; 
s[top] = val; 
} 
else 
{ 
cout << "\nStack is full"; 
} 
} 
char stack::pop() 
{ 
char val; 
if (!isempty()) 
{ 
val = s[top]; 
top--; 
return val; 
} 
else 
{ 
cout << "\nStack is empty"; 
return '*'; // Return '*' to indicate an error 
} 
} 
class paranthesis 
{ 
char expn[25]; 
stack obj; 
public: 
    void read(); 
    void checkexpn(); 
}; 
void paranthesis::read() 
{ 
cout << "\nEnter the expression: "; 
cin >> expn; 
cout << "\nEntered expression is: " << expn; 
} 
void paranthesis::checkexpn() 
{ 
int i, flag; 
char ch; 
flag = 0; 
for (i = 0; expn[i] != '\0'; i++) 
{ 
if (expn[i] == '{' || expn[i] == '[' || expn[i] == '(') 
{ 
obj.push(expn[i]); 
} 
if (expn[i] == '}' || expn[i] == ']' || expn[i] == ')') 
{ 
if (!obj.isempty()) 
{ 
ch = obj.pop(); 
if (expn[i] == '}' && ch != '{') 
{ 
flag = 1; 
break; 
} 
if (expn[i] == ']' && ch != '[') 
{ 
flag = 1; 
break; 
} 
if (expn[i] == ')' && ch != '(') 
{ 
flag = 1; 
break; 
} 
} 
else 
{ 
flag = 1; // Unmatched closing bracket 
break; 
} 
} 
} 
if (flag == 0 && obj.isempty()) 
cout << "\nExpression is well parenthesized"; 
else 
cout << "\nExpression is not well parenthesized"; 
} 
 int main() 
{ 
paranthesis obj1; 
obj1.read(); 
obj1.checkexpn(); 
return 0; 
} 