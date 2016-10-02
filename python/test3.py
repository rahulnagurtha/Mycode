import os
import re
import sys      	

def callme(temp):
	bible = open(temp,"r")
	regex = re.compile('index.html@sub=[0-9]+&amp;brch=[0-9]+&amp;sim=[0-9]+.html|index.html@sub=[0-9]+&amp;brch=[0-9]+.html|index.html@sub=[0-9]+.html|index.html@sub=[0-9]+&amp;brch=[0-9]+&amp;sim=[0-9]+&amp;cnt=[0-9]+.html')
	for line in bible:
	    four_letter_words = regex.findall(line)
	    for word in four_letter_words:
	        print word

for dirname, dirnames, filenames in os.walk('D:/test'):
    for filename in filenames:
    	temp = os.path.join(dirname,filename)
    	callme(temp)
        # print temp
    