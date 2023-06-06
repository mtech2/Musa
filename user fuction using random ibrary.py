import random as rm
print("What You Want")
num=input()
number= rm.randint(1,100)
color=["red","bule","green","yellow","purple"]
val=rm.choice(color)
if num == "color" :
    print(val)
elif num == "number" :
    print(number)