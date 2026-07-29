i = 1
j = 1
temp = 1
a = 0
while i <= 10:
    while j<=i:
        temp *= j
        j += 1
    a += temp
    i += 1
print(a)