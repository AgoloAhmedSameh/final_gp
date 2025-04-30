# Classify numbers from 1 to 10 as even, odd, or divisible by 3
for num in range(1, 11):
    if num % 2 == 0:
        print(f"{num} is even.")
    elif num % 3 == 0:
        print(f"{num} is divisible by 3.")
    else:
        print(f"{num} is odd.")
print("done!")