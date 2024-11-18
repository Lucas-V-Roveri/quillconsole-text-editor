#include <iostream>
#include "Editor.hpp"
#include <string>
using namespace std;

Editor::Editor()
{
    this->currentLine = 0;
    this->cursorPos = 0;
}

/**
 * Handles the editor navigation and user input
 */
void Editor::display()
{
    system("cls");

    for (int i = 0; i < lines.size(); i++)
    {
        for (int j = 0; j < lines[i].size(); j++)
        {
            if (i == this->currentLine && j == this->cursorPos)
            {
                cout << "|";
            }
            else
            {
                cout << lines[i][j];
            }
        }
        cout << endl;
    }
}

/**
 * Handles the cursor movement
 * @recieves int direction
 */
void Editor::move(int ch)
{
    switch (ch)
    {
    case 13:
        lines.push_back(vector<char>());
        this->currentLine++;
        this->cursorPos = 0;
        break;
    case 75: // Left arrow key
        if (this->cursorPos != 0)
        {
            this->cursorPos--;
        }
        break;
    case 77: // Right arrow key
        if (this->cursorPos != lines[this->currentLine].size())
        {
            this->cursorPos++;
        }
        break;
    case 72: // Up arrow key
        if (this->currentLine != 0)
        {
            this->currentLine--;
        }
        break;
    case 80: // Down arrow key
        if (this->currentLine != lines.size() - 1)
        {
            this->currentLine++;
            this->cursorPos = 0;
        }
        break;

    default:
        break;
    }
}

void Editor::type(char c)
{
    while (this->currentLine >= lines.size())
    {
        lines.push_back(vector<char>());
    }
    if (this->cursorPos == lines[this->currentLine].size())
    {
        lines[this->currentLine].push_back(c);
    }
    else
    {
        lines[this->currentLine][this->cursorPos] = c;
    }
    cursorPos++;
}