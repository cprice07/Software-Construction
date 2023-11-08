#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <assert.h>
#include <ctime>
using namespace std;

/*  File Name: project2_Price_czp0085.cpp
 *  Author: Corah Price
 *  Compile using g++ project2_Price_czp0085.cpp - o Project2.out
 * Utilized University provided tutoring for modulus help
 * Utilized source code layout and hints provided in project 2 pdf by Dr Li
 * Utilized University provided tutoring to assist with setting up test cases
 * Utilized w3schools to learn how to convert integer to a percentage
 */

//Function Prototypes

    bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);
    void Aaron_shoots1(bool& B_alive, bool& C_alive);
    void Aaron_shoots2(bool& B_alive, bool& C_alive);
    void Bob_shoots(bool& A_alive, bool& C_alive);
    void Charlie_shoots(bool& A_alive, bool& B_alive);

    //Test Driver Prototypes
    void test_at_least_two_alive();
    void test_Aaron_shoots1();
    void test_Bob_shoots();
    void test_Charlie_shoots();
    void test_Aaron_shoots2();

    //Variable initialization
    const int A_accuracy = 33;
    const int B_accuracy = 50;
    const int total_runs = 10000;
    int Aaron_wins = 0;
    int Bob_wins = 0;
    int Charlie_wins = 0;
    int Aaron2_wins = 0;



    //Aaron's probability = 1/3 or 33
    void Aaron_shoots1(bool& B_alive, bool& C_alive) {
        assert(B_alive || C_alive);
        //Random number between 0 and 99
        int num = rand() % 100;

        if (num < A_accuracy) {
            //Charlie shot
            if (C_alive) {
                C_alive = false;
                //Bob shot
            } else {
                B_alive = false;
            }
            //Missed shot
        } else {
        }
    }


    //Aaron intentionally misses first shot. Miss probability = 1/3. Hit probability = 2/3.
    void Aaron_shoots2(bool& B_alive, bool& C_alive) {
        assert(B_alive || C_alive);

        //Intentional miss
        if (B_alive && C_alive) {
            return;
        }
        //Random number between 0 and 99
        int num = rand() % 100;

        if (num < A_accuracy) {
            //Charlie shot
            if (C_alive) {
                C_alive = false;
                //Bob shot
            } else {
                B_alive = false;
            }
            //Missed shot
        } else {
        }
    }

    //Bob's probability = 1/2
    void Bob_shoots(bool& A_alive, bool& C_alive) {
        assert(A_alive || C_alive);

        //Random number between 0 and 99
        int num = rand() % 100;

        if (num < B_accuracy) {
            //Charlie shot
            if (C_alive) {
                C_alive = false;
                //Aaron shot
            } else {
                A_alive = false;
            }
            //Missed shot
        } else {
        }
    }

    //Charlie's probability = 1/1
    void Charlie_shoots(bool& A_alive, bool& B_alive) {
        assert(A_alive || B_alive);
        //Charlie will shoot at Bob first if still alive
        if(B_alive){
            B_alive = false;
        }
        else{
            A_alive = false;
        }
    }

    //Returns true when two are left alive
   bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
    if ((A_alive && B_alive) || (A_alive && C_alive) || (B_alive && C_alive)) {
        return true;
    }
    else {
        return false;
        }
    }

    //Pause function
    void Press_any_key() {
    cout <<"Press any key to continue...";
    cin.ignore().get();
}



    int main() {

        //Initialize random number generator
        cout <<"*** Welcome to Corah's Duel Simulator ***\n";
        srand(time(0));

        //Test functions
        test_at_least_two_alive();
        Press_any_key();
        test_Aaron_shoots1();
        Press_any_key();
        test_Bob_shoots();
        Press_any_key();
        test_Charlie_shoots();
        Press_any_key();
        test_Aaron_shoots2();
        Press_any_key();

        //Strategy 1
        cout << "Ready to test strategy 1 (run 10000 times):\n";
        Press_any_key();
        for (int i = 0; i < total_runs; i++) {
            //Declare variable
            bool A_alive = true;
            bool B_alive = true;
            bool C_alive = true;

            while (at_least_two_alive(A_alive, B_alive, C_alive)) {
                if (A_alive && at_least_two_alive(A_alive, B_alive, C_alive)) {
                    Aaron_shoots1(B_alive, C_alive);
                }
                if (B_alive) {
                    Bob_shoots(A_alive, C_alive);
                }
                if (C_alive) {
                    Charlie_shoots(A_alive, B_alive);
                }
            }
            //Count winner
            if(A_alive) {
                Aaron_wins++;
            } else if (B_alive) {
                Bob_wins++;
            } else {
                Charlie_wins++;
            }
        }

        // Strategy 1 tally
        cout << "Aaron won " << Aaron_wins << "/10000 duels or "
             << static_cast<double>(Aaron_wins) / 100 << "%\n";
        cout << "Bob won " << Bob_wins << "/10000 duels or "
             << static_cast<double>(Bob_wins) / 100 << "%\n";
        cout << "Charlie won " << Charlie_wins << "/10000 duels or "
             << static_cast<double>(Charlie_wins) / 100 << "%\n";

        //Strategy 2
        cout << "\nReady to test strategy 2 (run 10000 times):\n";
        Press_any_key();
        for (int i = 0; i < total_runs; i++) {
            bool A_alive = true;
            bool B_alive = true;
            bool C_alive = true;

            while (at_least_two_alive(A_alive, B_alive, C_alive)) {
                if (A_alive) {
                    Aaron_shoots2(B_alive, C_alive);
                }
                if (B_alive) {
                    Bob_shoots(A_alive, C_alive);
                }
                if (C_alive) {
                    Charlie_shoots(A_alive, B_alive);
                }
            }
            //Count winner
            if(A_alive) {
                Aaron2_wins++;
            } else if (B_alive) {
                Bob_wins++;
            } else {
                Charlie_wins++;
            }
        }

        // Strategy 2 tally
        cout << "Aaron won " << Aaron2_wins << "/10000 duels or " << static_cast<double>(Aaron2_wins) / 100 << "%\n";
        cout << "Bob won " << Bob_wins << "/10000 duels or " << static_cast<double>(Bob_wins) / 100 << "%\n";
        cout << "Charlie won " << Charlie_wins << "/10000 duels or " << static_cast<double>(Charlie_wins) / 100 << "%\n";

        if(Aaron2_wins > Aaron_wins) {
            cout << "\nStrategy 2 is better than strategy 1.\n";
        } else {
            cout << "\nStrategy 1 is better than strategy 2. \n";
        }

        return 0;
    }

    void test_at_least_two_alive(void) {
        cout << "Unit Testing 1: Function - at_least_two_alive() \n";

        cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
        assert(true == at_least_two_alive(true, true, true));
        cout << "\tCase passed ...\n";

        cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
        assert(true == at_least_two_alive(false, true, true));
        cout << "\tCase passed ...\n";

        cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
        assert(true == at_least_two_alive(true, false, true));
        cout << "\tCase passed ...\n";

        cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
        assert(true == at_least_two_alive(true, true, false));
        cout << "\tCase passed ...\n";

        cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
        assert(false == at_least_two_alive(false, false, true));
        cout << "\tCase passed ...\n";

        cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
        assert(false == at_least_two_alive(false, true, false));
        cout << "\tCase passed ...\n";

        cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
        assert(false == at_least_two_alive(true, false, false));
        cout << "\tCase passed ...\n";

        cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
        assert(false == at_least_two_alive(false, false, false));
        cout << "\tCase passed ...\n";

    }

    void test_Aaron_shoots1(){
        cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";

        //Case 1
        {
            //Reset values
            bool B_alive = true;
            bool C_alive = true;
            assert(B_alive || C_alive);
            Aaron_shoots1(B_alive, C_alive);
            cout << "\tCase 1: Bob alive, Charlie alive\n"
                 << "\t\tAaron is shooting at Charlie\n";
        }

        //Case 2
        {
            //Reset values
            bool B_alive = false;
            bool C_alive = true;
            assert(B_alive || C_alive);
            Aaron_shoots1(B_alive, C_alive);
            cout << "\tCase 2: Bob dead, Charlie alive\n"
                 << "\t\tAaron is shooting at Charlie\n";
        }

        //Case 3
        {
            //Reset values
            bool B_alive = true;
            bool C_alive = false;
            assert(B_alive || C_alive);
            Aaron_shoots1(B_alive, C_alive);
            cout << "\tCase 3: Bob alive, Charlie dead\n"
                 << "\t\tAaron is shooting at Bob\n";
        }
    }

    void test_Bob_shoots(){
        cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n";

        //Case 1
        {
            //Reset values
            bool A_alive = true;
            bool C_alive = true;
            assert(A_alive || C_alive);
            Bob_shoots(A_alive, C_alive);
            cout << "\tCase 1: Aaron alive, Charlie alive\n"
                 << "\t\tBob is shooting at Charlie\n";
        }

        //Case 2
        {
            //Reset values
            bool A_alive = false;
            bool C_alive = true;
            assert(A_alive || C_alive);
            Bob_shoots(A_alive, C_alive);
            cout << "\tCase 2: Aaron dead, Charlie alive\n"
                 << "\t\tBob is shooting at Charlie\n";
        }

        //Case 3
        {
            //Reset values
            bool A_alive = true;
            bool C_alive = false;
            assert(A_alive || C_alive);
            Bob_shoots(A_alive, C_alive);
            cout << "\tCase 3: Aaron alive, Charlie dead\n"
                 << "\t\tBob is shooting at Aaron\n";
        }
    }

    void test_Charlie_shoots(){
        cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n";

        //Case 1
        {
            //Reset values
            bool A_alive = true;
            bool B_alive = true;
            assert(A_alive || B_alive);
            Charlie_shoots(A_alive, B_alive);
            cout << "\tCase 1: Aaron alive, Bob alive\n"
                 << "\t\tCharlie is shooting at Bob\n";
        }

        //Case 1
        {
            //Reset values
            bool A_alive = false;
            bool B_alive = true;
            assert(A_alive || B_alive);
            Charlie_shoots(A_alive, B_alive);
            cout << "\tCase 2: Aaron dead, Bob alive\n"
                 << "\t\tCharlie is shooting at Bob\n";
        }

        //Case 1
        {
            //Reset values
            bool A_alive = true;
            bool B_alive = false;
            assert(A_alive || B_alive);
            Charlie_shoots(A_alive, B_alive);
            cout << "\tCase 3: Aaron alive, Bob dead\n"
                 << "\t\tCharlie is shooting at Aaron\n";
        }
    }

    void test_Aaron_shoots2(){
        cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n";

        //Case 1
        {
            //Reset values
            bool B_alive = true;
            bool C_alive = true;
            assert(B_alive || C_alive);
            Aaron_shoots2(B_alive, C_alive);
            cout << "\tCase 1: Bob alive, Charlie alive\n"
                 << "\t\tAaron intentionally misses his first shot\n";
        }

        //Case 1
        {
            //Reset values
            bool B_alive = false;
            bool C_alive = true;
            assert(B_alive || C_alive);
            Aaron_shoots2(B_alive, C_alive);
            cout << "\tCase 2: Bob dead, Charlie alive\n"
                 << "\t\tAaron is shooting at Charlie\n";
        }

        //Case 1
        {
            //Reset values
            bool B_alive = true;
            bool C_alive = false;
            assert(B_alive || C_alive);
            Aaron_shoots2(B_alive, C_alive);
            cout << "\tCase 3: Bob alive, Charlie dead\n"
                 << "\t\tAaron is shooting at Bob\n";
        }
    }





