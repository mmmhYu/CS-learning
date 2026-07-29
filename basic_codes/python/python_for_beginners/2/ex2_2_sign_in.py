from traceback import print_tb

user_name=input("请输入用户名:");user_type=input("请输入用户类型:");user_deposit=int(input("请输入余额:"))
#原始输出
print("您好："+user_name+"，您是尊贵的："+user_type+"，账户余额为："+str(user_deposit)+"，欢迎您的光临")
#格式化输出
print("您好：%s，您是尊贵的：%s，账户余额为：%d，欢迎您的光临"%(user_name,user_type,user_deposit))
#f""输出
print(f"您好：{user_name}，您是尊贵的：{user_type}，账户余额为：{user_deposit}，欢迎您的光临")