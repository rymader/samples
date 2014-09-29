# Ryan Mader Program04.pyw
# CSCI 1521
# 2-7-12
# NOTE: graphics.py is required to run this program

import math
from graphics import *

def main():

    # Set the graphics window 
    win = GraphWin("Line distance & slope calculator", 400, 400)
    win.setBackground("red") # Makes the cyan midpoint easier to see.
    win.setCoords(0.0, 0.0, 10.0, 10.0) # creates a domain & range of [0, 10]
    message = Text(Point(5, 0.5), "Click on two points anywhere in this window")
    message.draw(win)

    # Get two points and draw a line with a midpoint
    p1 = win.getMouse()
    p2 = win.getMouse()
    line1 = Line(p1, p2)
    midpoint = line1.getCenter() # Automatically locates the midpoint of p1 & p2.
    midpoint.setFill("cyan")
    line1.draw(win)
    midpoint.draw(win)

    # Calcualate the slope and distance between the points
    x1 = p1.getX()
    x2 = p2.getX()
    y1 = p1.getY()
    y2 = p2.getY()
    dx = x2 - x1 # delta x
    dy = y2 - y1 # delta y
    slope = dy/dx # Calculates the slope of the line
    distance = math.sqrt(dx**2 +dy**2) # Calculates the distance between two points

    # Print the slope and distance on the window
    #
    # *Note* I had issues with brackets {} appearing anytime I tried to
    # fudge the spacing between the slope and distance on the window
    # and I could only change the output of 'message' correctly by putting the slope,
    # distance, and string literals in the variable 'output';
    # This part gave me the most difficulty.
    #
    output = "Slope=" , round(slope, 2), "Distance=", round(distance, 2)
    message.setText(output)

    # Click mouse to end program
    win.getMouse()
    win.close()
    
main()
    
