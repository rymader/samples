# Ryan Mader  Program12.py
# CSCI-1521
# 5/4/12

# palindrome function
def palindrome(s):

    # If/else structure with multiple
    # stopping criteria and scenarios for recursion
    if s == "":  # False stopping criteria not met, even string
        return True 
    elif len(s) == 1: # False stopping criteria not met, odd string
        return True
    # If ASCI code for char not in range of lowercase a-z,
    # remove element from string
    elif ord(s[0]) < 97 or ord(s[0]) > 122:
        return palindrome(s[1:])
    elif ord(s[len(s)-1]) < 97 or ord(s[len(s)-1]) > 122:
        return palindrome(s[:len(s)-1])
    # False Stopping criteria, string is not a palindrome
    elif s[0] != s[len(s)-1]:
        return False
    # Ordinary recursion, no punctuation or spaces
    else:
        return palindrome(s[1:len(s)-1])

# Main function
def main():
    
    # Get string from user
    s1 = input("Enter a word or phrase: ") 
    s1 = s1.lower() # Convert all letters to lowercase

    # Pass string to palindrome function, get true false answer
    if palindrome(s1) == True:
        print("It is a palindrome")
    else:
        print("It is not a palindrome")
            
main()

        
    
