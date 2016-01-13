a = raw_input().split()
if a[2] == "week":
	if a[0] == "1":
		print "52"
	elif a[0] == "2":
		print "52"
	elif a[0] == "3":
		print "52"
	elif a[0] == "4":
		print "52"
	elif a[0] == "5":
		print "53"
	elif a[0] == "6":
		print "53"
	else:
		print "52"
else:
	if int(a[0]) <= 29:
		print "12"
	elif int(a[0]) == 30:
		print "11"
	else:
		print "7"
