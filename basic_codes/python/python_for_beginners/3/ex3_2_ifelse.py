height=int(input("请输入您的身高(cm)"))
if height>120:
    print(f"您的身高超出120cm，游玩需要购票{(height-120)}元。")
else:
    print(f"您的身高未超出120cm，可以免费游玩。")
print("祝您游玩愉快！")