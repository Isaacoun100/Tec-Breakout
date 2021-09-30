#include "login/Login.h"
#include "temp/ReadWrite.h"

/**
 * This is the main method that will clear the tmp.txt file and initiate the login interface
 * @return a 0 value if no issue was found.
 */
int main(){
    ReadWrite().clearFile();
    Login();
    return 0;
}
