import sys

def checker(high, low, number):
    for i in range(number, 1, -1):
        if low % i == 0:
            if checker(high, low/i, i-1):
                return True
        if high % i == 0:
            if checker(high/i, low, i-1):
                return True

    global flag
    if low == 1:
        flag = True
    elif not flag:
        return True
    if high == 1 and low ==1:
        return True
    return False

line = sys.stdin.readline()
while line:
    scores = line.split()
    high = int(scores[0])
    low = int(scores[1])
    if low > high:
        tep = low
        low = high
        high = tep
    flag = False
    winner = high
    if not checker(high, low, 100):
        winner = low
    print (winner)
line = sys.stdin.readline()
