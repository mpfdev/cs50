import sys

def print_blank(space):
    print(" " * space, end="")

def print_block(blocks):
    print("#" * blocks, end="")


while True:
    height = int(input("Height: "))

    if height >= 1 and height <= 8:
        for h in range(1,height+1):
            print_blank(height - h)
            print_block(h)
            print()
    else:
        print("Invalid height.")
        print("Choose height between 1 and 8.")
        sys.exit(1)

    sys.exit(0)


