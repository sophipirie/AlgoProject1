#ifndef LOCKBOX
#define LOCKBOX

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class LockBox {
        private:
                int length;
                int range;
                vector <int> randomCode;
                vector <int> guess;
        public:
                LockBox(int, int);
                void setRandomCode(string);
                void generateCode(int, int);
                vector<int> getCode();
                void setGuess(string s);
                vector<int> getGuess();
                int correctLocation(LockBox *);
                int incorrectLocation(LockBox *);
};

#endif
