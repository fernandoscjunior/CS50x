while (True):
    try:
        height = int(input("Height: "))
        if (height > 0 and height < 9):
            break
    except:
        print("Invalid input")

for rows in range(height):

    for left_columns in range(height):
        if left_columns < height - rows - 1:
            print(" ", end="")
        else:
            print("#", end="")

    print("  ", end="")

    for right_columns in range(height):
        if right_columns > rows:
            print("", end="")
        else:
            print("#", end="")

    print("")
