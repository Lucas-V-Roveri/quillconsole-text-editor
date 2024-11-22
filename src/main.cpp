#include <iostream>
#include <conio.h>
#include "Editor.hpp"

using namespace std;

int main()
{

    Editor *editor = new Editor;
    system("cls");
    while (true)
    {
        editor->display();
        int ch = _getch();

        if (ch == 0 || ch == 224)
        {
            ch = _getch();

            editor->move(ch);
        }
        else if (ch == 8 || ch == 13 || ch == 9)
        {
            editor->specialKeys(ch);
        }
        else if (ch == 3)
        {
            system("cls");
            break;
        }
        else
        {
            editor->type(ch);
        }
    }
}
