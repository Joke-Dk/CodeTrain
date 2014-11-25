class Solution:
	def longestConsecutive(self, num):
		self.dic = { i:1 for i in num}
		max_val = -1
		#print self.dic
		for i in num:
			if i in self.dic:
				tmp = self.find_next(i, -1) + self.find_next(i, 1) + 1
				max_val = max(max_val, tmp)
		return max_val

	def find_next(self, index, step):
		ret = 0
		tmp = index+step
		while(tmp in self.dic):
			ret += 1
			self.dic.pop(tmp)
			tmp += step
			
		return ret
num = [100, 4, 200, 1, 3, 2, 12, 6, 5, 7,9]
print Solution().longestConsecutive(num)

