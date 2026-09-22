class student:
    def __init__(self,name,Chinese,Maths,English):
        self.name = name
        self.Chinese = Chinese
        self.Maths = Maths
        self.English = English

    def __str__(self):
        return f"name:{self.name}|Chinese:{self.Chinese}|Maths:{self.Maths}|English:{self.English}"

    def update_score(self,C = None,M = None,E = None):
        if C is not None:
            self.Chinese = C
        if M is not None:
            self.Maths = M
        if E is not None:
            self.English = E

class EduManagement:
    def __init__(self):
        self.stuList = []

    def addStu(self):
        name = input("请输入学生姓名：")

        for s in self.stuList:
            if s.name == name:
                print("学生已存在！")
                return

        Chinese,Maths,English = map(int,input("请输入三门成绩：").split())

        if 0 <= Chinese <= 100 and 0 <= Maths <= 100 and 0 <= English <= 100:
            self.stuList.append(student(name,Chinese,Maths,English))
        else:
            print("成绩不合法！")
            return

    def updateStu(self):
        name = input("请输入学生姓名：")

        for stu in self.stuList:
            if stu.name == name:
                break
        else:
            print("该学生不存在！")
            return

        update_dict = {"Chinese":None,"Maths":None,"English":None}

        while (sub := input("请输入要修改的科目(输入0以退出)")) != '0':
            match sub:
                case "Chinese":
                    score = int(input("请输入修改后的成绩"))
                    if 0 <= score <= 100:
                        update_dict["Chinese"] = score
                    else:
                        print("不合法的成绩！")
                        return
                case "Maths":
                    score = int(input("请输入修改后的成绩"))
                    if 0 <= score <= 100:
                        update_dict["Maths"] = score
                    else:
                        print("不合法的成绩！")
                        return
                case "English":
                    score = int(input("请输入修改后的成绩"))
                    if 0 <= score <= 100:
                        update_dict["English"] = score
                    else:
                        print("不合法的成绩！")
                        return
                case _:
                    break

        #可以增加成绩合法判定
        stu.update_score(update_dict["Chinese"],update_dict["Maths"],update_dict["English"])
        