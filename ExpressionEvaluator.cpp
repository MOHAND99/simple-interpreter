//
// Created by Youssef on 16/05/2020.
//

#include "ExpressionEvaluator.h"

ExpressionEvaluator::ExpressionEvaluator(string expression):expression(expression),post("") {
}

void ExpressionEvaluator::addSpace() {
    int expLength = expression.length();
    int index=0;
    char expChar[expression.length()+1];
    char space[10*expLength];
    std::copy(expression.begin(), expression.end(), expChar);
    expChar[expLength] = '\0';
    for (int i = 0; i <expLength ; i++) {
        if (expChar[i] =='/'||expChar[i] =='('||expChar[i] ==')'||
        (expChar[i] =='*'&& !(expChar[i+1]=='*'))||(i!=0&&expChar[i]=='-'&&expChar[i+1]!='-'&&expChar[i-1]!='/'&&expChar[i-1]!='('
        &&expChar[i-1]!='+'&&expChar[i-1]!='*'&&expChar[i-1]!=')'&&expChar[i-1]!=' ')){
            if (i!=0) {
                space[index] = ' ';
                index++;
            }
            space[index]=expChar[i];
            index++;
            space[index]=' ';
            index++;
        }else if (expChar[i] =='*'&&expChar[i+1]=='*'){
            space[index]=' ';
            index++;
            space[index]=expChar[i];
            index++;
            space[index]=expChar[i+1];
            index++;
            space[index]=' ';
            index++;
            i++;
        } else if (expChar[i] =='+'){
            for (int j = i+1; j <expLength ; j++) {
                if (isdigit(expChar[j])!=0){
                    space[index]=' ';
                    index++;
                    space[index]='+';
                    index++;
                    space[index]=' ';
                    index++;
                    break;
                } else if(expChar[j]=='+'){
                    space[index]=' ';
                    index++;
                    space[index]='+';
                    index++;
                    space[index]=' ';
                    index++;
                    i=j;
                    break;
                }
            }
        } else if ((expChar[i]=='-')){
            for (int j = i+1; j <expLength ; j++) {
                if (isdigit(expChar[j])!=0){
                    space[index]=' ';
                    index++;
                    space[index]='-';
                    index++;
                    break;
                }else if(expChar[j]=='-'){
                    space[index]=' ';
                    index++;
                    space[index]='+';
                    index++;
                    space[index]=' ';
                    index++;
                    i=j;
                    break;
                } else if (expChar[j]=='('){
                    space[index]=' ';
                    index++;
                    space[index]='(';
                    index++;
                    space[index]=' ';
                    index++;
                    space[index]='-';
                    index++;
                    i=j;
                    break;
                } else if (expChar[j]=='+'){
                    space[index]=' ';
                    index++;
                    space[index]='-';
                    index++;
                    space[index]=' ';
                    index++;
                    i=j;
                    break;
                }  else if (!isdigit(expChar[j])&&expChar[j]!=' '){
                    space[index]=' ';
                    index++;
                    space[index]='-';
                    index++;
                    space[index]=' ';
                    index++;
                    j=i;
                    break;
                }
            }
        }

        else {
            space[index] = expChar[i];
            index++;
        }
    }
    space[index]='\0';
    int i;
    string s = "";
    for (i = 0; i <strlen(space); i++) {
        s = s + space[i];
    }
    cout<<"expis:"<<s<<endl;
}
