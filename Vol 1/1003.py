#import sys
#from __future__ import print_function

#returns a list of pairs of contestants, with each contestant being represented as the base of numbers that add up to it
def convert_to_base(a_input):
    contestants = []
    for line in a_input:
        contestant_higher = []
        contestant_lower = []
        num1, num2 = line.split()

        contestant_higher.append(int(num1))
        contestant_lower.append(int(num2))
        while True:
            contestant_upper = []
            for i in range(101, 1):
                try:
                    for a in contestant_higher:
                        contestant_upper.append(int(a/i))a%i==0
                except:
                    pass

            if contestant_higher == contestant_upper:
                break
            else:
                contestant_higher = contestant_upper

        while True:
            contestant_lesser = []
            for i in range(101, 1):
                try:
                    for a in contestant_lower:
                        contestant_lesser.append(int(a/i))
                except:
                    pass

            if contestant_lower == contestant_lesser:
                break
            else:
                contestant_lower == contestant_lesser

        constants.append([contestant_lower, contestant_higher])
    return contestants

#This checks if anyone is lying
def checker(a_list):
    list_of_winners = []
    for i in range(len(a_list)):
        if a_list[i][0] == None:
            if a_list[i][1] == None:
                list_of_winners.append()
            else:
                list_of_winners.append(a_list[i][1])
            list_of_winners.append(list_of_winners)

        else:
            a = a_list[i][0]
            b = a_list[i][1]
            any_in = lambda a, b : bool(set(a).intersection(b))
            if any_in:
                list_of_winners.append(a_list[i][1])
            else:
                list_of_winners.append(a_list[i][0])
            list_of_winners.append(list_of_winners)

    return list_of_winners

# Prints winning number
def print_winner(a_list):
    number = 1
    for i in a_list:
        number = number * i
    print(number)

if __name__ == '__main__':
    # a_list = convert_to_base(sys.stdin)
    with open('test.txt', 'r') as read:
        a_list = convert_to_base(read)
    print('1')
    a_list = checker(a_list)
    print('2')
    print_winner(a_list)
    print('3')
