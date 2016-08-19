class EllysNumberGuessing(object):
	def getNumber(self,guesses,answers):
		initial = []
		if guesses[0] - answers[0] >= 1:
			initial.append(guesses[0] - answers[0])
		if guesses[0] + answers[0] <= 10**9:
			initial.append(guesses[0] + answers[0])
		finalAnswer = set(initial)
		print finalAnswer
		for x in xrange(1,len(guesses)):
			cur = []
			if guesses[x] - answers[x] >= 1:
				cur.append(guesses[x] - answers[x])
			if guesses[x] + answers[x] <= 10**9:
				cur.append(guesses[x] + answers[x])
			finalAnswer = finalAnswer.intersection(set(cur))
		if len(finalAnswer) == 1:
			return list(finalAnswer)[0]
		elif len(finalAnswer) == 0:
			return -2
		else:
			return -1