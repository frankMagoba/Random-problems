#!/bin/python3

import sys
import copy

class ValidPlus:

    def __init__(self):
        self.area = 1
        self.length = 1
        self.cells = []

    def addCell(self, cell):
        self.cells.append(cell)

class Cell:

    def __init__(self, row, column):
        self.row = row
        self.column = column

    def __str__(self):
        return str(self.row) + str(self.column)

    def __hash__(self):
        return hash(str(self))

    def __eq__(self, other):
        return self.row == other.row and self.column == other.column

    def __gt__(self, other):
        return self.row > other.row and self.column > other.column

    def __lt__(self, other):
        return self.row < other.row and self.column < other.column


if __name__ == '__main__':
    n, m = input().strip().split(' ')
    n, m = [int(n), int(m)]
    grid = []
    grid_i = 0
    for grid_i in range(n):
        grid_t = str(input().strip())
        grid.append(grid_t)

    # We save all the valid pluses

    validPluses = []
    for i in range(n):
        for j in range(m):
            current_cell = grid[i][j]
            if current_cell == 'G':
                there_is_a_good_cell = True
                # Everytime we find a good cell, we create a valid plus
                # With length 1
                validPlus = ValidPlus()
                length = 1
                validPlus.addCell(Cell(i,j))
                validPluses.append(validPlus)
                while there_is_a_good_cell:
                    # We check if it's possible to extend the valid plus in
                    # all the four directions
                    if (i - length >= 0 and grid[i - length][j] == 'G') and (i + length < n and grid[i + length][j] == 'G') and (j - length >= 0 and grid[i][j - length] == 'G') and (j + length < m and grid[i][j + length] == 'G'):
                        # If it's possible, we create a new valid plus
                        new_valid_plus = copy.deepcopy(validPlus)
                        new_valid_plus.addCell(Cell(i - length, j))
                        new_valid_plus.addCell(Cell(i + length, j))
                        new_valid_plus.addCell(Cell(i, j - length))
                        new_valid_plus.addCell(Cell(i, j + length))
                        length += 1
                        new_valid_plus.area = 1 + (4 * (length - 1))
                        new_valid_plus.length = length
                        validPluses.append(new_valid_plus)
                        validPlus = copy.deepcopy(new_valid_plus)
                    else:
                        there_is_a_good_cell = False

    max_area = 0

    # We compare all the valid pluses
    for i in range(len(validPluses)):
        current_valid_plus = validPluses[i]
        for j in range(i + 1, len(validPluses)):
            other_valid_plus = validPluses[j]
            current_area = current_valid_plus.area * other_valid_plus.area
            if current_area > max_area:
                # If we have found a new max area, we have to check that
                # the valid pluses don't overlap.
                # To do this, we get the cells occupied by the two valid
                # pluses
                current_cells = current_valid_plus.cells
                other_cells = other_valid_plus.cells
                common_cells = set(current_cells) - (set(current_cells) - set(other_cells))
                # If the valid pluses don't have common cells, it's OK
                if len(common_cells) == 0:
                    max_area = current_area
    print(max_area)