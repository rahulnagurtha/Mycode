from __future__ import print_function

import re,os,sys

#function to find title of file
def find_title(filename):
	f = open(filename, 'r')
	pattern = re.compile("<div class=\"title\">(.*?)</div>")
	for line in f:
		match = pattern.findall(line)
		if(len(match) > 0):
			print(match[0])
			title = match[0].strip().replace(' ', '-').replace('/','-')
			f.close()
			return title

#dictionary mapping old to new locations
BASEPATH = os.getcwd();
loc = {"index.html": BASEPATH + '/index.html'}

#apply function operate on all filenames matching pattern
#pattern must match to give 2 groups
def rearrange(pattern, operate):
	file_list = [fstr for fstr in os.listdir(BASEPATH) if os.path.isfile(fstr)]
	for filename in file_list:
		m = pattern.match(filename)
		if m:
			operate(m.group(0), m.group(1), m.group(2))

#operate for creating new directories
def operate(filename, parent, present):
	new_path = os.path.dirname(loc[parent + ".html"])
	print(new_path)
	new_path = os.path.join(new_path, find_title(filename))
	print(new_path)
	os.mkdir(new_path)
	new_path = os.path.join(new_path, "index.html")
	os.rename(filename, new_path)
	loc[filename] = new_path

#operate for experiments
def expt_operate(filename, parent, present):
	new_path = os.path.dirname(loc[parent + ".html"])
	print(new_path)
	new_path = os.path.join(new_path, find_title(filename))
	print(new_path)
	if(not os.path.exists(new_path)):
		os.mkdir(new_path)
	new_path = os.path.join(new_path, present+".html")
	os.rename(filename, new_path)
	loc[filename] = new_path
	

#classify departments
rearrange(re.compile("(index).html@sub=(\d+).html"), operate)
rearrange(re.compile("(index.html@sub=\d+)&brch=(\d+).html"), operate)
rearrange(re.compile("(index.html@sub=\d+&brch=\d+)&sim=\d+&cnt=(\d+).html"), expt_operate)



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
print "here"
print loc["index.html@sub=58&brch=160&sim=382&cnt=1972.html"]