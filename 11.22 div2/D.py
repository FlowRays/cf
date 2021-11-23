a = 2
b = 100
q = {a,b}

s = set()

def f(a,b):
    global q
    q.add(abs(a-b))
    if (abs(a-b),b) not in s:
        s.add((abs(a-b),b))
        f(abs(a-b),b)
    if (abs(a-b),a) not in s:
        s.add((abs(a-b),a))
        f(a,abs(a-b))

s.add((a,b))
f(a,b)

t = sorted(list(q))

print(t)