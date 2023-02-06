#include "LockBox.h"
#include <vector>
#include <string>
using namespace std;

int main() {
        vector<string> inputs = {"5,0,3,2,6", "2,1,2,2,2", "1,3,3,4,5"};

        int length;
        int digits;
        int count=0;

        cout << endl << "Enter the lock code length: ";
        cin >> length;
        cout << "Enter the range of digits: ";
        cin >> digits;

        LockBox* lock = new LockBox(length, digits);
        lock->generateCode(length, digits);

        LockBox* guess = new LockBox(length, digits);
        vector<int> code = lock->getCode();

        for (int i=0; i< inputs.size(); i++) {
                guess->setGuess(inputs.at(i));
                vector<int> g = guess->getGuess();
                cout<<"\nGuess: "<<inputs.at(i) <<endl;
                if (code == g) {
                        cout << "Correct! " << endl;
                } 
		else {
                        cout <<"Numbers in correct location: "<< lock->correctLocation(guess)<< endl;
                        cout <<"Numbers in the incorrect location: "<< lock->incorrectLocation(guess)<<endl;
		}
	}

	// print out the secret code:
	cout << endl;
	cout <<"The secret code: ";
	for (int i=0; i< code.size()-1; i++) {
		cout << code.at(i) << ",";
	}
	cout << code.at(code.size()-1) << endl;
	cout << endl;	
	return 0;
}
