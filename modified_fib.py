""" t_(i+2) = t_i + (t_(i+1))^2 """  

import sys

fibmem = []

def fib(n):
    fibmem.append(fibmem[n-2] + (fibmem[n-1] ** 2))
    return      
   
def begin_fib(f,s,n):
    fibmem.append(0)
    fibmem.append(f)
    fibmem.append(s)
    for i in range(3,n): 
        fib(i)
    return 

data = sys.stdin.readlines()
s = data[0].split(" ")
begin_fib(int(s[0]), int(s[1]), int(s[2])+1)

print(fibmem[int(s[2])])