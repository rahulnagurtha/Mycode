from urllib2 import Request, urlopen, URLError
import json

 

request = Request('http://codeforces.com/api/user.status?handle=sumeet.varma&from=1&count=1750')

import datetime

dict = {}

try:
	response = urlopen(request)
	kittens = response.read()
	converted = json.loads(kittens)
	# print len(converted)
	for x in xrange(0,1750):
		curVal = converted['result'][x]['creationTimeSeconds']
		temp = datetime.datetime.fromtimestamp(curVal).strftime('%Y-%m')
		dict[temp] = dict.get(temp, 0) + 1
except URLError, e:
    print 'No kittez. Got an error code:', e


print dict