#import sys
#from __future__ import print_function

#returns a list of pairs of contestants, with each contestant being represented as the base of numbers that add up to it
def checker(high, low, number):
    for i in range(number, 0, -1):
        # Check if lower number is able to be divided by the number
        elif low % i == 0:
            if checker(high, low/i, i):
                return low
        # Check if higher number is able to be divided by the number
        elif high % i == 0:
            if checker(high/i, low, i):
                return high
        else:
            pass

        if low == 1:
            return True
        if high == 1:
            print

if __name__ == '__main__':
    for line in sys.stdin:
        a, b = line.split()
        if a > b:
            a = high
            b = low
        else:
            b = high
            a = low
        checker(high, low, 100)
