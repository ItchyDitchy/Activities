Height = input(" Please Enter your Height: ")
Weight = input(" Please Enter the Weight: ")
Age = input(" Please Enter the Age: ") #IDK where to use this to calculate BMI...
parsedHeight = float(Height)
parsedWeight = float(Weight)
parsedAge = int(Age) # Just to give an error if they typed a random value.
print("Your BMI is equal to " + str(parsedWeight / parsedHeight ** 2))
print("Your age is also " + str(parsedAge) + " for no reason")
#Also can use if and elif statements for checking if they are either underweight, normal, overweight, obese or extremely obese.
