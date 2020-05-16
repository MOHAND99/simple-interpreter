#include <iostream>
#include <string>
#include <dshow.h>
#include "Headers/Interpretation.h"

using namespace std;

int main() {

    Interpretation interpretation;
    interpretation.execute("myFile");

    return 0;
}
