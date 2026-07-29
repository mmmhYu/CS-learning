import random
i=1
num = random.randint(1,100)
guess = int(input("请输入你猜测的数字："))
while guess != num:
    if guess > num:
        print("大了")
    else:
        print("小了")
    i += 1
    guess = int(input("请输入你猜测的数字：")）
print(f"猜中了！总共花了{i}次。")
