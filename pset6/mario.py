from cs50 import get_int

while True:
    n = get_int("Height: ")
    
    if n >=1 and n <=8:
        break

for i in range(n):
    for j in range(n-1, i ,-1):
        print(" ", end="")
    for j in range(0,i+1,1):
        print("#", end = "")
     
    print("  " + "#"*(j+1))    #crazy cool line of code in PY that took a minute to discover to replace our 3rd for loop from c mario problem
        

   
