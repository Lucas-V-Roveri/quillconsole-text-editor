#include <iostream>
#include "Editor.hpp"
#include <string>
#include <windows.h>

using namespace std;

Editor::Editor()
{
    this->currentLine = 0;
    this->cursorPos = 0;
    this->hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

/**
 * Handles the editor navigation and user input
 */
void Editor::display()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(this->hConsole, &csbi);
    int consoleWidth = csbi.dwSize.X;

    for (int i = 0; i < lines.size(); i++)
    {
        DWORD charsWritten;

        std::string stringedArray(lines[i].begin(), lines[i].end());
        WriteConsoleOutputCharacterA(this->hConsole, stringedArray.c_str(), lines[i].size() + 1, {0, (SHORT)i}, &charsWritten);
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
    case 75: // Left arrow key
        if (this->cursorPos != 0)
        {
            this->cursorPos--;
            SetConsoleCursorPosition(this->hConsole, {this->cursorPos, this->currentLine});
        }
        break;
    case 77: // Right arrow key
        if (this->cursorPos != lines[this->currentLine].size())
        {
            this->cursorPos++;
            SetConsoleCursorPosition(this->hConsole, {this->cursorPos, this->currentLine});
        }
        break;
    case 72: // Up arrow key
        if (this->currentLine != 0)
        {
            this->currentLine--;
            this->cursorPos = this->cursorPos > lines[this->currentLine].size() ? lines[this->currentLine].size() : this->cursorPos;
            SetConsoleCursorPosition(this->hConsole, {this->cursorPos, this->currentLine});
        }
        break;
    case 80: // Down arrow key
        if (this->currentLine != lines.size() - 1)
        {
            this->currentLine++;
            this->cursorPos = this->cursorPos > lines[this->currentLine].size() ? lines[this->currentLine].size() : this->cursorPos;
            SetConsoleCursorPosition(this->hConsole, {this->cursorPos, this->currentLine});
        }
        break;

    default:
        break;
    }
}

/**
 * Handles special keys input
 * @recieves int ascii code of the key pressed
 */
void Editor::specialKeys(int ch)
{
    switch (ch)
    {
    case 13: // Enter key
        lines.push_back(vector<char>());
        this->currentLine++;
        this->cursorPos = 0;
        SetConsoleCursorPosition(this->hConsole, {this->cursorPos, this->currentLine});
        break;
    case 9: // TAB key
        for (short i = 0; i <= 4; i++)
        {
            lines[this->currentLine].push_back(' ');
            this->move(77);
        }
        break;
    case 8: // Backspace Key
        int lineLength = lines[this->currentLine].size();
        if (lineLength > 0)
        {
            for (short i = this->cursorPos - 1; i < lineLength; i++)
            {
                lines[this->currentLine][i] = lines[this->currentLine][i++];
            }
            lines[this->currentLine].resize(lineLength - 1);
            this->move(75);
        }
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

        lines[currentLine].insert(lines[currentLine].begin() + cursorPos, c);
        this->display();
    }
    this->move(77);
}
