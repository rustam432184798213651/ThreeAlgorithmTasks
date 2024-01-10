// ThreeAlgorithmTasks.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <stack>
#include <string>

int FibonacciNumber(int n)
{
    if (n <= 0)
    {
        throw "Such Fibonacci number does not exist";
    }
    if (n == 1 || n == 2)
        return 1;
    return FibonacciNumber(n - 1) + FibonacciNumber(n - 2);
}

// Check if the string is balanced in terms of open and closed brackets
bool isBalancedString(std::string str)
{
    std::stack<char> Stack;
    for (auto el : str)
    {
        if (el == '(')
        {
            Stack.push(el);
        }
        else if (el == ')')
        {
            if (Stack.size() == 0)
            {
                return false;
            }
            else
            {
                Stack.pop();
            }
        }
    }
    return Stack.size() == 0;
}

template <typename T>
struct ListNode
{
    ListNode(T value = 0, ListNode * next = nullptr)
    {
        this->value = value;
        this->next = next;
    }
    T value;
    ListNode * next;
    
};

template<typename T>
ListNode<T>* reverseList(ListNode<T>* head)
{
    // If the size of the list 0 or 1 we just have to return head because there is no need in reversion it because result will be the same. 
    if (!head or !(head->next))
    {
        return head;
    }

    ListNode<T>* cur = head;
    ListNode<T>* next = head->next;
    head->next = nullptr;
    while (next)
    {
        ListNode<T>* tmp = next->next;
        next->next = cur;
        cur = next;
        next = tmp;
    }
    return cur;
}


int main()
{

    return 0;
}
