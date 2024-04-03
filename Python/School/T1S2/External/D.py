def get_race(fellow):
    if fellow == 'Gandalf':
        print("wizard")
    elif fellow == 'Aragorn' or fellow == 'Boromir':
        print("man")
    elif fellow == 'Legolas':
        print("elf")
    else:
        print("hobbit")

get_race('Gandalf')
get_race('Boromir')
get_race('Frodo')
get_race('Legolas')