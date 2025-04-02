// Name: 155. Min Stack
// Topics: Stack Design
// Companies:
// - Zenefits
// - Paytm
// - Tinkoff
// - Snap
// - Splunk
// - Lyft
// - Yandex
// - Intuit
// - Palo Alto Networks
// - Qualcomm
// - Snowflake
// - Salesforce
// - Oracle
// - Agoda
// - ServiceNow
// - Walmart Labs
// - PayPal
// - DE Shaw
// - Flipkart
// - Nvidia
// - LinkedIn
// - Cisco

#include <iostream>
#include <vector>

class MinStack
{
private:
    std::vector<int> contents;
    std::vector<int> mins_history;

public:
    MinStack() {}

    // NOTE: We don't need to check for operations on an empty stack because the
    //       problem's description guarantees we will always be able to effectuate
    //       the requested operations/moves.

    void push(int val)
    {
        contents.push_back(val);

        if (mins_history.empty() || mins_history.back() >= val)
            mins_history.push_back(val);
    }

    void pop()
    {
        int to_pop = contents.back();
        contents.pop_back();

        if (to_pop == mins_history.back())
            mins_history.pop_back();
    }

    int top()
    {
        return contents.back();
    }

    int get_min()
    {
        return mins_history.back();
    }
};

int main(void)
{
    MinStack the_stack;

    the_stack.push(-2);
    the_stack.push(0);
    the_stack.push(-3);

    std::cout << the_stack.get_min() << std::endl;

    the_stack.pop();
    std::cout << the_stack.top() << std::endl;
    std::cout << the_stack.get_min() << std::endl;

    return 0;
}
