"""
    Samarth Ramkrushna Kamble(21142)
    Assignment-2
    Data Structures Laboratory
"""

# Write a Python program to compute following operations on String:
# a) To display word with the longest length
# b) To determine the frequency of occurrence of particular character in the string
# c) whether given string is palindrTo check ome or not
# d) To display index of first appearance of the substring
# e) To count the occurrences of a word in a given string

class Str_operations:
    
    def printall(self):
        """To print given string for analysing output"""
        print("Given string: ",self.str)

    def restart(self):
        """Asks user whether to continue OR exit the program"""
        tmp = input("\nDo you want to continue? (y/n): ")
        if(tmp == 'y'):
            self.menu()
        else:
            print("Thank You!")
    
    def menu(self):
        """Menu function shows a menu and takes choice as an input"""
        print()
        self.printall()
        print("\n", 5*'*', "MENU", 5*'*')
        print("Press 1 to display word with the longest length")
        print("Press 2 to diplay the frequency of particular character in the string")
        print("Press 3 to check whether given string is palindrome or not")
        print("Press 4 to display index of first appearance of the substring")
        print("Press 5 to count the occurrences of each word in a given string")

        try:
            ch = int(input("\nEnter your choice: "))
        except ValueError:
            print("Invalid input!")
            ch = int(input("\nEnter your choice: "))

        if ch == 1:
            self.ans1()
            self.restart()

        elif ch == 2:
            self.ans2()
            self.restart()

        elif ch == 3:
            self.ans3()
            self.restart()

        elif ch == 4:
            self.ans4()
            self.restart()

        elif ch == 5:
            self.ans5()
            self.restart()

        else:
            print("\nInvalid choice detected!!!")
            print("...Restarting\n")
            self.menu()

    def ans1(self):
        """
        Displays word with longest length.
        Makes list of words in given string and finds word with maximum length
        """
        li=[]
        tmp=''
        for char in self.str:
            if char==' ':
                li.append(tmp)
                tmp=''
            else:
                tmp+=char
        
        max = -1
        ans = ""
        for ele in li:
            if len(ele)>max:
                ans=ele
                max=len(ele)
        print("{} is the word with longest length.".format(ans))

    def ans2(self):
        """Finds frequency of entered character in given string"""
        c = input("Enter the character: ")
        ct = 0
        for i in range(len(self.str)):
            if self.str[i] == c:
                ct += 1
        print("The character {} is present {} times.".format(c, ct))

    def ans3(self):
        """Checks whether the string is palindrome OR not"""
        if self.str == self.str[::-1]:
            print("The given string is a palindrome.")
        else:
            print("The given string is not a palindrome.")

    def ans4(self):
        """Displays the index of first appearance of entered substring"""
        sub = input("Enter the substring: ")

        def Ind(s, sub):
            st = 0
            end = 0
            while st < len(s):
                if s[st+end] != sub[end]:
                    st += 1
                    end = 0
                    continue
                end += 1
                if end == len(sub):
                    return st
            return -1

        print("The index is {}".format(Ind(self.str, sub)))

    def ans5(self):
        """Finds frequency of entered substring in given string"""
        word = input("Enter the word: ")
        count=0
        l2=len(word)
        #self.str= Hi my my my name is 
        for i in range(len(self.str)):
            if self.str[i] == word[0]:
                end = i+l2
                sub1 = self.str[i:end]
                if word == sub1:
                    count += 1
        print("The occurrence of {} in string is {} times".format(word ,count))

    def inputstr(self):
        """Takes input of the string"""
        self.str = input("Enter the string: ")
        self.menu()

    def __init__(self):
        """Constructor initializes string"""
        self.str = ""
        try:
            self.inputstr()
        except ValueError:
            print("Invalid input!")
            self.inputstr()

#Object of class is created
obj1 = Str_operations()


