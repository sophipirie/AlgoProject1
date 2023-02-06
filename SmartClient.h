#ifndef SMART_CLIENT
#def SMART_CLIENT

#include <iostream>
#include "LockBox.h"
#include "ClientFeedback.h"
using namespace std;

class SmartClient {
	private:
		Lockbox *lockbox;
		int n;
		int m;
	public:
		SmartClient();
		void printCode();
		LockBox clientGuess();
		ClientFeedback getFeedback(int guess); 
		ClientFeedback isOpened(ClientFeedback &x);
		void openLockBox();
};
#endif
