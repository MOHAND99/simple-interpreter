//
// Created by Youssef on 16/05/2020.
//

#include "ExpressionEvaluator.h"

ExpressionEvaluator::ExpressionEvaluator(string expression):expression(expression),post("") {
}

void ExpressionEvaluator::addSpace() {
    //(--.5)*(-(-0.5)   )     + +10 / -(2)
    int expLength = expression.length();
    int index = 0;
    char expChar[expression.length() + 1];
    char space[10 * expLength];
    std::copy(expression.begin(), expression.end(), expChar);
    expChar[expLength] = '\0';
    for (int i = 0; i < expLength; i++) {
        if (expChar[i] == '/' || expChar[i] == '(' || expChar[i] == ')' ||
            (expChar[i] == '*' && !(expChar[i + 1] == '*'))) {
            if (i != 0) {
                space[index] = ' ';
                index++;
            }
            space[index] = expChar[i];
            index++;
            space[index] = ' ';
            index++;
        } else if (expChar[i] == '*' && expChar[i + 1] == '*') {
            space[index] = ' ';
            index++;
            space[index] = expChar[i];
            index++;
            space[index] = expChar[i + 1];
            index++;
            space[index] = ' ';
            index++;
            i++;
        } else if (expChar[i] == '+') {
            for (int j = i + 1; j < expLength; j++) {
                if (isdigit(expChar[j]) != 0 || expChar[j] == '(') {
                    space[index] = ' ';
                    index++;
                    space[index] = '+';
                    index++;
                    space[index] = ' ';
                    index++;
                    i = j - 1;
                    break;
                } else if (expChar[j] == '+' || expChar[j] == ' ') {
                    continue;
                } else {
                    cout << "Error" << endl;
                }
            }
        } else if ((expChar[i] == '-')) {
            int negCount = 0;
            int betOprator =0;
            for (int j = i + 1; j < expLength; j++) {
                if (isdigit(expChar[j]) != 0 || expChar[j] == '.') {
                    space[index] = ' ';
                    index++;
                    if (negCount % 2 != 0) {
                        space[index] = '+';
                        index++;
                        i = j - 1;
                        break;
                    }
                    space[index] = '-';
                    index++;
                    i = j - 1;
                    break;
                } else if (expChar[j] == '(') {
                    space[index] = ' ';
                    index++;
                    if (negCount ==0){
                        space[index]='(';
                        index++;
                        space[index]=' ';
                        index++;
                        space[index]='-';
                        index++;
                        i=j;
                        break;
                    }
                    if (negCount % 2 != 0) {
                        space[index] = '+';
                        index++;
                        i = j - 1;
                        break;
                    }
                    space[index] = '-';
                    index++;
                    i = j - 1;
                    break;
                } else if (expChar[j] == '-') {
                    negCount++;
                } else if (expChar[j] == ' ') {
                    continue;
                } else {
                    cout << "Error" << endl;
                }
            }
        } else {
            space[index] = expChar[i];
            index++;
        }
    }
    space[index] = '\0';
    int i;


    for (int k = 0; k < strlen(space); k++) {
      if (space[k] == '-' && isdigit(space[k + 1]) == 0) {

            for (int j = k +1; isdigit(space[j]) == 0; j++) {
                if (isdigit(space[j])==0&&space[j]=='-'){
                    space[j]='+';
                    space[k]=' ';
                } else if (isdigit(space[j])==0&&space[j]=='+'){
                    space[j]='-';
                    space[k]=' ';
                }
            }
        } else if(space[k] == '+' && isdigit(space[k + 1]) == 0){
          int beforeNumber=0;
          for (int l = k-1; l >= 0; l--) {
              if (space[l]!=' '&&isdigit(space[l])==0) {
                  beforeNumber++;
              }
              else if(space[l]!=' '){
                  break;
              }

          }
          if (beforeNumber !=0) {
              for (int j = k + 1; isdigit(space[j]) == 0; j++) {
                  if (isdigit(space[j]) == 0 && space[j] == '-') {
                        space[k]=' ';
                  }
              }
          }
      }

    }
        string s = "";
        for (i = 0; i < strlen(space); i++) {
            s = s + space[i];
        }
        cout << "expis:" << s << endl;
}
