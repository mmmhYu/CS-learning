sum_account= 10000
salary = 1000
i = 1
import random
for i in range(1,21):
    num = random.randint(1,10)
    if num < 5:
        print(f"员工{i}绩效分{num}，低于5，不发工资 下一位。")
        continue
    else:
        if sum_account >= salary:
            sum_account -= salary
            print(f"向员工{i}发放工资{salary}元，账户余额还剩{sum_account}元")
        else:
            print('工资发完了～')
            break
print(f"发放至第{i}位员工，账户剩余{sum_account}元")


