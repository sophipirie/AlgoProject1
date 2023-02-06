#ifndef CLIENT_FEEDBACK
#define CLIENT_FEEDBACK

#include <iostream>
using namespace std;

class ClientFeedback {
	private:
		int correct;
		int incorrect;
	public:
		ClientFeedback();
		void setFeedback(int c, int i);
		int getCorrect();
		int getIncorrect();
		friend bool operator==(const ClientFeedback &x, const ClientFeedback &y);
		friend ostream& operator<< (ostream& ostr, const ClientFeedback &x);
};

#endif
