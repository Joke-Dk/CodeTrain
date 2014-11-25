class A:
	def __init__(self, value):
		self.val = value
def change(a):
	a.val = 100
if __name__ == "__main__":
	a = A(1)
	b = a
	print a.val, b.val
	a.val = 10
	print a.val, b.val
	change(b)
	print a.val, b.val
	
	tmp=a
	tmp = A(1000)
	print a.val, b.val

