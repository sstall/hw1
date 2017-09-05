//Dequeue.cpp
//Samuel Stall
//COP3503 Data Structures and Algorithms

#include "Bounded_Dequeue.h"
#include <iostream>

bool Dequeue_size_0(Bounded_Dequeue<int> d0) {
     if(!d0.is_full()) {
          return false;
     }
     if(!d0.is_empty()) {
          return false;
     }
     try {
          d0.push_front(1);
          return false;
     } catch(...) {}
     try {
          d0.pop_front();
          return false;
     } catch(...) {}

     return true;
}

bool Dequeue_size_1(Bounded_Dequeue<int> d1) {
     if(d1.is_full()) {
          return false;
     }
     if(!d1.is_empty()) {
          return false;
     }
     try {
          d1.push_front(1);
          if(d1.peek_front() != 1) {
               return false;
          }
     } catch(...) {}
     try {
          d1.pop_back();
          d1.pop_back();
          return false;
     } catch (...) {}

     return true;
}

bool Dequeue_size_5(Bounded_Dequeue<int> d5) {
     if(d5.is_full()) {
          return false;
     }
     if(!d5.is_empty()) {
          return false;
     }
     try {
          d5.push_front(1);
          d5.push_front(2);
          d5.push_front(3);
          d5.push_front(4);
          d5.push_front(5);
     } catch(...) {
          return false;
     }
     if(d5.pop_back() != 1) {
          return false;
     }
     if(d5.pop_back() != 2) {
          return false;
     }
     if(d5.pop_back() != 3) {
          return false;
     }
     if(d5.pop_back() != 4) {
          return false;
     }
     if(d5.pop_back() != 5) {
          return false;
     }

     try {
          d5.pop_back();
          return false;
     } catch(...) {}

     //Test wrap around
     try {
          d5.push_back(1);
          d5.push_back(2);
          d5.push_back(3);
          d5.push_back(4);
          d5.pop_front();
          d5.push_back(11);
          d5.pop_front();
          d5.push_back(12);
          if(d5.pop_front() != 3) {
               return false;
          }
          if(d5.pop_back() != 12) {
               return false;
          }
     } catch(...) {
          return false;
     }

     //Test clear
     try {
          d5.clear();
          if(!d5.is_empty()) {
               return false;
          }
          if(d5.is_full()) {
               return false;
          }
     } catch(...) {}
     try {
          d5.peek_front();
          return false;
     } catch(...) {}
     return true;
}
int main() {
     bool dequeue0 = Dequeue_size_0(Bounded_Dequeue<int>(0));
     bool dequeue1 = Dequeue_size_1(Bounded_Dequeue<int>(1));
     bool dequeue5 = Dequeue_size_5(Bounded_Dequeue<int>(5));

     std::cout << "Dequeue size 0 test: ";
     if(dequeue0) {
          std::cout << "PASSED" << std::endl;
     }
     else {
          std::cout << "FAILED" << std::endl;
     }

     std::cout << "Dequeue size 1 test: ";
     if(dequeue1) {
          std::cout << "PASSED" << std::endl;
     }
     else {
          std::cout << "FAILED" << std::endl;
     }

     std::cout << "Dequeue size 5 test: ";
     if(dequeue5) {
          std::cout << "PASSED" << std::endl;
     }
     else {
          std::cout << "FAILED" << std::endl;
     }

     std::cout << "All tests: ";
     if(dequeue0 && dequeue1 && dequeue5) {
          std::cout << "PASSED" << std::endl;
     }
     else {
          std::cout << "AT LEAST ONE FAILED" << std::endl;
     }

     return 0;
}
