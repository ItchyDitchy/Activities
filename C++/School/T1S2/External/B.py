fellowship = ["gandalf","aragorn","boromir","legolas","gimli","frodo","sam","merry","pippin"]
choice = input("Guess who's in the list that has been provided to us\n> ")
choice = choice.lower()
if choice in fellowship:
    print("TRUE")
else:
    print("FALSE")