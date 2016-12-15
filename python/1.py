from urllib2 import Request, urlopen, URLError
import json
 

request = Request('http://codeforces.com/api/user.status?handle=rahulnagurtha&from=1&count=5')

import datetime

dict = {}

try:
	response = urlopen(request)
	kittens = response.read()
	converted = json.loads(kittens)
	# print len(converted)
	for x in xrange(0,5):
		print converted['result'][x]
		curVal = converted['result'][x]['creationTimeSeconds']
		temp = datetime.datetime.fromtimestamp(curVal).strftime('%Y-%m-%d')
		print converted['result'][x]['id'] ,
		print temp
except URLError, e:
    print 'No kittez. Got an error code:', e