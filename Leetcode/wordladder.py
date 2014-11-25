class Solution:
	def ladderLength(self, start, end, dict):
		dict.append(start)
		dict.append(end)
		N = len(dict)
		mat = [[False for i in range(N)] for j in range(N)]
		#build graph
		for i in range(N):
			for j in range(i+1,N):
				mat[i][j] = self.compare_link(dict[i], dict[j])
				mat[j][i] = mat[i][j]
				#print dict[i], dict[j], mat[i][j]
		#print mat

		#traval

	def compare_link(self, str0, str1):
		cout = sum([str0[i]!=str1[i] for i in range(len(str0))])
		if cout == 1:
			return True
		else:
			return False
if __name__ == "__main__":
	start = "hit"
	end = "cog"
	dict = ["hot","dot","dog","lot","log"]
	Solution().ladderLength(start, end, dict)
