def capital_indexes(string):
    indexes = list()
    if not type(string) == str:
        return indexes
    i = 0
    while i < (len(string)):
        if string[i].isupper():
            indexes.append(i)
        i += 1
    return indexes
