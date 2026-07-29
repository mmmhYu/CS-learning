import random
num=random.randint(1,10)
gn=int(input("第一次猜测："))
if gn==num:
    print("恭喜你！第一次就猜对了！")
else:
    if gn>num:
        print("大了！")
    else:
        print("小了！")
    gn=int(input("第二次猜测："))
    if gn == num:
        print("恭喜你！第二次就猜对了！")
    else:
        if gn > num:
            print("大了！")
        else:
            print("小了！")
        gn = int(input("第三次猜测："))
        if gn == num:
            print("恭喜你！第三次就猜对了！")
        else:
            print("啊哦，机会用完了。")