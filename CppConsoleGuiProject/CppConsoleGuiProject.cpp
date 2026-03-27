#include <iostream>

#include "GameViewLibrary.h"

int main()
{
    //Window* win = new Window({2, 3}, {20, 10}, Colors::DarkBlue, Colors::White, "Hello", BorderStyle::Double);
    //win->Show();
    //win->GetConsole()->GetChar();

    //GameView* gView = new GameView(2);
    //gView->Show();
    //gView->GetConsole()->GetChar();

    FieldView* fView = new FieldView({ 3, 4 }, 2, "Player");
    fView->Show();
    fView->GetConsole()->GetChar();
}
