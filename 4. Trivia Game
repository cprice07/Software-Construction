#define UNIT_TESTING
#include <cstddef>
#include <cassert>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*  File Name: project4_Price_czp0085.cpp
 *  Author: Corah Price
 *  Compile using g++ -std=c++11 project4_Price_czp0085.cpp - o Project4.out
 *   When wanting to run non debug code, simply //comment out the #define UNIT_TESTING portion
 *  Utilized Dr Li's walkthrough explanation in class of the code layout and formatting
 *  Utilized geeksforgeeks to learn about linked list data structure formatting
 *  Utilized programiz to learn about defining nodes
 *  Utilized codesdope.com to learn how to connect linked lists
 */

    //Define TriviaNode structure
    struct TriviaNode {
        string question;
        string answer;
        int points;
        TriviaNode* next;
    };


    //Define linked list of Trivia
    TriviaNode* triviaLinkedList() {
        TriviaNode* head = nullptr;

        TriviaNode* trivia1 = new TriviaNode;
        trivia1->question = "How long was the shortest war on record? (Hint: how many minutes)";
        trivia1->answer = "38";
        trivia1->points = 100;
        trivia1->next = nullptr;

        TriviaNode* trivia2 = new TriviaNode;
        trivia2->question = "What was Bank of America’s original name? (Hint: Bank of Italy or Bank of Germany)";
        trivia2->answer = "Bank of Italy";
        trivia2->points = 50;
        trivia2->next = nullptr;

        TriviaNode* trivia3 = new TriviaNode;
        trivia3->question = "What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)";
        trivia3->answer = "Wii Sports";
        trivia3->points = 20;
        trivia3->next = nullptr;

        head = trivia1;
        trivia1->next = trivia2;
        trivia2->next = trivia3;
        return head;
    }


    //Function implemented to ask questions and assign points
    int pointSystem(TriviaNode* head, int totalQuestions) {
        int pointsEarned = 0;
        TriviaNode* current = new TriviaNode;
        current->next = head;
        string inputAnswer;

        if (totalQuestions <= 0) {
            cout << "Warning - the number of trivia to be asked must be equal to or be larger than 1.";
            return 1;
        }
        else if (totalQuestions > 3) {
            cout << "\nWarning - There is only 3 trivia in the list.\n";
            return 1;
        }
        else {
            while (totalQuestions > 0 && current->next) {
                cout << endl;
                cout << "Question: " << current->next->question << endl;
                cout << "Answer: ";
                //cin.ignore();
                getline(cin, inputAnswer);

                //Used to see what input was being passed along
                //cout << "Entered Answer: " << inputAnswer << endl;
                //cout << "Correct Answer: " << current->next->answer << endl;

                if (inputAnswer == current->next->answer)  {
                    pointsEarned += current->next->points;
                    cout << "Your answer is correct. You receive " << current->next->points << " points." << endl;
                } else {
                    cout << "Your answer is wrong. The correct answer is " << current->next->answer << "\n";
                }

                cout << "Your total points: " << pointsEarned << endl;

                totalQuestions--;
                current->next = current->next->next;
            }
            return 0;
        }
    }

    void addQuestion(TriviaNode* &head, const string& question, const string& answer, int points) {
        TriviaNode* newNode = new TriviaNode;
        newNode->question = question;
        newNode->answer = answer;
        newNode->points = points;
        newNode->next = nullptr;

        if (!head) {
            head = newNode;
        } else {
            TriviaNode* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }

    }

    #ifdef UNIT_TESTING
    //Unit test for pointSystem
    int main() {
            TriviaNode *test = triviaLinkedList();
            int pointsEarned;

            cout << "***This is the debugging version ***\n";
            //Case 1: ask 0 questions
            cout << "Unit Test Case 1: Ask no question. The program should give a warning message.\n";
            pointsEarned = pointSystem(test, 0);
            assert(pointsEarned == 1);
            cout << "\nCase 1 Passed" << endl;

            //Case 2: ask 1 question, right answer
            cout << "\nUnit Test Case 2.1: Ask 1 question in the linked list. The tester enters an incorrect answer.";
            pointsEarned = pointSystem(test, 1);
            cout << "\nCase 2.1 Passed" << endl;

            //Case 2: ask 1 question, wrong answer
            cout << "\nUnit Test Case 2.2: Ask 1 question in the linked list. The tester enters a correct answer.";
            pointsEarned = pointSystem(test, 1);
            assert(pointsEarned == 0);
            cout << "\nCase 2.2 Passed" << endl;

            //Case 3: ask 3 questions, assuming two correct answers
            cout << "\nUnit Test Case 3: Ask all the questions of the last trivia in the linked list.";
            pointsEarned = pointSystem(test, 3);
            cout << "\nCase 3 Passed" << endl;

            //Case 4: ask 5 questions
            cout
                    << "\nUnit Test Case 4: Ask 5 questions that exceed the number of available trivia in the linked list.";
            pointsEarned = pointSystem(test, 5);
            assert(pointsEarned == 1);
            cout << "\nCase 4 Passed" << endl;

            cout << "\n*** End of the Debugging Version ***";

    }

    #else
    int main() {
        cout << "*** Welcome to Corah's trivia quiz game ***\n";

        TriviaNode *list = triviaLinkedList();
        string userInput;
        string question;
        string answer;
        int points;

        do {
            cout << "Enter a question: " ;
            cin.ignore();
            getline(cin, question);

            cout << "Enter an answer: ";
            getline(cin, answer);

            cout << "Enter award points: ";
            cin >> points;
            cin.ignore();

            addQuestion(list, question, answer, points);

            cout << "Continue? (Yes/No) : ";
            cin >> userInput;
            cin.ignore();

          //Accept Yes or yes for input
        } while (userInput == "Yes" || userInput == "yes");

        int pointsEarned = pointSystem(list, 3);

        cout << "\n*** Thank you for playing the trivia quiz game. Goodbye! ***";

        return 0;
    }
    #endif

