#Definition for a  binary tree node

class Solution:
	# @param root, a tree node
	# @return an integer
	def travel( self, node, cur_value):
		#prove this node isn't none
		cur_value = cur_value*10+node.val
		if node.left is None and node.right is None:
			#this node is leaf node
			self.ret += cur_value	
		else:      
			if node.left is not None:
				self.travel(node.left, cur_value)
			if node.right is not None:
				self.travel(node.right, cur_value)
	def sumNumbers(self, root):
		self.ret = 0
		self.travel( root, 0)
		return self.ret 

class TreeNode(object):
	def __init__(self, x):
		self.val = x
		self.left = None
		self.right = None
if __name__ == "__main__":
	a = TreeNode(1)
	b = TreeNode(2)
	c = TreeNode(3)
	a.left = b
	a.right = c
	print Solution().sumNumbers(a)
	
