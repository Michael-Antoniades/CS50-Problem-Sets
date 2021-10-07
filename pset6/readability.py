from cs50 import get_string
import math


def main():

    L = 0; # initialization for number of letters
    W = 1; # initialization for number of words, starts at 1
    S = 0; # initialization for number of sentences
    index = 0; #part of the equation determining reading level
    titlecheck = False #trigger for subtracting a sentence if a Mr./Mrs. or Dr. title is input

    text = get_string("Text: ")
    length = len(text)
    
    for i in range(0,length,1):
            if text[i] != chr(32) and text[i] != chr(33) and text[i] != chr(63) and text[i] != chr(39) and text[i] != chr(44):
                L+=1
            elif text[i] == chr(32):
                W+=1
            
            if text[i] == chr(33) or text[i] == chr(46) or text[i] == chr(63):
                S+=1;
                titlecheck = True;
            else: 
                titlecheck = False;
            if titlecheck and ((text[i-2] <= chr(90) and text[i-2] >= chr(65) or (text[i-3] <= chr(90) and text[i-3] >= chr(65)))):
                S -=1;
    AL = 100 * L / W
    AS = 100 * S / W
    index = (0.0588 * AL) - (0.296 * AS) - 15.8
    
    grade = math.floor(index)
    ww = round(W)
    ss = round(S)
    ll = round(L)
    
    if grade <= 1:
        print("Before Grade 1\n")
    elif grade >=2 and grade <=16:
        print("Grade", grade)
    elif grade > 16:
        print("Grade: 16+\n")
    
if __name__ == "__main__":
    main()
