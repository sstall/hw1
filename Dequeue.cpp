//Dequeue.cpp
//Samuel Stall
//COP3503 Data Structures and Algorithms

#include "Bounded_Dequeue.h"
#include <iostream>

int main() {
     Bounded_Dequeue<int> d1 = Bounded_Dequeue<int>(3);
     d1.push_front(1);
     d1.push_front(0);
     d1.push_front(5);
     std::cout << d1.pop_front() << std::endl;
     d1.push_back(9);
     std::cout << d1.pop_front() << std::endl;
     std::cout << d1.pop_front() << std::endl;
     std::cout << d1.pop_front() << std::endl;
     std::cout << d1.is_empty() << std::endl;
     return 0;
}
