from sys import argv
import math
from cs50 import get_string
import csv
import re 

def main():
    
    if len(argv) == 3:
        with open(argv[1] , "r" , newline = '' ) as file:
            reader = csv.reader(file)
            for line in reader:
                header = line #gives us our header line which is excluded from comp_array not sure why
                people_array = list(reader) # populates an array of all information minus header
            #dict_from_csv = {line[0]:line[1:len(line)] for line in reader} #very powerful line of code 
            # I had a for loop seperate to start for line in reader:, and could successfully loop through CSV
            # but was having trouble assigning it to an array, was able to make this dynamic array with csv data AND 
            # have for loop within it.  Found this helpful reference: https://www.delftstack.com/howto/python/python-csv-to-dictionary/
            
        with open(argv[2] , "r") as file2:
            reader = csv.reader(file2)
            
            for line in reader:
                sequence = list(line)
                #print(sequence[0]) #test line works as intended
                sequence_max= (len(sequence[0]))
        
        #print(sequence)
    
        header_length = len(header) #for loop to iterate from 1 to 8 like our header file and count each occurence in sequence
        match_array = []
        print(header)
        print(header[3])
        for i in range(1,header_length,1):
            
            x = sequence[0].count(header[i]) 
            match_array.append(x) # returns an array that is full of all the counts we need
        #print(match_array)
        #print(people_array)
        
        number_of_people = len(people_array)
        people_count = number_of_people
       #print(people_array)
        print(match_array)
        print(people_array[1][1:header_length])
    
        arrayk = [31, 21, 41, 28, 30, 9, 36, 44]
        arrayj = [31, 21, 41, 28, 30, 9, 36, 44]
        #print(arrayk)
        
        if arrayj == arrayk:
            print("ilovelamp")
        
        for m in range(0,people_count,1): 
            #print(people_array[m][1:header_length])
            if people_array[m][1:header_length] == match_array:
                print(people_array[m][0])
            #else:
                #print("oops")
        
  
        
        
        #key,val = dict_from_csv.items()[0]
        #for value in dict_from_csv.values():
         #   if value =
        #sequence = dict_from_csv.get(0)
        #print(sequence)
        #for key, value in dict_from_csv.items():

            #print(value)
            #print(len(value))
            #if key == "name":
                #break
                
                #this section for a dictionary approach which turned out to not be as easy
        
            
            
                
                
                
        
        #sys.exit(0)
    
    
    
    
    
    
    
    
    elif len(argv) != 3:               
        #moved this non-3 argv case at the bottom of main to keep it out of the way 
        print("Proper usage is: python dna.py data.csv sequence.txt")
        #sys.exit(1)
if __name__ == "__main__":
    main()
