//
// Created by sophi on 2/3/2023.
//

#include <iostream>
#include <vector>
#include<cstdlib>
#include <ctime>
using namespace std;

class LockBox{
private:
    vector<int> vCode;
    int x;
public:
    LockBox(int n, int m){
        vCode = generateCode(n, m);
    };
    LockBox(int n){
        vector<int> guessCode(n);
        cout << "Enter code by digit" << endl;
        for(int i =0; i < n; i++){
            cin >> guessCode[i];
        }
        vCode = guessCode;

    };
    vector<int> generateCode(int n, int m){
        srand(time(0));
        vector<int> vCode(n);
        for (int i = 0; i < n; i++){
            int x = rand()%(m-1);
            cout << x << endl;
            vCode[i]=x;
        }
        return vCode;
    };
    vector<int> returnVector(){
        return vCode;
    };

    int correctLocation(LockBox code){
        int correct;
        //for loop if index guess == wrong index

        return correct;
    }
    int incorrectLocation(LockBox guess){
        int lockCodeSize = this->vCode.size();
        int incorrect;
        vector<int> copyCode(lockCodeSize, 0);

        for (int j = 0; j < lockCodeSize; j++){
            for (int i =0; i<lockCodeSize; i++){
                if(this->vCode.at(j) == guess.returnVector().at(i) && i==j){
                    copyCode[i] = 1;
                }
                if(this->vCode.at(j) == guess.returnVector().at(i) && i!=j && copyCode.at(i)!= 2 && copyCode.at(i)!= 1){
                    copyCode[i] = 2;
                    incorrect ++;
                    break;
                }
            }
        }
        return incorrect;
    }
};
