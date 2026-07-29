age=int(input("请输入您的年龄"));year=int(input("请输入工作时长"));level=int(input("请输入您的级别"))
if 18<=age<30:
    if year>2 or level>3:
        print("请前往领取您的礼物！")
    else:
        print("不是老资历啊！")
else:
    print("Sorry，年龄不在领取范围内")