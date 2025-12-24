#pragma once
#include "stdr.h"



class postfix
{
private:
    std::string _input;

    int getPriority(char op)
    {
        switch (op)
        {
        case '(':
            return 0;
        case ')':
            return 1;
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
            return 3;
        default:
            return -1;
        }
    }

public:
    postfix(const std::string& input) : _input(input) {}

    std::string toPostfix()
    {
        std::string output = "";
        Stack<char> opStack;
        for (char c : _input)
        {
            if (std::isalnum(c))  // операнд
            {
                output += c;
            }
            else if (c == '(')
            {
                opStack.Push(c);
            }
            else if (c == ')')
            {
                while (!opStack.isEmpty() && opStack.Top() != '(')
                {
                    output += opStack.Top();
                    opStack.Pop();
                }
                if (!opStack.isEmpty() && opStack.Top() == '(')
                    opStack.Pop();  // удаляем '('
            }
            else  // оператор
            {
                while (!opStack.isEmpty() &&
                    opStack.Top() != '(' &&
                    getPriority(opStack.Top()) >= getPriority(c))
                {
                    output += opStack.Top();
                    opStack.Pop();
                }
                opStack.Push(c);
            }
        }

        // Очистка стека
        while (!opStack.isEmpty())
        {
            output += opStack.Top();
            opStack.Pop();
        }

        return output;
    }


#include <cctype>   // для isdigit
#include <stdexcept> // для исключений

    long SolveString()
    {
        Stack<long> numStack; // Убедитесь, что ваш Stack поддерживает тип long

        for (char c : _input)
        {
            if (std::isdigit(static_cast<unsigned char>(c)))
            {
                numStack.Push(c - '0'); // однозначные числа
            }
            else if (c == '+' || c == '-' || c == '*' || c == '/')
            {
              
                long b = numStack.Top();
                numStack.Pop();

                long a = numStack.Top(); 
                numStack.Pop();          

                long result = 0;
                switch (c)
                {
                case '+':
                    result = a + b;
                    break;
                case '-':
                    result = a - b;
                    break;
                case '*':
                    result = a * b;
                    break;
                case '/':
                    /*if (b == 0) */
                        
                    result = a / b;
                    break;
                default:
                    break;
                }
                numStack.Push(result);
            }
            
        }

       
        return numStack.Top();
    }

    void clear()
    {
        _input.clear();
    }

    ~postfix()
    {
        clear();
    }
};