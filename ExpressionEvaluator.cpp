//
// Created by Youssef on 16/05/2020.
//

#include "ExpressionEvaluator.h"

ExpressionEvaluator::ExpressionEvaluator(string expression):expression(expression),post("") {
}
void ExpressionEvaluator::addSpace() {
    int expLength = expression.length();
    int index = 0;
    char expChar[expression.length() + 1];
    char space[10 * expLength];
    std::copy(expression.begin(), expression.end(), expChar);
    expChar[expLength] = '\0';
    for (int i = 0; i < expLength; i++) {
        if (expChar[i] == '/' || expChar[i] == '(' || expChar[i] == ')' ||
            expChar[i] == '*' ||expChar[i] == '^' ) {
            if (i != 0) {
                space[index] = ' ';
                index++;
            }
            space[index] = expChar[i];
            index++;
            space[index] = ' ';
            index++;
        }else if (expChar[i] == '+') {
            for (int j=i-1 ;j>=0;j--) {
                if (isdigit(expChar[j])==0&&expChar[j] != ' ' ) {
                    space[index]=' ';
                    index++;
                    space[index]='1';
                    index++;
                    space[index]=' ';
                    index++;
                    space[index]='*';
                    index++;
                    space[index]=' ';
                    index++;
                    space[index]='1';
                    index++;
                    space[index]=' ';
                    index++;
                    space[index]='*';
                    index++;
                    space[index]=' ';
                    index++;
                    break;
                } else if (isdigit(expChar[j])!=0&&expChar[j] != ' '){
                    space[index]=' ';
                    index++;
                    space[index]='+';
                    index++;
                    space[index]=' ';
                    index++;
                    break;
                }
            }
        }else if (expChar[i] == '-') {
            for (int j = i-1; j >= 0 ; j--) {
                if (expChar[j] != ' ' && isdigit(expChar[j]) == 0) {
                    space[index]=' ';
                    index++;
                    space[index]='1';
                    index++;
                    space[index]=' ';
                    index++;
                    space[index]='*';
                    index++;
                    space[index]=' ';
                    index++;
                    space[index]='-';
                    index++;
                    space[index]='1';
                    index++;
                    space[index]=' ';
                    index++;
                    space[index]='*';
                    index++;
                    space[index]=' ';
                    index++;
                    break;
                } else if (expChar[j] != ' ' && isdigit(expChar[j]) != 0){
                    space[index]=' ';
                    index++;
                    space[index]='+';
                    index++;
                    space[index]=' ';
                    index++;
                    break;
                }

            }
        }else{
            space[index] = expChar[i];
            index++;
        }
    }
    space[index] = '\0';
    string s = "";
    for (int i = 0; i < strlen(space); i++) {
        s = s + space[i];
    }
    cout << "expis:" << s << endl;
}
