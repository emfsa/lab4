#pragma once
#include <vector>
#include "stack.h"
#include "checker.h"
#include "executer.h" 
#include "Table.h"      

class stdr
{
private:
    std::string _text;
    Stack<char> _sign;
    Stack<char> _Letter;
    std::vector<char> _Vsign;
    std::vector<char> _VLetter;
    bool isOk = true;
    checker chk;


    Executerr _logger;

public:

    explicit stdr(Table* table) : _logger(table), chk(table) {}

    void setText(const std::string& tmp)
    {
        _text = tmp;
        isOk = chk.checkLine(this->getText());
        if (!isOk)
        {
            _logger.thRow(logs("000"));
            clear();
            
            return;
        }
        splitText();
    }

    std::string getText() const { return _text; }
    bool isValid() const { return isOk; }
    void splitText()
    {
        _text = chk.delspace(_text);
        if (_text.size() != 0)
        {
            for (size_t i = 0; i < _text.size(); i++)
            {
                if (_text[i] == '(' || _text[i] == ')' || _text[i] == '+' || _text[i] == '-' || _text[i] == '*' || _text[i] == '/' || _text[i] == '=')
                {
                    _sign.Push(_text[i]);
                    _Vsign.push_back(_text[i]);
                }
                else if (std::isalnum(_text[i]))
                {
                    _Letter.Push(_text[i]);
                    _VLetter.push_back(_text[i]);
                }
            }
        }
    }

    std::string getStringSigns() { return std::string(_Vsign.begin(), _Vsign.end()); }
    std::string getStringLetters() { return std::string(_VLetter.begin(), _VLetter.end()); }

    Stack<char>& getSigns() { return _sign; }
    Stack<char>& getLetters() { return _Letter; }

    void clear()
    {
        _text.clear();
        _sign.clearData();
        _Letter.clearData();
        _Vsign.clear();
        _VLetter.clear();
    }

    ~stdr() { clear(); }
};