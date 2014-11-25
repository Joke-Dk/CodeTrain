class Solution:
    # @param num, a list of integer
    # @return an integer
	def longestConsecutive(self, num):
		self.dic = {}
		for i in range(len(num)):
			val = num[i]
			if val-1 in self.dic and val+1 in self.dic:
				tmp01 = self.dic[val-1]
				tmp02 = self.dic[val+1]
				self.dic.pop(val-1)
				self.dic.pop(val+1)
				tmp01.num = tmp01.num+tmp02.num+1
				tmp01.right = tmp02.right
				self.dic[tmp02.right] = tmp01
				self.dic[tmp01.left]  = tmp01
			elif val-1 in self.dic:
				self.exchange(val-1, val)
			elif val+1 in self.dic:
				self.exchange(val+1, val)
			else:
				label_new = label(i, val)
				self.dic[val] = label_new
			print "___________%d____insert_%d____" % (i, val)
        	for ( d, x) in self.dic.items():
        		print d, x.i, x.num, x.left, x.right
		#find the max label
		#print max([x.num for (d, x) in self.dic.items()])
		print max([self.dic[d].num for d in self.dic])
			
	def exchange(self, old_val, new_val):
		tmp = self.dic[old_val]
		if tmp.left< new_val and tmp.right>new_val:
			return
		tmp.num = tmp.num+1
		if old_val < new_val:
			tmp.right = new_val
		else:
			tmp.left = new_val
		if tmp.num is not 2:
			self.dic.pop(old_val)
		self.dic[new_val] = tmp
class label:
	def __init__(self, i, val):
		self.i = i
		self.num = 1
		self.left = val
		self.right = val
#if __name__ == "__mian__":
num = [0,0]#[100, 4, 200, 1, 3, 2,6,3,2,5,9,7,8]
Solution().longestConsecutive(num)
