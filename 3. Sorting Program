#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

/*  File Name: project3_Price_czp0085.cpp
 *  Author: Corah Price
 *  Compile using g++ project3_Price_czp0085.cpp - o Project3.out
 *  Utilized Dr Li's walkthrough explanation in class of the code layout and formatting
 *  Utilized cplusplus.com to help with stream formatting
 *  Utilized geeksforgeeks to learn about pop_back and push_back formatting
 *  Utilized stack overflow to learn difference in ofstream and ifstream
 */


//Ensures file can be found
bool check_file(string& fileName) {
    ifstream inStream;
    // Pass the file name as an array of chars to open()
    // inStream.open(filename);
    inStream.open((char*)fileName.c_str());
    if (!inStream) {
        //Print error if file unable to be found
        cout << "Error: unable to open file." << endl;
        inStream.close();
        return false;
    }
    inStream.close();
    return true;
}

//Read file into vector form
vector<int> read_file(const string& fileName) {
    int i;
    ifstream inStream;
    vector<int> number1;
    inStream.open((char*)fileName.c_str());

    while(inStream.good()) {
        inStream >> i;
        //Push_back places new elements at the end of the vector
        number1.push_back(i);
    }
    //Pop_back removes an element from the end of the vector
    number1.pop_back();
    inStream.close();
    return number1;
}

void write_file(string& fileName3, vector<int> vec3) {
    int i;

    ofstream outStream;
    outStream.open((char*)fileName3.c_str());
    for(i = 0; i < vec3.size(); i++){
        outStream << vec3.at(i) << "\n";
    }
    outStream.close();
}

vector<int> merge(vector<int> vec1, vector<int> vec2) {
    vector<int> vec3;
    int i;

    //Compare vectors
    while(!vec1.empty() && !vec2.empty()) {
        if (vec1.at(0) < vec2.at(0)) {
            vec3.push_back(vec1.at(0));
            vec1.erase(vec1.begin());
        } else {
            vec3.push_back(vec2.at(0));
            vec2.erase(vec2.begin());
        }
    }
    if (!vec1.empty()) {
        for (i = 0; i < vec1.size(); i++) {
            vec3.push_back(vec1.at(i));
        }
        vec1.erase(vec1.begin());
    }
    if (!vec2.empty()) {
        for (i = 0; i < vec2.size(); i++) {
            vec3.push_back(vec2.at(i));
        }
        vec2.erase(vec2.begin());
    }
    return vec3;
}

int main(){
    //declare variables
    string file1;
    string file2;
    string fileName3;
    vector<int> num1;
    vector<int> num2;
    vector<int> num3;

    cout << "*** Welcome to Corah's sorting program ***" << endl;

    //Get file1 values
    do {
        //Ask user input
        cout << "Enter the first input file name: ";
        //Accept input file
        cin >> file1;
        //Print error for invalid input
        if (cin.fail() || !check_file(file1)) {
            cout << "Error: unable to retrieve file." << endl;
            cin.clear();
        }
    } while(cin.fail() || !check_file(file1));

    //Values from file1
    num1 = read_file(file1);
    cout << "The list of " << num1.size() << " numbers in file " << file1 << " is:" << endl;
    for (size_t i = 0; i < num1.size(); i++) {
        cout << num1[i] << endl;
    }

    //Get file2 values
    do {
        //Ask user input
        cout << "\nEnter the second input file name: ";
        //Accept input file
        cin >> file2;

        //Print error for invalid input
        if (cin.fail() || !check_file(file2)) {
            cout << "Error: unable to retrieve file." << endl;
            cin.clear();
        }
    } while(cin.fail() || !check_file(file2));

    //Values from file2
    num2 = read_file(file2);
    cout << "The list of " << num2.size() << " numbers in file " << file2 << " is:" << endl;
    for (size_t i = 0; i < num2.size(); i++) {
        cout << num1[i] << endl;
    }
    //Merge values
    num3 = merge(num1, num2);

    cout << "\nThe sorted list of " << num3.size() << " numbers is:";
    for (size_t i = 0; i < num3.size(); i++) {
        cout << " " << num3[i];
    }

    //Get user file3 name
    do {
        cout << "\nEnter the output file name: ";
        cin >> fileName3;
    } while(cin.fail());

    //Write to file3
    write_file(fileName3, num3);

    cout << "*** Please check the new file - " << fileName3 << " ***" << endl;
    cout << "*** Goodbye. ***" << endl;

    return 0;
}


