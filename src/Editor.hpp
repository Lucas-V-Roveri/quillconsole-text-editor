#ifndef EDITOR_HPP
#define EDITOR_HPP
#include <vector>
#include <string>

using namespace std;

class Editor
{
public:
    Editor();
    void display();
    void move(int ch);
    void type(char c);

private:
    vector<vector<char>> lines;
    int currentLine;
    int cursorPos;
};

#endif