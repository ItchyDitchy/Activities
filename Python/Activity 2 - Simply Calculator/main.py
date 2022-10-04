operation = input("What would you like to do? (input: {MULTIPLICATION, DIVISION, ADDITION, SUBTRACTION})\n")
number1 = input("What is your first number?\n")
number2 = input("What is your second number?\n")
if (operation == "ADDITION") :
  print("The result is " + str(int(number1) + int(number2)))
elif (operation == "SUBTRACTION") :
  print("The result is " + str(int(number1) - int(number2)))
elif (operation == "MULTIPLICATION") :
  print("The result is " + str(int(number1) * int(number2)))
elif (operation == "DIVISION") :
  print("The result is " + str(int(number1) / int(number2)))
