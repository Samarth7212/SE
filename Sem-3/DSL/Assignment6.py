"""
    Samarth (21142 F1-batch)
    DSL Assignment-6
"""

# Problem Statement:
# Write  a  Python  program  to  store  second  year  percentage  of  students  in  list.  Write
# function for sorting self.liStd of floating point numbers in ascending order using QuickSort.


class MarksOfStudents:

    def restart(self):
        ch = input("Do you want to continue?(y/n)?")
        if(ch == 'y'):
            self.passes = 0
            self.liStd = []
            self.takeInput()
        else:
            print("Thank you!")

    def printL(self, n):
        print("Sorted list: ", self.liStd)
        print("Total number of swaps: ", self.passes)
        topFive = [self.liStd[i] for i in range(n-1, n-6, -1)]
        print("\nTo five student's percentage are: ")
        for i in range(5):
            print("{}. {}".format(i+1, topFive[i]))

    def takeInput(self):
        n = int(input("\nEnter the number of students: "))

        while(n <= 5):
            print("Atleast 6 students should be there!!!")
            n = int(input("Enter again: "))

        for i in range(n):
            tmp = float(input("Enter percentage of Student-{}: ".format(i+1)))
            while(tmp > 100 or tmp < 0):
                print("Invalid marks!!!")
                tmp = float(
                    input("Enter percentage of Student-{}: ".format(i+1)))
            self.liStd.append(tmp)

        print(138*'_')
        self.quickSort(0, n-1)
        print(138*'_')
        self.printL(n)
        self.restart()

    def __init__(self):
        self.passes = 0
        self.liStd = []
        self.takeInput()

    def swap(self, a, b):
        self.passes = self.passes+1
        self.liStd[a], self.liStd[b] = self.liStd[b], self.liStd[a]
        print("Current list: ", self.liStd, "\n")

    def partition(self, st, end):
        pivInd = st
        pivot = self.liStd[pivInd]
        print("Pivot is: ", self.liStd[pivInd])

        while st < end:

            while st < len(self.liStd) and self.liStd[st] <= pivot:
                st += 1

            while self.liStd[end] > pivot:
                end -= 1

            if(st < end):
                self.swap(st, end)

        self.swap(end, pivInd)
        return end

    def quickSort(self, st, end):

        if(st < end):
            loc = self.partition(st, end)
            self.quickSort(st, loc-1)
            self.quickSort(loc+1, end)


obj = MarksOfStudents()
