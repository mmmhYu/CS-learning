print("请输入十个数字，空格隔开")

arr_sum = 0
arr = []

for i in range(10) :
    tmp = int(input())
    arr.append(tmp)
    arr_sum += tmp

avg = arr_sum / 10
arr.sort()

print(f"最小值为:{arr[0]};最大值为:{arr[-1]};平均值为:{avg}");
