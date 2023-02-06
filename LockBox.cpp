#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "LockBox.h"
using namespace std;

LockBox::LockBox(int n, int m) {
	length = n;
	range = m;
}

void LockBox::generateCode(int n, int m) {
	int value;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		value = rand() % m;
		v.push_back(value);
	}
	//for (int i = 0; i<n; i++) {
	//	cout << v.at(i) << " ";
	//}
	randomCode = v;
}

vector<int> LockBox::getCode() {
	return randomCode;
}

void LockBox::setGuess(string s) {
	vector<int> v;

	for (int i=0; i < s.size(); i++ ) {
                if (isdigit(s[i])) {
                        v.push_back(s[i] - '0');
                }
        }
        guess = v;
}
		
vector<int> LockBox::getGuess() {
	return guess;
}

int LockBox::correctLocation(LockBox *g) {
	vector<int> x = this->getCode();
	vector<int> y = g->getGuess();
	int correct = 0;

	for (int i = 0; i < x.size(); i++) {
		if (x.at(i) == y.at(i)) {
			correct++;	
		}
	}
	return correct;
}

int LockBox::incorrectLocation(LockBox *g) {
	vector<int> x = this->getCode();
	vector<int> y = g->getGuess();
	int incorrect = 0;
	vector<int> copyCode(x.size());
	vector<int> x1;
	vector<int> y1;
/*
	for (int i = 0; i < x.size(); i++) {
		for (int j = 0; j < x.size(); i++) {
			if (x.at(i) == y.at(i) && i==j) {
				copyCode[i] = 1;
			}
			if (x.at(i) == y.at(i) && i!=j && copyCode.at(i)!=2 && copyCode.at(i)!= 1) {
				copyCode[i] = 2;
				incorrect++;
				break;
			}
		}
	}
	return incorrect;
}
*/

	for (int i = 0; i < x.size(); i++) {
		if (x.at(i) != y.at(i)) {
			x1.push_back(x.at(i));
			y1.push_back(y.at(i));
		}	
	}
/*
	for (int i = 0; i < x1.size()-1; i++) {
		if (x1.at(i) == x1.at(i+1)) {
			x1.at(i) = -1;
		}
	}
*/
	for (int i = 0; i < x1.size(); i++) {
		for (int j = 0; j < y1.size(); j++) {
			if ((x1.at(i) == y1.at(j)) && (i != j)) {
				incorrect++;
				break;
			}
		}
	}
	return incorrect;
}
/*
int main() {

	int length;
	int digits;
	int count = 0;
	bool done = false;

	cout << "Enter the lock code length: ";
	cin >> length;
	cout << "Enter the range of digits: ";
	cin >> digits;

	LockBox *answer = new LockBox(length, digits);
	answer->generateCode(length, digits);

	string input;
	LockBox *guess = new LockBox(length, digits);

	while (!done && count++ < 10) {
		cout << "Enter your guess separated by commas with no spaces: ";
		cin >> input;
		guess->setGuess(input);
		
		vector<int> code = answer->getCode();
		vector<int> g = guess->getGuess();

		if (code == g) {
			cout << "Correct!" << endl;
			done = true;
		}
		else {
			cout << "Numbers in correct location: " << answer->correctLocation(guess) << endl;
			cout << "Numbers in incorrect location: " << answer->incorrectLocation(guess) << endl;
		}
}


	if (count > 10) {
		cout << "System disabled" << endl;
	}

return 0;
}
*/
