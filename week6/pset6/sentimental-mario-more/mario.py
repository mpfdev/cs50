
def print_spaces(space):
    print(" " * space, end="")

def print_blocks(block):
    print("#" * block, end="")

def print_gap():
    print(" " * 2, end="")

height = int(input("Height: "))

if height >= 1 and height <= 8:
    for h in range(1, height+1):
        print_spaces(height - h)
        print_blocks(h)
        print_gap()
        print_blocks(h)
        print()

