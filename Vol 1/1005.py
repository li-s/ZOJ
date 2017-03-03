import sys

def pour(ca, cb, n):
    a = 0
    b = cb
    print 'fill B'
    while b != n:
        print 'pour B A'
        if ca - a < b:
            print 'empty A'
            b = b - ca + a
            a = 0
        else:
            print 'fill B'
            a = a+b
            b = cb
    print 'success'
    return

line = sys.stdin.readline()
while line:
    data = line.split()
    ca = int(data[0])
    cb = int(data[1])
    n = int (data[2])
    pour(ca, cb, n)
    line = sys.stdin.readline()
