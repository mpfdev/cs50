try:
    changes = float(input("Change owed: "))
    coins = 0

    if changes >= 0.25:
        coins = int(changes / 0.25)
        changes = round(changes % 0.25, 2)

    if changes >= 0.10:
        coins += int(changes / 0.10)
        changes = round(changes % 0.10, 2)

    if changes >= 0.05:
        coins += int(changes / 0.05)
        changes = round(changes % 0.05, 2)

    if changes >= 0.01:
        coins += int(changes / 0.01)

    print(f"Coins: {coins}")
except:
    print("It's a invalid input!")

