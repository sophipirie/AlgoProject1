//number11
#include <iostream>
#include<cstdlib>
#include <vector>
#include "LockBox.cpp"
using namespace std;


int main() {
    bool thefuck = true;
    int range = 3;
    LockBox l1(range, 6);
    while(thefuck) {


        //    vector<int> code = l1.generateCode();
        //    for (int i=0; i <code.size(); i++){
        //        cout <<code.at(i);
        //    }
        LockBox guess(range);
        int incorrect = l1.incorrectLocation(guess);
        cout << "incorrect " << incorrect <<endl;


        vector<int> code = l1.returnVector();
//        for (int i = 0; i < code.size(); i++) {
//            cout << code.at(i);
//        }
        if(l1.returnVector() == guess.returnVector()){
            thefuck = false;
        }
    }


}