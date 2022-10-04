def mid(string):
    if not type(string) == str:
        return ""
    if len(string)%2 == 0:
        return ""
    return string[len(string)//2]
