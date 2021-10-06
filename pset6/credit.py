from cs50 import get_int
import math



def main():

    while True:
        ccn = get_int("Number: ")
        
        numdigits = math.floor(math.log10(ccn) +1); #works the same under the hood as C version
        if (numdigits > 16 or numdigits < 13 or numdigits == 14):
            print("Invalid Length Error")
            print(numdigits)
            break

        else:
            ccnholder = ccn;
            sumation = 0; #global sumation
            for i in range(0, ccn!= 0, 1):          #lines 20-29 are my problem, they are behaving differently than C does, some cases work others don't 
                ccn = math.floor(ccn/10);
                if i%2 == 0:
                    sumation += ccn % 10;
                    print(sumation);
                else:
                    seperator = 2 * (ccn % 10);
                    print(seperator);
                    sumation += math.floor(seperator / 10) + seperator % 10;
                    print(sumation);
                    
            if sumation%10 == 0:
                if (ccnholder >= 34e13 and ccnholder < 35e13) or (ccnholder >= 37e13 and ccnholder < 38e13):
                    print("AMEX\n")
                elif (ccnholder >= 4e12 and ccnholder < 5e12) or (ccnholder >= 4e15 and ccnholder < 5e15):
                    print("VISA\n")
                elif (ccnholder >= 5.1e15 and ccnholder < 5.6e15):
                    print("MASTERCARD\n")
                    break
                else:
                    print("INVALID Error 2\n")
            #else:
             #   print("INVALID Error 1\n")





if __name__ == "__main__":
    main()

    
    
    
    ################################################################## v2 a little different with lines 20 thru 29, 25 thru 29 are the issue
    from cs50 import get_int
import math



def main():

    while True:
        ccn = get_int("Number: ")
        
        numdigits = math.floor(math.log10(ccn) +1); #works the same under the hood as C version
        if (numdigits > 16 or numdigits < 13 or numdigits == 14):
            print("Invalid Length Error")
            print(numdigits)
            break

        else:
            ccnholder = ccn;
            sumation = 0; #global sumation
            for i in range(0, ccn!= 0, 1):          #lines 20-29 are my problem, they are behaving differently than C does, some cases work others don't 
                ccn = math.floor(ccn/10);
                if math.remainder(i,2) == 0:
                    sumation += math.remainder(ccn,10);
                    
                else: #lines 25-29 are now the case I have to look out for
                    seperator = 2 * math.remainder(ccn,10);
                    
                    sumation += seperator / 10 + math.remainder(seperator,10);
                    print(sumation);
                    
            if math.remainder(sumation,10) == 0:
                if (ccnholder >= 34e13 and ccnholder < 35e13) or (ccnholder >= 37e13 and ccnholder < 38e13):
                    print("AMEX\n")
                elif (ccnholder >= 4e12 and ccnholder < 5e12) or (ccnholder >= 4e15 and ccnholder < 5e15):
                    print("VISA\n")
                elif (ccnholder >= 5.1e15 and ccnholder < 5.6e15):
                    print("MASTERCARD\n")
                    break
                else:
                    print("INVALID Error 2\n")
            #else:
             #   print("INVALID Error 1\n")





if __name__ == "__main__":
    main()
