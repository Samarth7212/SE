"""
    Samarth Kamble (21142 F1-batch)
    DSL Assignment-3
"""

"""
Write a Python program to compute following computation on matrix:
a) Addition of two matrices 
B) Subtraction of two matrices
c) Multiplication of two matrices 
d) Transpose of a matrix
"""


class Matrix_operations:

    def restart(self):
        ch = input("Do you want to continue(y/n)? ")
        if ch == 'y':
            self.menu()
        else:
            print("Thank you!")

    def print_matrix(self, result):
        print("\nThe result is: ")
        for elem in result:
            print("\t\t|", *elem, "|", sep=" ")
            # print("\t\t[", *elem, "]", sep=" ")
        print("The size of matrix is ({}x{})".format(
            len(result), len(result[0])))

    def print_matrices(self):
        print("Matrix-1:")
        for elem in self.matrix1:
            print("\t\t|", *elem, "|", sep=" ")

        print("\nMatrix-2:")
        for elem in self.matrix2:
            print("\t\t|", *elem, "|", sep=" ")

    def menu(self):
        print("\nMAIN MENU")
        print("Press 1 for addition")
        print("Press 2 for subtraction")
        print("Press 3 for multiplication")
        print("Press 4 for transpose\n")
        ch = int(input("Enter your choice: "))
        print()

        if ch == 1:
            self.addition()
            self.restart()
        elif ch == 2:
            self.subtraction()
            self.restart()
        elif ch == 3:
            self.multiplication()
            self.restart()
        elif ch == 4:
            self.transpose()
            self.restart()
        else:
            print("Invalid choice!\n...Restarting")
            self.restart()

    def addition(self):
        self.print_matrices()
        result = []
        if(self.row1 == self.row2 and self.col1 == self.col2):
            row_count = self.row1
            col_count = self.col1
            for row in range(row_count):
                tmp_row = []
                for i in range(col_count):
                    tmp_row.append(self.matrix1[row][i]+self.matrix2[row][i])
                result.append(tmp_row)
            self.print_matrix(result)
        else:
            print("Addition cannot be performed!!!")

    def subtraction(self):
        self.print_matrices()
        result = []
        if(self.row1 == self.row2 and self.col1 == self.col2):
            row_count = self.row1
            col_count = self.col1
            for row in range(row_count):
                tmp_row = []
                for i in range(col_count):
                    tmp_row.append(self.matrix1[row][i]-self.matrix2[row][i])
                result.append(tmp_row)
            self.print_matrix(result)
        else:
            print("Multiplication cannot be performed!!!")

    def multiplication(self):
        self.print_matrices()
        row_count = self.row1
        col_count = self.col2
        com_count = self.col1

        if(self.col1 == self.row2):
            result = []
            for i in range(row_count):
                tmp_row = []
                for j in range(col_count):
                    s = 0
                    for k in range(com_count):
                        s += (self.matrix1[i][k])*(self.matrix2[k][j])
                    tmp_row.append(s)
                result.append(tmp_row)
            self.print_matrix(result)

        else:
            print("Multiplication can't be performed!!!")

    def transpose(self):
        """
            matrix=[[1,2],[3,4]]
            trans=[[1,3],[2,4]]
        """
        self.print_matrices()

        def determine_transpose(row_count, col_count, matrix):
            result = []
            for i in range(col_count):
                tmp_row = []
                for j in range(row_count):
                    tmp_row.append(matrix[j][i])
                result.append(tmp_row)
            self.print_matrix(result)
            print()

        determine_transpose(self.row1, self.col1, self.matrix1)
        determine_transpose(self.row2, self.col2, self.matrix2)

    def input_matrix(self):
        """i*j j*k row*column"""
        print("\nMatrix-1")
        for i in range(self.row1):
            tmp_row = []
            for j in range(self.col1):
                tmp_row.append(
                    int(input("Enter element({},{}): ".format(i+1, j+1))))
            self.matrix1.append(tmp_row)

        print("\nMatrix-2")
        for i in range(self.row2):
            tmp_row = []
            for j in range(self.col2):
                tmp_row.append(
                    int(input("Enter element({},{}): ".format(i+1, j+1))))
            self.matrix2.append(tmp_row)

        self.menu()

    def input_size(self):

        print("\nMatrix-1")
        self.row1 = int(input("Enter number of rows: "))
        self.col1 = int(input("Enter number of columns: "))

        print("\nMatrix-2")
        self.row2 = int(input("Enter number of rows: "))
        self.col2 = int(input("Enter number of columns: "))
        self.input_matrix()

    def __init__(self):
        """[row1,row2,row3,...]"""
        self.matrix1 = []
        self.matrix2 = []
        self.row1 = 0
        self.row2 = 0
        self.col1 = 0
        self.col2 = 0
        self.input_size()


obj1 = Matrix_operations()
