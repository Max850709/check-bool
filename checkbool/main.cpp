//
//  main.cpp
//  checkbool
//
//  Created by Max on 2021/6/22.
//  Copyright © 2021年 Max. All rights reserved.
//

#include <iostream>
#include <stack>
#include <cstring>
#include <stdio.h>
#include <string.h>
using namespace std;

int main() {
    
    int n;
    string s;
    cin >> n;
    cin.get();
    for(int i=0;i<n;i++){
        getline(cin,s);
        int boolean=0;
        stack <int> myStack;
        for(int j=0;j<s.size();j++){
            if(s.at(j)=='[' || s.at(j)=='{' || s.at(j)=='<' || s.at(j)=='('){
                myStack.push(s.at(j));
            }
            else if(s.at(j)==']' || s.at(j)=='}' || s.at(j)=='>' || s.at(j)==')'){
                if (myStack.size() <=0){
                    boolean+=1;
                }
                else if(s.at(j)==']'){
                    char pair = myStack.top();
                    if (pair =='['){
                        myStack.pop();
                    }
                    else{
                        boolean+=1;
                    }
                }
                else if(s.at(j)=='}'){
                    
                    char pair = myStack.top();
                    if (pair =='{'){
                        myStack.pop();
                    }
                    else{
                        boolean+=1;
                    }
                }
                else if(s.at(j)=='>'){
                    
                    char pair = myStack.top();
                    if (pair =='<'){
                        myStack.pop();
                    }
                    else{
                        boolean+=1;
                    }
                }
                else if(s.at(j)==')'){
                    
                    char pair = myStack.top();
                    if (pair =='('){
                        myStack.pop();
                    }
                    else{
                        boolean+=1;
                    }
                }
            }
        }
        if(myStack.size()>0){
            boolean+=1;
        }
        
        if(boolean==0){
            cout << "Y" << endl;
        }
        else{
            cout << "N" << endl;
        }
    }
    return 0;
}
