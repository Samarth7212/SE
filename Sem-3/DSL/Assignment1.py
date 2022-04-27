"""
    Samarth Ramkrushna Kamble(21142)
    Assignment-1
    Data Structures Laboratory
"""

def check_duplicate(l1, i, tmp):
    #To check if the input given already exists in particular list, if yes re-input is taken
    if tmp in l1:
        print("Check entered Student name!")
        tmp = input("Enter the name of student {}:".format(i+1))
        l1.append(tmp)
    else:
        l1.append(tmp)


def union(ls1, ls2):
    #Union(List1,List2)
    union = []
    for i in ls1:
        if i not in union:
            union.append(i)
    for i in ls2:
        if i not in union:
            union.append(i)
    return union


def intersect(ls1, ls2):
    #Intersection(list1,list2)
    inter = []
    for i in ls1:
        if i in ls2:
            inter.append(i)
    return inter


def difference(ls1, ls2):
    # ls1-ls2
    diff = []
    for i in ls1:
        if i not in ls2:
            diff.append(i)
    return diff


def ans1(obj2, obj3):
    #Function for option-1
    print("List of students who play both cricket and badminton:")
    print(*intersect(obj2.game_list, obj3.game_list), sep="\n")


def ans2(obj2, obj3):
    #Function for option-2
    print("List of students who play either cricket OR badminton:")
    print(*list(difference(union(obj2.game_list, obj3.game_list),
          intersect(obj2.game_list, obj3.game_list))), sep="\n")


def ans3(obj1, obj2, obj3):
    #Function for option-3
    print("List of students who play neither cricket nor badminton: ")
    print(*list(difference(obj1.game_list,
          union(obj2.game_list, obj3.game_list))), sep="\n")


def ans4(obj3, obj2, obj4):
    #Function for option-4
    print("List of students who play cricket and football but not badminton")
    print(*list(difference(intersect(obj2.game_list,obj4.game_list),obj3.game_list)))


def restart():
    #Allows to continue the program with existing input OR close it.
    r = input("Do you want to continue (y/n): ")
    if r == 'y':
        choice(obj1, obj2, obj3, obj4)
    elif r == 'n':
        print("Thank you!")


def choice(obj1, obj2, obj3, obj4):
    #Menu function to run different options
    print(5*'*',"Menu",5*'*')
    print("Press 1 to to see list of students who play both cricket and badminton.")
    print("Press 2 to see list of students who play either cricket OR badminton.")
    print("Press 3 to see list of students who play neither cricket nor badminton.")
    print("Press 4 to see list of students who play cricket and football but not badminton.")
    ch = int(input("Enter your choice: "))
    print()
    #Functions will be called according to choice given.
    if(ch == 1):
        printall()
        print()
        ans1(obj2, obj3)
        restart()

    elif(ch == 2):
        printall()
        print()
        ans2(obj2, obj3)
        restart()

    elif(ch == 3):
        printall()
        print()
        ans3(obj1, obj2, obj3)
        restart()

    elif(ch == 4):
        printall()
        print()
        ans4(obj1, obj2, obj4)
        restart()
    else:
        print("Invalid choice!!!")
        restart()


class Game:
    def input_list(self):
        #Takes input
        self.length = int(input("Enter length of the list : "))
        for i in range(0, self.length):
            tmp = input("Enter the name of Student{}: ".format(i+1))
            check_duplicate(self.game_list, i, tmp)
            print()

    def __init__(self):
        #Initializes variables for objects
        self.game_list = []
        self.length = 0
        self.input_list()

def printall():
    #Function to print all values while analysing output.
    print("Superset: ",obj1.game_list)
    print("Cricket: ",obj2.game_list)
    print("Badminton: ",obj3.game_list)
    print("Football: ",obj4.game_list)


#Driver code:
print("Enter all the names of students ")
obj1 = Game()  # Superset
print(5*'*', "CRICKET", 5*'*')
obj2 = Game()  # cricket
print(5*'*', "BADMINTON", 5*'*')
obj3 = Game()  # badminton
print(5*'*', "FOOTBALL", 5*'*')
obj4 = Game()  # football

choice(obj1, obj2, obj3, obj4)
