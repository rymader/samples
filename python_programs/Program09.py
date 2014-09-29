# Ryan Mader Program09.py
# CSCI 1521
# 4/3/12
from random import randrange

# This program demonstrates the odds of
# winning a game of craps by simulating a 
# number of games selected by the user.

# Start of main 
def main():

    # Will keep looping as long as again == "Yes"
    again = "Yes"

    # Start by calling the printIntro function
    printIntro()

    # While loop to repeat after invalid input
    while again == "Yes":

        # Will use exceptions for bad input
        try:

            # Get the number of games to be simulated
            n = getNumberOfGames()

            # Pass that number to the craps simulator, get win/loss
            win, loss = playCraps(n)

            # print the results of the simulation
            getResults(win, loss, n)

            # To terminate while loop
            again = "No"

        # Exceptions for invalid input
        except TypeError:
            errorMessage()
        except NameError:
            errorMessage()
        except SyntaxError:
            errorMessage()
        except ZeroDivisionError:
            errorMessage()
        

# printIntro function prints message describing the program
def printIntro():
    print("This program simulates the probability of winning\na"
          ,"game of craps. Enter the number of games you wish to simulate.\n")

# getNumberOfGames function returns number of games to be simulated
def getNumberOfGames():
        
    n = eval(input("How many games do you wish to simulate? "))

    # Will validate input to make sure the number entered is positive
    while n < 0:
        print("\nError, invalid input! Please enter a positive number.\n")
        n = eval(input("How many games do you wish to simulate? "))
    return n
    
# playCraps function gets number of games, returns win/loss count
def playCraps(n):
        
    # initialize win & loss to 0
    win = 0
    loss = 0

    # Counted loop for number of simulations specified
    for i in range(n):
        dice1 = randrange(1,7)
        dice2 = randrange(1,7)

        # Decide if the first roll == loss
        if dice1 + dice2 == (2 or 3 or 12):
            loss = loss + 1

        # Else decide if first roll == win
        elif dice1 + dice2 == (7 or 11):
            win = win + 1

        # Else call playForPoint function to conculde game
        else:
            point = dice1 + dice2
            result = rollForPoint(point)

            # returned answer determines win or loss
            if result == "Yes":
                win = win + 1
            else:
                loss = loss + 1

    # return total win/loss count to main
    return win, loss

# rollForPoint function concludes game if not concluded in playCraps
def rollForPoint(point):
    
    # intitialize total at 0
    total = 0
    

    # while loop to roll until total == 7 or point
    while not(total == 7 or total == point):
        dice1 = randrange(1,7)
        dice2 = randrange(1,7)
        total = dice1 + dice2

    # Determine result 
    if total == point:
        result = "Yes"
    else:
        result = "No"

    # return value to playCraps
    return result

# getResults function will print the results of the simulation
def getResults(win, loss, n):

    # print results
    print("\nThe number of wins is {0} ({1:0.1%})".format(win, win/n))
    print("The number of losses is {0} ({1:0.1%})".format(loss, loss/n))

# function is called when exceptions are found
def errorMessage():
    print("\nError, invalid input! Please enter a positive integer (larger than 0)")
    print("without any spaces, characters, or words.\n")
    
    
    

if __name__ == '__main__' : main()
    
        

    


































    
































        

    

    
