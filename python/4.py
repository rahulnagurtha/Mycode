previous = {0:1L, 1:1L}
def fibonacci(n):
	if previous.has_key(n):
		return previous[n]
	else:
		newValue = fibonacci(n-1) + fibonacci(n-2)
		previous[n] = newValue
		return newValue

print fibonacci(50)
