#include <iostream>

struct node {
    int number;
    node* next;
    node(): number(0), next(nullptr) { }
    node(int _number): number(_number) { }
};

int main() {
    node* head = new node(1);
    head->next = new node(2);
    node* second = head->next;
    std::cout << "head->number = " << head->number << std::endl;
    std::cout << "head->next->number = " << head->next->number << std::endl;
    std::cout << "second->nunber = " << second->number << std::endl;

    return 0;
}
