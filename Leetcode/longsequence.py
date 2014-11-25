class pairs:
	def __init__(self, id, step):
		self.id = id
		self.step = step
class Solution:
	# @param num, a list of integer
	# @return an integer
	def longestConsecutive(self, num):
		print "this num is ", num
		dict0 = {}
		dict_num = {}
		for i in range(len(num)):
			val = num[i]
			if val in dict0:
				tmp = dict0[val]
				dict_num[tmp.id] = dict_num[tmp.id] + 1
				dict0.pop(val)
				if val+tmp.step in dict0:
					
				dict0[val+tmp.step] = tmp
			else:
				p0 = pairs( i,-1)
				p1 = pairs( i, 1)
				dict0[ val-1] = p0
				dict0[ val+1] = p1
				dict_num[i] = 1

		print dict_num

		print dict0

#if __name__ == "__mian__":
num = [100, 4, 200, 1, 3, 2]
Solution().longestConsecutive(num)
