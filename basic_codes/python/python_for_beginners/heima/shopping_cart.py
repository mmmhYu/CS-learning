print("""
请输入你要进行的操作:
1.
2.
3.
4.
5.
""")

cart = dict()

while 1 :
    i = int(input())

    match i :
        case 1:
            print("请输入要添加的商品名称，价格以及件数")
            str = input()
            good,price,num = str.split()
            cart[good] = {"price":int(price),"num":int(num)}
            print(cart)
            pass

        case 2:
            print("请输入要修改的商品名称，价格以及件数")
            str = input()
            good,price,num = str.split()
            cart[good] = {"price":price,"num":num}
            pass

        case 3:
            print("请输入要删除的商品名称")
            good = input()
            del cart[good]
            pass

        case 4:
            print("请输入要查询的商品名称")
            good = input()
            x,y = cart[good].values()
            print(f"价格为{x},件数为{y}")
            pass

        case _:
            pass
        
