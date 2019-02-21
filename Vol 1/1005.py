import sys

def pourba(ca, cb, n):
    a = 0
    b = cb
    print 'fill B'
    while b != n:
        print 'pour B A'
        if (ca - a) < b:
            print 'empty A'
            b = b - ca + a
            a = 0
        else:
            print 'fill B'
            a = a+b
            b = cb
    print 'success'
    return

def pourab(ca, cb, n):
    a = ca
    b = 0
    print "fill A"
    while a != n:
        print "pour A B"
        if (cb - b) < a:
            print "empty B"
            a = a - cb + b
            b = 0
        else:
            print "fill A"
            b = b + a
            a = ca
    print "success"
    return

line = sys.stdin.readline()
while line:
    data = line.split()
    ca = int(data[0])
    cb = int(data[1])
    n = int (data[2])

    if (n % 2) == 0:
        pourba(ca, cb, n)

    else:
        pourab(ca, cb, n)

    line = sys.stdin.readline()
