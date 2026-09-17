print("提取所有偶数并作平方，存到一个新的数组里面")

num_list = [19,23,54,64,87,20,109,232,123,43,26,55,72]
sqr_list = []

for i in num_list :
    if not i % 2 :
        sqr_list.append(i*i)

print(num_list)
print(sqr_list)