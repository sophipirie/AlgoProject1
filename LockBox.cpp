#include <iostream>
#include <vector>
#include <string>
#include <sstream>
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
        vector<int>::iterator it1, it2;	

        vector<int> x1;
	vector<int> y1;


	// Transfer the unmatch ones to another vectors
	for (int i = 0; i < x.size(); i++) {
		if (x.at(i) != y.at(i)) {
			x1.push_back(x.at(i));
			y1.push_back(y.at(i));
		}
	}

	for (int i = 0; i < x1.size(); i++) {
		for (int j = 0; j < y1.size(); j++) {
			if ((x1.at(i) == y1.at(j)) && (i != j)) {
				incorrect++;
			}
		} 
	}
	return incorrect;
}

int main() {

	int length;
	int digits;
	int count = 0;

	cout << "Enter the lock code length: ";
	cin >> length;
	cout << "Enter the range of digits: ";
	cin >> digits;

	LockBox *answer = new LockBox(length, digits);
	answer->generateCode(length, digits);

	string input;
	LockBox *guess = new LockBox(length, digits);

	bool done = false;

	while (!done && count++ <= 10) {
		cout << "Enter your guess separated by commas with no spaces: ";
		cin >> input;
		guess->setGuess(input);

		vector<int> code = answer->getCode();
		vector<int> g = guess->getGuess();

		if (code == g) {
			cout << "correct! \n";
			done = true;
		} else {
			cout << answer->correctLocation(guess) << "," <<  answer->incorrectLocation(guess) << endl;
        	}
	}	

	if (count > 10) cout << "system disabled \n"; 
	return 0;
}
