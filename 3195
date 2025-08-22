class Solution(object):
    def minimumArea(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        top_left_corner = [len(grid),len(grid[0])] # vertical then horizontal coordinate
        found_top = False
        for i in range(len(grid)):
            for j in range(top_left_corner[1]):
                if grid[i][j] and not found_top:
                    top_left_corner[0] = i
                    found_top = True
                if grid[i][j] and j < top_left_corner[1]:
                    top_left_corner[1] = j
        
        bottom_right_corner = [0,0]
        found_bottom = False
        for i in range(len(grid) - 1,-1,-1):
            for j in range(len(grid[i]) - 1,bottom_right_corner[1]-1,-1):
                if grid[i][j] and not found_bottom:
                    bottom_right_corner[0] = i
                    found_bottom = True
                if grid[i][j] and j > bottom_right_corner[1]:
                    bottom_right_corner[1] = j

        return (top_left_corner[0] - bottom_right_corner[0] - 1) * (top_left_corner[1] - bottom_right_corner[1] - 1)

                
        
