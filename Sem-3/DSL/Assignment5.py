"""
    Samarth (21142 F1-batch)
    DSL Assignment-5
"""

# Problem Statement:
# Write  a  Python  program  to  store  second  year  percentage  of  students  in  array.  Write
# function for sorting array of floating point numbers in ascending order using
# a) Insertion sort
# b) Shell Sort and display top five scores.


class MarksOfStudents:

    def restart(self, n):
        ch = input("Do you want to continue?(y/n): ")
        if(ch == 'y'):
            self.sortedListOfStudents = []
            self.menu(n)

        elif (ch == 'n'):
            ch2 = input("Do you want to restart?(y/n): ")

            if(ch2 == 'y'):
                self.listOfStudents = []
                self.sortedListOfStudents = []
                self.takeInput()

            elif (ch2 == 'n'):
                print("Thank you!!!")

    def copyList(self):
        self.sortedListOfStudents = []
        for i in self.listOfStudents:
            self.sortedListOfStudents.append((i))

    def printList(self, n):
        print(138*"_", "\nOriginal list: ", self.listOfStudents)
        print("Sorted list: ", self.sortedListOfStudents)
        print(138*"_")
        topFive = [self.sortedListOfStudents[i] for i in range(n-1, n-6, -1)]
        print("\nTo five student's percentage are: ")
        for i in range(5):
            print("{}. {}".format(i+1, topFive[i]))
        print("Count: ", self.ct)

    def insertionSort(self, n):
        self.copyList()
        for i in range(1, n):
            j = i-1
            key = self.sortedListOfStudents[i]

            while (j >= 0 and key < self.sortedListOfStudents[j]):
                self.sortedListOfStudents[j+1] = self.sortedListOfStudents[j]
                j = j-1

            self.sortedListOfStudents[j+1] = key
            self.fun()
        self.printList(n)

    def swap(self, a, b):
        self.ct = self.ct+1
        tmp = self.sortedListOfStudents[a]
        self.sortedListOfStudents[a] = self.sortedListOfStudents[b]
        self.sortedListOfStudents[b] = tmp
        
    def fun(self):
        print("Current list: ")
        print(self.sortedListOfStudents)

    def shellSort(self, n):
        """A=[77,62,10,9,30,22,80,25,70,56]"""
        self.copyList()

        gap = n//2
        while(gap != 0):
            for j in range(gap, n):
                for i in range(j-gap, -1, -gap):
                    if(self.sortedListOfStudents[i+gap] > self.sortedListOfStudents[i]):
                        break
                    else:
                        self.swap(i+gap, i)
                        self.fun()
            gap //= 2

        self.printList(n)

    def menu(self, n):
        print("\nMAIN MENU")
        print("1.Inserion Sort\n2.Shell Sort")
        ch = int(input("Enter your choice: "))
        if(ch == 1):
            self.insertionSort(n)
            self.restart(n)
        elif(ch == 2):
            self.shellSort(n)
            self.restart(n)
        else:
            print("Invalid choice!!!")
            self.restart(n)

    def takeInput(self):
        n = int(input("\nEnter the number of students: "))

        while(n <= 5):
            print("Atleast 6 students should be there!!!")
            n = int(input("Enter again: "))

        for i in range(n):
            tmp = float(input("Enter percentage of Student-{}: ".format(i+1)))
            while(tmp > 100):
                print("Invalid marks!!!")
                tmp = float(
                    input("Enter percentage of Student-{}: ".format(i+1)))
            self.listOfStudents.append(tmp)

        self.menu(n)

    def __init__(self):
        self.ct = 0
        self.listOfStudents = []
        self.sortedListOfStudents = []
        self.takeInput()


obj = MarksOfStudents()
