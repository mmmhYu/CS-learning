invitation = ['Jobs','Michael','Kun']
message = 'Please arrive at Hotel Herman at 14:00 on Feb 29th!'
print(f"{invitation[2]} is on duty at that time.")
invitation[2] = "Jay"
print(f"{invitation[2]} will take his place.")

print("I found a bigger table! More could be seated!")
invitation.insert(0,"David")
invitation.insert(3,"JJ")
invitation.append("192")
popped_1 = invitation.pop()
print(f"Sorry {popped_1}, you're popped!")
del invitation[3]
i=0
while i<4:
    print(f"{invitation[i]}:{message}")
    i+=1
