"""
    Samarth (21142 F1-batch)
    DSL Assignment-4
"""

# Write a Python program to store roll numbers of student in array who attended
# training program in random order. Write function for searching whether particular
# student attended training program or not, using Linear search and Sentinel search,
# Binary search and Fibonacci search


class Search_program:

    def print_list(self):
        print("\n---------------------------------------\nOriginal list: ",
              self.list_of_students)
        print("Sorted list: ",
              self.sorted_list, "\n---------------------------------------\n")

    def Srestart(self):
        ch = input("\nDo you want to continue with sorted order search?(y/n): ")
        if(ch == 'y'):
            self.sorted_search_menu()
        elif(ch == 'n'):
            self.list_of_students = []
            self.sorted_list = []
            tmp = input("Do you want to continue with main menu?(y/n): ")
            if(tmp == 'y'):
                self.menu()
            elif(tmp == 'n'):
                print("\nThank you!")

    def Rrestart(self):
        ch = input("\nDo you want to continue with random order search?(y/n): ")
        if(ch == 'y'):
            self.random_search_menu()
        elif(ch == 'n'):
            self.list_of_students = []
            self.sorted_list = []
            tmp = input("Do you want to continue with main menu?(y/n): ")
            if(tmp == 'y'):
                self.menu()
            elif(tmp == 'n'):
                print("\nThank you!")

    def __init__(self):
        """Constructor initializes empty lists"""
        self.list_of_students = []
        self.sorted_list = []
        self.menu()

    def linear_search(self, to_be_searched):
        """Iterates from start to end of list and checks whether the element exists OR not."""
        self.print_list()
        flag = False
        for i in range(len(self.list_of_students)):
            if(self.list_of_students[i] == to_be_searched):
                print(
                    "The roll number {} is present at index-{}".format(self.list_of_students[i], i))
                flag = True
        if(flag == False):
            print("The number {} is not present".format(to_be_searched))

    def sentinel_search(self, to_be_searched):

        self.print_list()
        size = len(self.list_of_students)
        last = size - 1

        last_elem = self.list_of_students[last]
        # Last element is maintained in last_elem variable

        self.list_of_students[last] = to_be_searched
        # Last element is replaced with element to be searched
        ind = 0

        while(self.list_of_students[ind] != to_be_searched):
            ind += 1

        self.list_of_students[last] = last_elem  # Element put back in place

        if((ind < size-1) or (self.list_of_students[size-1] == to_be_searched)):
            print("The number {} is present at index-{}.".format(to_be_searched, ind))
        else:
            print("The number {} is not present.".format(to_be_searched))

    def binary_search(self, to_be_searched):
        """Checks whether the number is present in list"""
        self.print_list()
        mid = 0
        hi = len(self.sorted_list) - 1
        lo = 0
        ans = -1
        while hi-lo > 1:
            mid = (int)((hi+lo)/2)
            if(to_be_searched > self.sorted_list[mid]):
                lo = mid+1
            elif(to_be_searched < self.sorted_list[mid]):
                hi = mid
            elif(self.sorted_list[mid] == to_be_searched):
                hi = mid
                break

        if(self.sorted_list[hi] == to_be_searched):
            ans = hi
            print("The number {} is present at index-{}.".format(to_be_searched, ans))
        elif(self.sorted_list[lo] == to_be_searched):
            ans = lo
            print("The number {} is present at index-{}.".format(to_be_searched, ans))
        elif(ans == -1):
            print("The number {} is not present.".format(to_be_searched))

    def fibonacci_search(self, to_be_searched):

        size = len(self.sorted_list)
        self.print_list()
        size = len(self.sorted_list)

        fib0 = 0
        fib1 = 1
        fibn = fib0 + fib1

        while (fibn < size):
            fib0 = fib1
            fib1 = fibn
            fibn = fib0 + fib1

        offset = -1

        while (fibn > 1):
            i = min(offset+fib0, size-1)

            #Move by one element left
            if (self.sorted_list[i] < to_be_searched):
                fibn = fib1
                fib1 = fib0
                fib0 = fibn - fib1
                offset = i

            #Move by two element left
            elif (self.sorted_list[i] > to_be_searched):
                fibn = fib0
                fib1 = fib1 - fib0
                fib0 = fibn - fib1

            else:
                return i

        if(fib1 and self.sorted_list[size-1] == to_be_searched):
            return size-1

        return -1

    def menu(self):
        """Takes input and checks whether to call random or sorted order search"""
        print("----------------------------------------------------------------\nMAIN MENU")
        print("Press 1 for Random order search")
        print("Press 2 for Sorted order search")
        print("Press -1 to exit")
        ch = int(input("Enter your choice: "))

        if ch == 1:
            self.random_order_search()

        elif ch == 2:
            self.sorted_order_search()

        elif ch == -1:
            print("Thank you!")

        else:
            print("Invalid choice!!!\nStart again\n")
            self.menu()

    def random_order_search(self):
        self.input_list()
        self.random_search_menu()

    def sorted_order_search(self):
        self.input_list()
        for elem in self.list_of_students:
            self.sorted_list.append(elem)
        self.sorted_list.sort()
        self.sorted_search_menu()

    def sorted_search_menu(self):
        print("----------------------------------------------------------------\nSORTED SEARCH MENU:")
        to_be_searched = int(input("Enter the roll number to be searched: "))
        print("\nPress 1 for binary search.")
        print("Press 2 for fibonacci search.")
        print("Press -1 to exit.")
        ch = int(input("Enter your choice: "))

        if ch == 1:
            self.binary_search(to_be_searched)
            self.Srestart()

        elif ch == 2:
            # print(self.fibonacci_search(to_be_searched))
            tmp = self.fibonacci_search(to_be_searched)
            if(tmp == -1):
                print("The element {} is not present.".format(to_be_searched))
            else:
                print(
                    "The element {} is present at index-{}.".format(to_be_searched, tmp))

            self.Srestart()

        elif ch == -1:
            print("Thank you!")

        else:
            print("Invalid choice!!!\nStart again\n")
            self.sorted_search_menu()

    def random_search_menu(self):
        print("----------------------------------------------------------------\nRANDOM SEARCH MENU:")
        to_be_searched = int(input("Enter the roll number to be searched: "))
        print("\nPress 1 for linear search.")
        print("Press 2 for sentinel search.")
        print("Press -1 to exit.")

        ch = int(input("Enter your choice: "))

        if ch == 1:
            self.linear_search(to_be_searched)
            self.Rrestart()

        elif ch == 2:
            self.sentinel_search(to_be_searched)
            self.Rrestart()

        elif ch == -1:
            print("Thank you!")

        else:
            print("Invalid choice!!!\nStart again\n")
            self.random_search_menu()

    def input_list(self):
        num = int(input("Enter the total number of students present: "))
        print("***Enter the roll numbers in random order***\n")
        for i in range(num):
            tmp = int(input("{}. Enter the present roll number: ".format(i+1)))
            repeat = tmp in self.list_of_students
            while(repeat):
                tmp = int(input("The number exists already!\nEnter again: "))
                repeat = tmp in self.list_of_students

            self.list_of_students.append(tmp)


obj = Search_program()
