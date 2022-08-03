#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
#include <stdexcept>
#include <optional>

namespace mydata {

    template <typename T>
    struct ListNode {
        T val;
        ListNode<T> *next;
    };

    template <typename T>
    class LinkedList {
        enum Error {
            OUT_OF_RANGE
        };

        private:
            int len; 
            ListNode<T> *head;
            ListNode<T> *tail;
        
        public:
            LinkedList<T>() {
                len = 0;
                head = NULL;
                tail = NULL;
            }

            virtual ~LinkedList<T>(){
                ListNode<T> *curr = head, *temp;
                while(curr != NULL) {
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
                if(tail == NULL) {
                    tail = new ListNode<T>();
                    if(head == NULL) head = tail;
                } else {
                    tail->next = new ListNode<T>();
                    tail = tail->next;
                }
                tail->val = val;
                len++;
            }

            /**
             * @brief Returns the nth value stored in the list.
             * 
             * @param n index number
             * @return T
             * @throws LinkedList::Error::OUT_OF_RANGE if @a index is larger than list len
             */
            virtual std::optional<T> getIndex(const int index) {
                if(index >= len) {
                    std::cerr << "Index `n` out of range: Must be less than list len.";
                    return OUT_OF_RANGE;
                }
                ListNode<T> *curr = head;
                
                for(int i = 0; i < index; i++) curr = curr->next;
                return curr->val;
            }

            virtual inline int size() { return len; }

            virtual std::optional<T> operator[](const int index) { return getIndex(index); }
    };
}

#endif // LINKEDLIST_HPP