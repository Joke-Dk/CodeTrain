X='X'
O='O'
board0 =["OOOOOOOOOOOOOOOOOOOOOOOOXXXXXXXOOO"]
	
class Solution:
	def travel(self, board, i, j):
		if self.visited[i][j] == 1 or board[i][j] == 'X': return
		self.visited[i][j] = 1
		if self.switch_place == True:
			board[i][j] = 'X'
		if i+1<=self.row-1:
			self.travel(board, i+1, j)
		if i-1>=0:
			self.travel(board, i-1, j)
		if j+1<=self.col-1:
			self.travel(board, i, j+1)
		if j-1>=0:
			self.travel(board, i, j-1)
		
			
	def solve(self, board):
		#print board
		self.row = len(board)
		self.col = len(board[0])
		self.visited = [ [0 for x in range(self.col)] for y in range(self.row)]
		#print flag
		
		#travel bound
		self.switch_place = False
		for i in range(self.row):
			self.travel(board, i, 0)
			self.travel(board, i, self.col-1)
		for j in range(self.col):
			self.travel(board, 0, j)
			self.travel(board, self.row-1, j)
		
		#travel inter
		self.switch_place = True
		for i in xrange(1,self.row-1):
			for j in range(1,self.col-1):
				self.travel(board, i, j)
				
if __name__ == "__main__":
	s = Solution()
	print 'origin', board0
	s.solve(board0)
	print 'after', board0
