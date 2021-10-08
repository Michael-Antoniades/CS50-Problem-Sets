from sys import argv
import math
from cs50 import get_string
import csv

def main():
    
    if len(argv) == 3:
        
        with open(argv[1] , "r" ) as file:
            reader = csv.reader(file)
  
            dict_from_csv = {line[0]:line[1:len(line)] for line in reader} #very powerful line of code 
            # I had a for loop seperate to start for line in reader:, and could successfully loop through CSV
            # but was having trouble assigning it to an array, was able to make this dynamic array with csv data AND 
            # have for loop within it.  Found this helpful reference: https://www.delftstack.com/howto/python/python-csv-to-dictionary/
                
              
                
        with open(argv[2] , "r") as file2:
            reader = csv.reader(file2)
            
            for array in reader:
                sequence = array
                
        loop_length = 0 
        loop_length = len(dict_from_csv)       
        print(loop_length)
        print(dict_from_csv)
        
        
        #key,val = dict_from_csv.items()[0]
        #for value in dict_from_csv.values():
         #   if value =
        #sequence = dict_from_csv.get(0)
        #print(sequence)
        for key, value in dict_from_csv.items():
            print(key,value)
            if key == "name":
                break
        
            
            
                
                
                
        
        #sys.exit(0)
    
    
    
    
    
    
    
    
    elif len(argv) != 3:               
        #moved this non-3 argv case at the bottom of main to keep it out of the way 
        print("Proper usage is: python dna.py data.csv sequence.txt")
        #sys.exit(1)
if __name__ == "__main__":
    main()
