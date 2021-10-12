from sys import argv
import math
from cs50 import get_string
from csv import reader, DictReader
import re 

def main():

if len(argv) < 3 or len(argv) > 4:
    print("Proper usage is: python dna.py data.csv sequence.txt")
    exit()

# read the dna sequence
with open(argv[2] , "r" , newline = '') as dnafile:
    dnareader = reader(dnafile)
    for row in dnareader:
        dnalist = row
            #dict_from_csv = {line[0]:line[1:len(line)] for line in reader} #very powerful line of code used at first
            # I had a for loop seperate to start for line in reader:, and could successfully loop through CSV
            # but was having trouble assigning it to an array, was able to make this dynamic array with csv data AND 
            # have for loop within it.  Found this helpful reference: https://www.delftstack.com/howto/python/python-csv-to-dictionary/
# store it in an array
dna = dnalist[0]
sequences = {}
#extract the DNA we'd like to match from argument 1, our database
with open(argv[1] , "r") as peoplefile:
    people = reader(peoplefile)
    for row in people:
        dnaSequences = row
        dnaSequences.pop(0)
        break
    
# create dnaSequence dictionary, initialize to 0.  keys will be database sequences
for item in dnaSequences:
    sequences[item] = 0
   
# iterate trough the dna sequence, when repititions are found, the sequence dictionary are counted
for key in sequences:
    l = len(key)
    tempMax = 0
    temp = 0
    for i in range(len(dna)):
        # Logic for counting that sequence and then tells us to go onto next one 
        while temp > 0:
            temp -= 1
            continue
        # if the segment of dna corresponds to the key and there is a repetition we increase our count
        if dna[i: i + l] == key:
            while dna[i - l: i] == dna[i: i + l]: #repitition logic
                temp += 1
                i += l

            # compares the value to the previous longest sequence to the longest
            if temp > tempMax:
                tempMax = temp

    # stores new longest key
    sequences[key] += tempMax

# open and iterate trough the database of people treating each one like a dictionary so it can compare to the sequences one
with open(argv[1], "r") as peoplefile:
    people = DictReader(peoplefile)
    for person in people:
        match = 0
        # compares the sequences to every person and prints name before leaving the program if there is a match
        for dna in sequences:
            if sequences[dna] == int(person[dna]):
                match += 1
        if match == len(sequences):
            print(person['name'])
            exit()


    print("No match")

if __name__ == "__main__":
    main()
