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
    char space[2*expression.length()+1];
    std::copy(expression.begin(), expression.end(), expChar);
    expChar[expLength] = '\0';
    for (int i = 0; i <expLength ; i++) {
        if (expChar[i] =='/'||expChar[i] =='+'||expChar[i] =='('||expChar[i] ==')'||
        (expChar[i] =='*'&& !(expChar[i+1]=='*'))||(i!=0&&expChar[i]=='-'&&expChar[i+1]!='-'&&expChar[i-1]!='/'&&expChar[i-1]!='('
        &&expChar[i-1]!='+'&&expChar[i-1]!='*'&&expChar[i-1]!=')')){
            index++;
            space[index]=' ';
            index++;
            space[index]=expChar[i];
            index++;
            space[index]=' ';
        }else if (expChar[i] =='*'&&expChar[i+1]=='*'){
            index++;
            space[index]=' ';
            index++;
            space[index]=expChar[i];
            index++;
            space[index]=expChar[i+1];
            index++;
            space[index]=' ';
            i++;
        } else if ((expChar[i]=='-'&&expChar[i+1]=='-')){
            index++;
            space[index]=' ';
            index++;
            space[index]=expChar[i];
            index++;
            space[index]=' ';
            index++;
            space[index]=expChar[i+1];
            i++;
        }
        else {
            index++;
            space[index] = expChar[i];

        }
    }
    int i;
    string s = "";
    for (i = 0; i <expLength*3+1; i++) {
        s = s + space[i];
    }
    cout<<"expis:"<<s<<endl;
}

//int ExpressionEvaluator::evaluateExp() {
//
//    return 0;
//}
//
//void ExpressionEvaluator::changeToPostifix() {
//    string exp = expression;
//    char *ptOperator;
//    cout<<exp<<endl;
//
//    for (int i = 0; i < expression.length(); i++) {
//        if (exp[i] == '+') {
//            ptOperator = "+";
//            exp = remainderExp(exp, ptOperator);
//            cout << exp << endl;
//            i=0;
//        }
////        if (exp[i] == '+' || exp[i] == '/') {
////            exp =remainderExp(post,exp,&exp[i]);
////            cout << exp[i] << endl;
//        else if ((exp[i] == '*' && exp[i + 1] != '*')) {
//            ptOperator="*";
//            exp = remainderExp(exp,ptOperator);
//            cout << exp << endl;
//            i=0;
//        } else if (exp[i]=='*'&&exp[i]=='*'){
//            ptOperator="**";
//            exp =remainderExp(exp,ptOperator);
//            cout<<exp<<endl;
//            i=0;
//        }
//    //else if (exp[i]=='('){
////            exp =remainderExp(post,exp,&exp[i]);
////            cout<<exp<<endl;
////        }
//    }
//}
//
//
//
//string ExpressionEvaluator::remainderExp(string exp, char oper[]){
//    int i=0;
//    string newExp="";
//    char chararr[exp.length()];
//    char postarr[exp.length()];
//    for(int x=0;x<exp.length();x++){
//        if(strcasecmp(reinterpret_cast<const char *>(exp[i]), oper)==0){
//            postarr[i] = ' ';
//            break;
//        } else{
//            postarr[i] = exp[i];
//            i+=1;
//        }
//    }
//    i=0;
//    if (strlen((char*)oper)==1) {
//        for (int j = 0; j < exp.length(); j++) {
//            if (strcasecmp(reinterpret_cast<const char *>(exp[j]), oper) != 0 || i != 0) {
//                chararr[i] = exp[j + 1];
//                i = i + 1;
//            }
//        }
//    } else{
//
//    }
//    for(int i=0;i<exp.length();i++){
//        newExp=newExp+chararr[i];
//    }
//    for(int i=0;i<exp.length();i++){
//        post=post+postarr[i];
//    }
//    //cout<<chararr<<endl;
//    return newExp;
//}
//
//void ExpressionEvaluator::addToStack(string oper) {
//
//}
//
//bool ExpressionEvaluator::checkNumber(string num) {
//    return false;
//}
//
//string ExpressionEvaluator::checkOperatorCondition(string ope){
//    return std::__cxx11::string();
//}
