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
            (expChar[i] == '*' && !(expChar[i + 1] == '*')) ) {
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
            if (i==0){
                space[index]='+';
                index++;
            }
            if (i != 0 && isdigit(expChar[i - 1]) != 0) {
                space[index] = ' ';
                index++;
                space[index] = expChar[i];
                index++;
                space[index] = ' ';
                index++;
            }else if (isdigit(expChar[i + 1]) != 0 || expChar[i + 1] == '.') {
                for (int j = i - 1; j > 0; j--) {
                    if (expChar[i] == '+') {
                        space[index] = ' ';
                        index++;
                        space[index] = '+';
                        index++;
                        break;
                    }
                }
            }else {
                space[index] = expChar[i];
                index++;
                space[index] = ' ';
                index++;
            }
        }else if (expChar[i] == '-') {
                if (i==0){
                    space[index]='-';
                    index++;
                }
                if (i != 0 && isdigit(expChar[i - 1]) != 0) {
                    space[index] = ' ';
                    index++;
                    space[index] = expChar[i];
                    index++;
                    space[index] = ' ';
                    index++;
                }else if (isdigit(expChar[i + 1]) != 0 || expChar[i + 1] == '.') {
                    for (int j = i - 1; j > 0; j--) {
                        if (expChar[i] == '-') {
                            space[index] = ' ';
                            index++;
                            space[index] = '-';
                            index++;
                            break;
                        }
                    }
                }else {
                    space[index] = expChar[i];
                    index++;
                    space[index] = ' ';
                    index++;
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

//void ExpressionEvaluator::addSpace() {
//    //(--.5)*(-(-0.5)   )     + +10 / -(2)
//    int expLength = expression.length();
//    int index = 0;
//    char expChar[expression.length() + 1];
//    char space[10 * expLength];
//    std::copy(expression.begin(), expression.end(), expChar);
//    expChar[expLength] = '\0';
//    for (int i = 0; i < expLength; i++) {
//        if (expChar[i] == '/' || expChar[i] == '(' || expChar[i] == ')' ||
//            (expChar[i] == '*' && !(expChar[i + 1] == '*'))) {
//            if (i != 0) {
//                space[index] = ' ';
//                index++;
//            }
//            space[index] = expChar[i];
//            index++;
//            space[index] = ' ';
//            index++;
//        } else if (expChar[i] == '*' && expChar[i + 1] == '*') {
//            space[index] = ' ';
//            index++;
//            space[index] = expChar[i];
//            index++;
//            space[index] = expChar[i + 1];
//            index++;
//            space[index] = ' ';
//            index++;
//            i++;
//        } else if (expChar[i] == '+') {
//            for (int j = i + 1; j < expLength; j++) {
//                if (isdigit(expChar[j]) != 0||expChar[j] =='.'|| expChar[j] == '(') {
//                    space[index] = ' ';
//                    index++;
//                    space[index] = '+';
//                    index++;
//                    space[index] = ' ';
//                    index++;
//                    i = j - 1;
//                    break;
//                } else if (expChar[j] == '+' || expChar[j] == ' ') {
//                    continue;
//                } else if (expChar[j] == '/'||expChar[j] == '*') {
//                    cout << "Error "<<expChar[j] << endl;
//                }
//            }
//        } else if ((expChar[i] == '-')) {
//            int negCount = 0;
//            int postCount=0;
//            int beforNum =0;
//            for (int j = i + 1; j < expLength; j++) {
//                if (isdigit(expChar[j]) != 0 || expChar[j] == '.') {
//                    space[index] = ' ';
//                    index++;
//                    for (int k = i; k >= 0 ; k--) {
//                        if (isdigit(expChar[k])!=0){
//                            beforNum++;
//                            break;
//                        }if (expChar[k]=='(')
//                            break;
//                    }
//
//                    if (negCount %2 ==0&&beforNum!=0){
//                        space[index] = '-';
//                        index++;
//                        space[index]=' ';
//                        index++;
//                        i = j-1;
//                        break;
//                    }
//                    if (negCount % 2 != 0&&beforNum!=0) {
//                        space[index] = '+';
//                        index++;
//                        space[index]=' ';
//                        index++;
//                        i = j - 1;
//                        break;
//                    }else if (negCount==0){
//                        space[index] = '-';
//                        index++;
//                        space[index]=' ';
//                        index++;
//                        i = j - 1;
//                        break;
//                    }
//                    space[index] = '-';
//                    index++;
//                    i = j - 1;
//                    break;
//                } else if (expChar[j] == '+'){
//                  postCount++;
//                } else if (expChar[j] == '(') {
//                    space[index] = ' ';
//                    index++;
//                    if (negCount ==0&&expChar[j-1]!=' '&&postCount==0){
//                        space[index]='(';
//                        index++;
//                        space[index]=' ';
//                        index++;
//                        space[index]='-';
//                        index++;
//                        i=j;
//                        break;
//                    }else if(negCount%2==0){
//                        space[index] = '-';
//                        index++;
//                        i = j-1;
//                        break;
//                    }else if (negCount % 2 != 0) {
//                        space[index] = '+';
//                        index++;
//                        i = j - 1;
//                        break;
//                    }else if (postCount!=0){
//                        space[index] = '-';
//                        index++;
//                        i = j-1;
//                        break;
//                    }
//
//                    space[index] = '-';
//                    index++;
//                    i = j - 1;
//                    break;
//                } else if (expChar[j] == '-') {
//                    negCount++;
//                } else if (expChar[j] == ' ') {
//                    continue;
//                } else if (expChar[j] == '/'||expChar[j] == '*'){
//                    cout << "Error "<<expChar[j] << endl;
//                }
//            }
//        } else {
//            space[index] = expChar[i];
//            index++;
//        }
//    }
//    space[index] = '\0';
//    int i;
////
//
//    for (int k = 0; k < strlen(space); k++) {
//      if (space[k] == '-' && isdigit(space[k + 1]) == 0) {
//          int beforeNumber=0;
//          int brackect = 0;
//          int post=0;
//          int neg=0;
//          for (int l = k-1; l >= 0; l--) {
//              if (space[l]!=' '&&isdigit(space[l])!=0) {
//                  beforeNumber++;
//              } else if (space[l]=='('){
//                brackect++;
//              }
//              else if(space[l]!=' '){
//                  break;
//              }
//
//          }
//
//          for (int m = k+1; m <isdigit(space[m])!=0 ; m++) {
//              if(space[m]=='+') {
//                  post++;
//                  space[m]=' ';
//              } else if (space[m]=='-'){
//                  neg++;
//                  space[m]=' ';
//              }
//
//          }
//          if (neg%2!=0){
//              space[k]='-';
//          } else {
//              space[k]='+';
//          }
//
//            for (int j = k +1; isdigit(space[j]) == 0; j++) {
//                if (isdigit(space[j])==0&&space[j]=='-'){
//                    space[j]='+';
//                    space[k]=' ';
//                } else if (isdigit(space[j])==0&&space[j]=='+'){
//                    if (beforeNumber!=0) {
//                        space[j] = '-';
//                        space[k] = ' ';
//                    }
//                }
//            }
//        } else if(space[k] == '+' && isdigit(space[k + 1]) == 0){
//          int beforeNumber=0;
//          for (int l = k-1; l >= 0; l--) {
//              if (space[l]!=' '&&isdigit(space[l])==0) {
//                  beforeNumber++;
//              }
//              else if(space[l]!=' '&&isdigit(space[l]!=0)){
//                  beforeNumber++;
//                  break;
//              } else if(space[l]!='('&&space[l]!=' '){
//                  beforeNumber=0;
//                  break;
//              }
//
//          }
//          if (beforeNumber !=0) {
//              for (int j = k + 1; isdigit(space[j]) == 0; j++) {
//                  if (isdigit(space[j]) == 0 && space[j] == '-') {
//                        space[k]=' ';
//                  }
//              }
//          } else if (beforeNumber==0){
//              space[k]=' ';
//          }
//      }
//
//    }
//        string s = "";
//        for (i = 0; i < strlen(space); i++) {
//            s = s + space[i];
//        }
//        cout << "expis:" << s << endl;
//}
