// ThreeAlgorithmTasks.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <list>

template<typename T>
struct ListNode;

template<typename T>
void printList(ListNode<T>* head);

template<typename T>
void printListFromSTL(std::list<T> lst);

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


template<typename T> 
std::list<T> reverseListFromSTL(std::list<T> head)
{
    int numberOfNodesToPushToBack = head.size();
    while (numberOfNodesToPushToBack > 1)
    {
        int frontValue = head.front();
        head.push_back(frontValue);
        head.pop_front();
        numberOfNodesToPushToBack -= 1;
    }
    return head;
}

#include <memory>
#include <vector>

class TreeNode
{
public:
    TreeNode(int value = 0, TreeNode* left = nullptr, TreeNode* right = nullptr)
    {
        this->left = left;
        this->right = right;
        this->value = value;
    }

    bool search(int target)
    {

        if (this->value < target)
        {
            if (this->right)
            {
                return this->right->search(target);
            }
            return false;
        }
        else if (this->value > target)
        {
            if (this->left)
            {
                return this->left->search(target);
            }
            return false;
        }
        else {
            return true;
        }
    }

    TreeNode* left;
    TreeNode* right;
    int value;
};

template<typename T>
std::shared_ptr<TreeNode<T>> getBinaryTreeSearchFromSortedArray(const std::vector<T>& sortedVector, unsigned int leftIndex, unsigned int rightIndex)
{
    if (rightIndex - leftIndex == 0)
    {
        return nullptr;
    }
    unsigned int currentMiddle = (rightIndex - leftIndex) / 2;
    std::shared_ptr<TreeNode<T>> root(new TreeNode{ sortedVector[currentMiddle] });
    root->left = getBinaryTreeSearchFromSortedArray(sortedVector, leftIndex, currentMiddle - 1);
    root->right = getBinaryTreeSearchFromSortedArray(sortedVector, currentMiddle + 1, rightIndex);
    return root;
}





int main()
{
    
    return 0;
}


template<typename T>
void printList(ListNode<T>* head)
{
    while (head)
    {
        std::cout << head->value << '\n';
        head = head->next;
    }
}

template<typename T>
void printListFromSTL(std::list<T> lst)
{
    for (auto it = lst.begin(); it != lst.end(); it++)
    {
        std::cout << *it << std::endl;
    }
}