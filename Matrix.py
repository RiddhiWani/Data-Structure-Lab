m1=[[2,3],[4,5]]
m2=[[3,5],[2,8]]
ans1=[[0,0] for i in range(2)]
ans2=[[0,0] for i in range(2)]
ans3=[[0,0] for i in range(2)]
ans4=[[0,0] for i in range(2)]
#ADDITION
for i in range (2):
     for j in range (2):
             ans1[i][j]=m1[i][j]+m2[i][j]

#SUBTRACTION
for i in range (2):
      for j in range (2):
              ans2[i][j]=m1[i][j]-m2[i][j]

#MULTIPLICATION
for i in range (2):
      for j in range (2):
        ans3[i][j]=sum(m1[i][k]*m2[j][k] for k in range (2))

#TRANSPOSE
for i in range (2):
      for j in range (2):
              ans4[i][j]=m1[j][i]
              ans4[i][j]=m2[j][i]
print("Addition is : ",ans1)
print("Subtraction is : ",ans2)
print("Multiplication is : ",ans3)
print("Transpose of m1 is : ",ans4)
print("Transpose of m2 is : ",ans4)











import numpy
x = numpy.array([[1,2], [4,5]])
y = numpy.array([[7,8], [9,10]])
print("The addition of matrix is : ")
print(numpy.add(x,y))
print("The subtraction of matrix is : ")
print(numpy.subtract(x,y))
print("The multiplication of matrix is : ")
print(numpy.multiply(x,y))
print("The transpose of matrix x is : ")
print(x.T)
print("The transpose of matrix y is : ")
print(y.T)


