a = 5
b = 10
c = 15

# First level of branching
if a < b:
    print("Level 1: a is less than b")

    # Second level of branching (nested)
    if b < c:
        print("Level 2: b is less than c")

        # Third level of branching (nested further)
        if a + b == c:
            print("Level 3: a + b equals c")
        else:
            print("Level 3: a + b does not equal c")
    else:
        print("Level 2: b is not less than c")

        # Additional nested condition
        if c - b > a:
            print("Level 3: c - b is greater than a")

    # Test full branch
    test_full_branch = True

    if test_full_branch:
        print("branch 1")
    elif test_full_branch < 3:
        print("branch 2")
    else:
        print("branch 3")

    print("done testing full branch!")

    if 3 > 1:
        print("always true!")

    for i in range(3):
        print("simple loop!")

else:
    print("Now the mid-level do-while loop!")

    cnt = 3
    while True:
        if True:
            print("testing a condition inside a loop!")
        break

    print("Level 1: a is not less than b")

    # Another branch outside the nested block
    if a * 2 == b:
        print("Level 2: a * 2 equals b")

        # Instruction at a deeper level
        if b * 2 == c:
            print("Level 3: b * 2 equals c")
        else:
            print("Level 3: b * 2 does not equal c")
    else:
        print("Level 2: a * 2 does not equal b")

# Branch that skips a level of nesting
if c > 10:
    print("c is greater than 10")

    if c % 2 == 0:
        print("c is even")
    else:
        print("c is odd")
