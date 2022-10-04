import random

#A list of questions to create 15 questions from.
questionList = []

# Configuration
amountOfQuestions = 15

# Question, Answer, Choice, Choice, Choice
questionList.append(["What is 1 + 1?","An expression","2","Two","Math"])
questionList.append(["Random Question answer is 1","1","One","Uno","Isa"])

# Creates a list of random questions.
def createQuestions(amount):
  questionListCopy = questionList
  questions = []

  if type(amount) != int:
    print("The method createQuestions(amount) only accepts an int!")
    return questions
  
  while len(questions) < amount:
    if len(questionListCopy) == 0:
      print("We ran out of questions to do " + str(amount) + ", but we still have " + str(len(questions)) + " questions :)")
      break
    
    randInt = random.randint(0, len(questionListCopy)-1)
    questions.append(questionListCopy[randInt])
    questionListCopy.pop(randInt)
  return questions

def doQuestions(questionsToUse):
  questionsAmount = len(questionsToUse)

  # Avoiding errors.
  if type(questionsToUse) != list:
    print("This method does not accept " + type(questionsToUse))
    return False
  if len(questionsToUse) == 0:
    print("The list of questions is empty!")
    return False
  for i in range(len(questionsToUse)):
    if type(questionsToUse[i]) != list or len(questionsToUse[i]) != 5:
      print("An item in the list is not a question!")
      return False
  
  questionNumber = 1
  points = 0

  print("=====================================================\n")
  print("Welcome to my test!\n")
  while len(questionsToUse) > 0:

    # Creates choices
    tempChoices = [1,2,3,4]
    choices = []

    for i in range(4):
      #print(str(tempChoices))
      randInt = tempChoices[random.randint(0,len(tempChoices)-1)]
      #print(str(randInt))
      tempChoices.remove(randInt)
      choices.append(randInt)
      if randInt == 1:
        questionAnswer = "ABCD"[len(choices)-1]
    
    question = questionsToUse.pop()

    userAnswer = input(str(questionNumber) + ". " + str(question[0])
    + "\n A. " + question[choices[0]]
    + "\n B. " + question[choices[1]]
    + "\n C. " + question[choices[2]]
    + "\n D. " + question[choices[3]] + "\nYour Answer: ").upper()
    while not userAnswer in "ABCD":
      userAnswer = input("\nThat is not a valid answer! (Example: A)\nYour Answer: ").upper()
    print("\n")
    
    if questionAnswer == userAnswer:
      points += 1
    questionNumber += 1

  print("\nCongratulations, you got a score of " + str(points) + " out of " + str(questionsAmount))
    
print("Logs:")
doQuestions(createQuestions(amountOfQuestions))
