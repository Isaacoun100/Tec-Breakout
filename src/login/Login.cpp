#include "Login.h"

/**
 *
 */
Login::Login() {
    string option;
    cout<<"*********************************************************\n"
          "***             WELCOME TO TEC BREAKOUT              ****\n"
          "* PLEASE SELECT IF YOU WANT TO LOG AS PLAYER OR SERVER **\n"
          "***    PRESS ( 1 ) FOR PLAYER,   ( 2 ) FOR SERVER    ****\n"
          "***      OR PRESS ( 0 ) TO FINALIZE THE SESSION      ****\n"
          "*********************************************************\n";
    cin>>option;

    if(option=="0"){
        return;
    }
    else if(option=="1"){
        StartClient();
        return;
    }
    else if(option=="2"){
        StartServer();
        return;
    }
    else{
        cout<<"Option not found, please try again"<<endl;
        Login();
    }

}
