import sys

#returns a list of pairs of contestants, with each contestant being represented as the base of numbers that add up to it
def convert_to_base():
    contestants = []
    for line in sys.stdin:
        contestant_higher = []
        contestant_lower = []
        num1, num2 = line.split()

        contestant_higher.append(int(num1))
        contestant_lower.append(int(num2)
        while True:
            contestant_upper = []
            for i in range(101, 1):
                try:
                    for a in range contestant_higher:
                        contestant_upper.append(int(a/i))
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
                    for a in range contestant_lower:
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
    for i in range(len(a_list)):
        if a_list[i][0] == None:
            if a_list[i][1] == None:
                print('both cheated')
            else:
                print_winner(a_list[i][1])
        else:
            for a in a_list[i][0]:
                if a in a_list[i][1]:
                    print_winner(a_list[i][1])
                    break


def print_winner(a_list):
    number = 1
    for i in a_list:
        number = number * i
    print(number)

if __name__ == '__main__':
    a_list = convert_to_base()
    checker(a_list)
