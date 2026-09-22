x = 10

def func():
    global x 
    x = 20
    print(x)
    x = 1
    print(x)

func()
print(x)