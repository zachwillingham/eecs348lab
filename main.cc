/*
Zachary Willingham
zwillingham04@ku.edu
10/19/2023
Lab 6

You are tasked with implementing a C++ program that performs various operations on square matrices using functions and arrays (no classes or objects yet). Your program should read matrix data from a file, perform matrix operations, and output the results. The max size of the square matrices should be defined as a static constant 100 but the actual size of the square matrix will be the first line of data, and it will less than or equal to 100.
*/

#include <iostream>  // Input and output stream handling
#include <fstream>   // File stream handling
#include <vector>    // Vector container for arrays

// Defines a function that reads values from a file to return 2 equally sized square matrices
void readMatrix(const std::string& filename, std::vector<std::vector<int>>& matrix1, std::vector<std::vector<int>>& matrix2) {
    std::ifstream file(filename); // Opens the file 
    if (file.is_open()) {          // Makes sure the file is opened so there are no errors
        std::vector<std::vector<int>> matrix; // Creates temporary matrix to store values
        int value;
        while (file >> value) {   // Reads integers from the file
            std::vector<int> row; // Temporary vector to store values for a row
            row.push_back(value); // Adds the first value to the row
            for (int i = 1; i < 3; ++i) { // Reads the next two values
                file >> value;
                row.push_back(value); // Adds the values to the row
            }
            matrix.push_back(row); // Adds the row to the temporary matrix
        }

        int halfSize = matrix.size() / 2; // Determines where to split the big matrix into 2 square ones
        matrix1.assign(matrix.begin(), matrix.begin() + halfSize); // Assigns first half to matrix1
        matrix2.assign(matrix.begin() + halfSize, matrix.end());    // Assigns second half to matrix2

        file.close(); // Closes the file 
    } else {
        std::cerr << "Unable to open file." << std::endl; // Indicates an error if there was one
        exit(1); // Exits the program with an error code
    }
}

// Defines a function to print a matrix
void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) { // Iterates through each row in the matrix
        for (int value : row) {
            std::cout << value << " "; // Prints each value in the row followed by a space
        }
        std::cout << std::endl; // Shifts to a new line
    }
}

// Defines a function to add two matrices
std::vector<std::vector<int>> addMatrix(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2) {
    std::vector<std::vector<int>> result; // Creates an empty matrix that will hold the sum
    for (size_t i = 0; i < matrix1.size(); ++i) {
        std::vector<int> row; // Temporary vector to store values for a row to then be appended to the result matrix
        for (size_t j = 0; j < matrix1[i].size(); ++j) {
            row.push_back(matrix1[i][j] + matrix2[i][j]); // Adds corresponding values from matrix1 and matrix2
        }
        result.push_back(row); // Adds the row to the result matrix
    }
    return result; // Return the sum
}

// Defines a function to multiply two matrices
std::vector<std::vector<int>> multiplyMatrix(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2) {
    std::vector<std::vector<int>> result(matrix1.size(), std::vector<int>(matrix2[0].size(), 0)); // Result matrix whose initial values are 0
    for (size_t i = 0; i < matrix1.size(); ++i) {
        for (size_t j = 0; j < matrix2[0].size(); ++j) {
            for (size_t k = 0; k < matrix2.size(); ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j]; // Square multiplication requires the summation of the products of the row of matrix1 and the column of matrix2
            }
        }
    }
    return result; // Return the product
}

// Defines a function to subtract two matrices
std::vector<std::vector<int>> subtractMatrix(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2) {
    std::vector<std::vector<int>> result; // Result matrix to store the difference
    for (size_t i = 0; i < matrix1.size(); ++i) {
        std::vector<int> row; // Temporary vector to store values for a row in the result matrix
        for (size_t j = 0; j < matrix1[i].size(); ++j) {
            row.push_back(matrix1[i][j] - matrix2[i][j]); // Subtract corresponding values from matrix1 and matrix2
        }
        result.push_back(row); // Add the row to the result matrix
    }
    return result; // Return the diffrence
}

// Defines a main function where the execution begins. This will call all the functions I just defined
int main() {
    std::string filename; // Variable to store the inputted filename
    std::cout << "Enter a file: "; // Prompts the user for the filename
    std::cin >> filename; // Reads input from the user and store it in the filename variable

    std::vector<std::vector<int>> matrix1, matrix2; // Variables to store the input matrices
    readMatrix(filename, matrix1, matrix2); // Reads matrices from the file

    // Output the matrices and their operations
    std::cout << "Zach Willingham" << std::endl; 
    std::cout << "Lab #6: Matrix Manipulation" << std::endl;
    std::cout << std::endl;
    std::cout << "Matrix A:" << std::endl;
    printMatrix(matrix1); // Output matrix1
    std::cout << std::endl;
    std::cout << "Matrix B:" << std::endl;
    printMatrix(matrix2); // Output matrix2
    std::cout << std::endl;
    std::cout << "Matrix Sum (A + B):" << std::endl;
    printMatrix(addMatrix(matrix1, matrix2)); // Output the sum of matrices
    std::cout << std::endl;
    std::cout << "Matrix Product (A * B):" << std::endl;
    printMatrix(multiplyMatrix(matrix1, matrix2)); // Output the product of matrices
    std::cout << std::endl;
    printMatrix(subtractMatrix(matrix1, matrix2)); // Output the difference of matrices
    std::cout << std::endl;
    std::cout