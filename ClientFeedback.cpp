#include <iostream>
#include "ClientFeedback.h"
using namespace std;

ClientFeedback::ClientFeedback() {
	correct = 0;
	incorrect = 0;
}

void ClientFeedback::setFeedback(int c, int i) {
	correct = c;
	incorrect = i;
}

int ClientFeedback::getCorrect() {
	return correct;
}

int ClientFeedback::getIncorrect() {
	return incorrect;
}

bool operator==(const ClientFeedback &x, const ClientFeedback &y) {
	return ((x.correct == y.correct) && (x.incorrect == y.incorrect));
}	
               
ostream& operator<< (ostream& ostr, const ClientFeedback &x) {
	ostr << x.correct << "," << x.incorrect;
	return ostr;
}
