# A few dependencies
import math

# Operation Handler
def handleOperation(operation, numberToTouch):
  operation = operation.lower()
  numberToTouch = float(numberToTouch)
  if (operation == "sin"):
    return math.sin(numberToTouch)
  elif (operation == "cos"):
    return math.cos(numberToTouch)
  elif (operation == "tan"):
    return math.tan(numberToTouch)
  elif (operation == "cot"):
    return 1.0/math.tan(numberToTouch)
  elif (operation == "sec"):
    return 1.0/math.cos(numberToTouch)
  elif (operation == "csc"):
    return 1.0/math.sin(numberToTouch)
  elif (operation == "exponent"):
    power = input("\nWhat would you like its exponent to be?\n")
    while (not power.isdigit()):
      power = input("That is not a number!\nWhat would you like its exponent to be?\n")
    return math.pow(numberToTouch, float(power))
  elif (operation == "root"):
    toUse = input("\nWhich root would you like to use for this operation?\n")
    while (not toUse.isdigit()):
      toUse = input("\nThat is not a number!\nWhich root would you like to use for this operation?")
    return math.pow(numberToTouch, 1.0/float(toUse))
  elif (operation == "addition" or operation == "add" or operation == "+"):
    toUse = input("\nWhat would you like the number to be used on this operation?\n")
    while (not toUse.isdigit()):
      toUse = input("\nThat is not a number!\nWhat would you like the number to be used on this operation?\n")
    return numberToTouch + float(toUse)
  elif (operation == "subtraction" or operation == "subtract" or operation == "-"):
    toUse = input("\nWhat would you like the number to be used on this operation?\n")
    while (not toUse.isdigit()):
      toUse = input("\nThat is not a number!\nWhat would you like the number to be used on this operation?\n")
    return numberToTouch - float(toUse)
  elif (operation == "multiplication" or operation == "multiply" or operation == "*"):
    toUse = input("\nWhat would you like the number to be used on this operation?\n")
    while (not toUse.isdigit()):
      toUse = input("\nThat is not a number!\nWhat would you like the number to be used on this operation?\n")
    return numberToTouch * float(toUse)
  elif (operation == "division" or operation == "divide" or operation == "/"):
    toUse = input("\nWhat would you like the number to be used on this operation?\n")
    while (not toUse.isdigit()):
      toUse = input("\nThat is not a number!\nWhat would you like the number to be used on this operation?\n")
    return numberToTouch / float(toUse)
  else:
    userInput = input("\nThat is not an operation!\nWhat would you like to do?.\nThe available operations are sin, cos, tan, cot, sec, csc, exponent, root, addition, subtraction, multiplication, and division.\n")
    handleOperation(userInput, numberToTouch)

def start():
  # Asks the user for a number.
  userInput = input("\nType your first number.\n")
  while(not userInput.isdigit()):
    userInput = input("\nThat is not a number! \nType your first number.\n")
  num = float(userInput)
  userInput = input("\nWhat would you like to do?.\nThe available operations are sin, cos, tan, cot, sec, csc, exponent, root, addition, subtraction, multiplication, and division.\n")
  print(str(handleOperation(userInput, num)) + " is the result of this session.")
  boolean = str(input("\nWould you like to try another operation? y/n\n")).lower()
  if (boolean == "y"):
    start()
  else:
    print("\nThank you for using my simple calculator! If you have suggestions then please message them to me.")
    exit()

# A startup message.
print("Simple Calculator V1.0 B1\n")
print("Welcome to the simple calculator.")
print("The calculator currently supports simple operations such as")
print("Multiplication, Division, Addition, and Subtraction.\n")

start()
