#
# Author: James Ortiz
# File: a_plus_b.py
# Description: Calculate a+b (Number: 1000)
# Input: 1 5
# Output: 6
#

def sum(a, b):
    return a + b

a, b = map(int, input().split())
print(sum(a, b))

