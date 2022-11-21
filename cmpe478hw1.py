import numpy as np
import matplotlib.pyplot as plt

#-----------------------------------------------------------

#read a txt file and return a list of lines
def read_file(filename):
    with open(filename) as f:
        content = f.readlines()
    content = [x.strip() for x in content]
    return content

#-----------------------------------------------------------

#content holds the list of lines
content = read_file("cmpe478hw1.txt")
#create a dictionary named dictionary
dictionary = {}
#we will split the lines into words, 2nd value will be the key, 1st value will be the value in the dictionary
for line in content:
    words = line.split()
    if len(words) == 2:
        #if the key is in the dictionary, we will append the value to the list of values
        if words[1] in dictionary:
            dictionary[words[1]].append(words[0])
        #if the key is not in the dictionary, we will add the key and the value to the dictionary
        else:
            dictionary[words[1]] = [words[0]]

#-----------------------------------------------------------

#we now have the dictionary with the key being the 2nd value in the line and the values being the list of 1st values in the line

#-----------------------------------------------------------
