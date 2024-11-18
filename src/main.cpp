#include <iostream>
#include <conio.h>
#include "Editor.hpp"

using namespace std;

int main()
{

    Editor *editor = new Editor;

    while (true)
    {
        editor->display();
        int ch = _getch();

        if (ch == 0 || ch == 224)
        {
            ch = _getch();

            editor->move(ch);
        }
        else if (ch == 3)
        {
            break;
        }
        else
        {
            editor->type(ch);
        }
    }
}
