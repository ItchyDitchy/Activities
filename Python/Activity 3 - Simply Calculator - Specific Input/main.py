operation = input("What would you like to do? (input: {MULTIPLICATION, DIVISION,  ADDITION, SUBTRACTION})\n").upper()
while not operation == "MULTIPLICATION" or not operation == "DIVISION" or not operation == "ADDITION" or not operation == "SUBTRACTION" :
  operation = input("What would you like to do? (input: {MULTIPLICATION, DIVISION,  ADDITION, SUBTRACTION}); You had entered \"" + operation + "\" which is not a valid operation!\n").upper
number1 = input("What is your first number?\n")
while not number1.isnumeric() :
  number1 = input("What is your first number? You are being asked to give a number not \"" + number1 +"\"\n")
else :
  print("You have decided that " + number1 + " is your first number!")
number2 = input("What is your second number?\n")
while not number2.isnumeric() :
  number2 = input("What is your second number? You are being asked to give a number not \"" + number2 +"\"\n")
else :
  print("You have decided that " + number2 + " is your second number!")
print("We will now be doing " + operation + " with numbers " + number1 + " and " + number2 + "!")
if (operation == "ADDITION") :
  print("The result is " + str(int(number1) + int(number2)))
elif (operation == "SUBTRACTION") :
  print("The result is " + str(int(number1) - int(number2)))
elif (operation == "MULTIPLICATION") :
  print("The result is " + str(int(number1) * int(number2)))
elif (operation == "DIVISION") :
  print("The result is " + str(int(number1) / int(number2)))
