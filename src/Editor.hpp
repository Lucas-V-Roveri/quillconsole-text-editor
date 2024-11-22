#ifndef EDITOR_HPP
#define EDITOR_HPP
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

class Editor
{
public:
    Editor();
    void display();
    void move(int ch);
    void type(char c);
    void specialKeys(int ch);

private:
    vector<vector<char>> lines;
    short currentLine;
    short cursorPos;
    COORD coord;
    HANDLE hConsole;
};

#endif