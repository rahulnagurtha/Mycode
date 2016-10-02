import os
import re
import sys

rootdir='D:/test'

def doWhatYouWant(line):
    return line
for subdir, dirs, files in os.walk(rootdir):
    for file in files:
        f=open(file, 'r')
        lines=f.readlines()
        for line in lines:
            print line