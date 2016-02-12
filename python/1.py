from bs4 import BeautifulSoup

soup = BeautifulSoup(open("test.html"),'html.parser')
a = soup.find_all("div",{"class":"commentary-event"})

for x in a:
	y = x.find_all("div")
	if len(y) > 1:
		print "insert into Commentary values ("
		print " ".join(str((y[0].text).encode('ascii','ignore')).split()),
		print ",'",
		print " ".join(str((y[1].text).encode('ascii','ignore')).split()),
		print "');"
	else:
		print "insert into Commentary values (-1.0"
		print ", '",
		print " ".join(str((y[0].text).encode('ascii','ignore')).split()),
		print "');"
	print "\n"