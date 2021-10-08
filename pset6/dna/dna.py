from sys import argv
import math
from cs50 import get_string
import csv

def main():
    
    if len(argv) == 3:
        
        with open(argv[1] , "r" ) as file:
            reader = csv.reader(file)
            
            for line in reader:
                name = line[0]
                counts = line
                dictionary = {
                    name : counts[1:len(line)]
                }
                
                print(dictionary)
                
        with open(argv[2] , "r") as file2:
            reader = csv.reader(file2)
            
            for array in reader:
                sequence = array
                
        
        for         
            
                
                
                
        
        #sys.exit(0)
    
    
    
    
    
    
    
    
    elif len(argv) != 3:               #moved this non-3 argv case at the bottom of main to keep it out of the way 
        print("Proper usage is: python dna.py data.csv sequence.txt")
        #sys.exit(1)
if __name__ == "__main__":
    main()
