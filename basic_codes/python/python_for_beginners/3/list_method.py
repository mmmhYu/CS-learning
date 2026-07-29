classmate=["192","Andy","Lee"]
classmate.append("Shanyu")
lattest = classmate.pop()
print(classmate)
print(f"最近认识的是{lattest.upper()}")
oldest = classmate.pop(1)
print(classmate)
print(f"最早认识的是{oldest.upper()}")
classmate[1]="seok"
print(classmate)