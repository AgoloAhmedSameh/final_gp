while True:
    number = int(input("Enter a positive number: "))
    if number > 0:
        print(f"Thank you! You entered: {number}")
        break
    else:
        print("That is not a positive number. Try again.")
