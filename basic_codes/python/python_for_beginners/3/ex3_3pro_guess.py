a=5;i=0
x=int(input(f"请输入第{i}次猜测的数字（1-10）："))
while x!=5 and i<3:
    if x>5:
        print("大了！");i+=1;x=int(input(f"请输入第{i}次猜测的数字（1-10）："))
    else:
        print("小了！");i+=1;x=int(input(f"请输入第{i}次猜测的数字（1-10）："))
if x==a:
    print("恭喜你！我想的数字就是%d"%x)
else:
    print("可惜啦！我想的其实是%d"%a)

