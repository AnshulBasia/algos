
numbers = map(int, raw_input().split())
a=numbers[0]
b=numbers[1]
n=numbers[2]

l=[]
l.append(a)
l.append(b)
def mod_fib(n):
    if len(l)>=n:
        return l[n-1]
    else:
        l.append(mod_fib(n-2)+(mod_fib(n-1)*mod_fib(n-1)))
        return l[n-1]
a=mod_fib(n)
print (a)