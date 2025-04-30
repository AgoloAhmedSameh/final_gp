# X = 3; Y = 4
# print(X); print(Y); Z = X + Y
# print(Z)

# print(X + Z);
# for i in range(3, 4):
#     print(i)

# if (X + Z > 3):
#     for i in range(5):
#         for j in range(10):
#             print(i)
#             if(i == 3):
#                 print("3 is found")
#                 break
#             elif i == 2:
#                 print("2 is found")
#                 yield 3
#             else:
#                 return 4
#             print("Before inner loop")
#         print("After inner loop")
#     print("After outer loop")
        
#     if Z < Z:
#         print(X)
#         print(Z)


# func(1,2,3)
# assert(x > 3)

# Ask the user for a number and classify it
while True:
    number = int(input("Enter a number: "))
    if number > 0:
        print(f"{number} is positive.")
        if number % 2 == 0:
            print("It is also even.")
        else:
            print("It is also odd.")
        break
    elif number < 0:
        print(f"{number} is negative. Try again.")
    else:
        print("You entered zero. Try again.")
# print('done')