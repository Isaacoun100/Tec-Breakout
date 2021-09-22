
#include "gui/game.h"
auto game = new Game();
int listenClient(){
    string txt;
    cin >> txt;
    if(txt =="LEFT"){
        game->moveToLeftBar();
        cout << " Me MOVI ala izquierda"<< endl;
        return listenClient();
    }
    else if(txt =="RIGHT") {
        game->moveToRightBar();
        cout <<" Me MOVI ala derecha"<< endl;
        return listenClient();
    }
    else if (txt=="salir"){
        game->stop();
        return 0;
    }else{
        return listenClient();

    }
}


int main() {
    game->run();
    delete game;
}