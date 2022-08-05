#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
#include <type_traits>

namespace mydata {

    template <typename T>
    struct ListNode {
        T val;
        ListNode<T> *next;

        ListNode() { next = nullptr; }
        ~ListNode() {}
    };

    template <typename T>
    class LinkedList {
        private:
            unsigned size; 
            ListNode<T> *head;
            ListNode<T> *tail;
        
        public:
            LinkedList<T>() {
                size = 0;
                head = nullptr;
                tail = nullptr;
            }

            virtual ~LinkedList<T>(){
                ListNode<T> *curr = head, *temp;
                while(curr != nullptr) {
                    temp = curr;
                    curr = curr->next;
                    delete temp;
                }
            }

            /**
             * @brief Inserts the value @a val at the end of the list.
             * 
             * @param val 
             */
            virtual void append(T val) {
                ListNode<T> *new_node = new ListNode<T>();
                new_node->val = val;
                new_node->next = nullptr;
                if(size == 0) tail = head = new_node;
                else {
                    tail->next = new_node;
                    tail = new_node;
                }
                size++;
            }

            /**
             * @brief Inserts the value @a val at the beginning of the list.
             * 
             * @param val 
             */
            virtual void prepend(T val) {
                ListNode<T> *new_node = new ListNode<T>();
                new_node->val = val;
                if(size == 0) head = tail = new_node;
                else {
                    new_node->next = head;
                    head = new_node;
                }
                size++;
            }

            /**
             * @brief Returns the number of elements in the list
             * 
             * @return size_t size
             */
            virtual inline unsigned getSize() { return size; }

            /**
             * @brief Get the value stored at the beginning of the list
             * 
             * @return T
             */
            virtual inline T getHead() { return head->val; }

            /**
             * @brief Get the value stored at the end of the list
             * 
             * @return T
             */
            virtual inline T getTail() { return tail->val; }

            /**
             * @brief Show the contents of the list
             * 
             * @param os 
             */
            virtual void show(std::ostream& os = std::cout) {
                os << "[";
                for(ListNode<T> *curr = head; curr != nullptr; curr = curr->next) {
                    os << curr->val;
                    if(curr != tail) os << ", ";
                }
                os << "]";
            }

            template <typename J>
            friend std::ostream& operator<<(std::ostream& os, LinkedList<J>& ll);
    };

    template <typename J>
    std::ostream& operator<<(std::ostream& os, LinkedList<J>& ll) {
        ll.show(os);
        return os;
    }
}

#endif // LINKEDLIST_HPP