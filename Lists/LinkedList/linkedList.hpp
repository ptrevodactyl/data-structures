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
            unsigned _size; 
            ListNode<T> *head;
            ListNode<T> *tail;
        
        public:
            LinkedList<T>() {
                _size = 0;
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
            void append(T val) {
                ListNode<T> *new_node = new ListNode<T>();
                new_node->val = val;
                new_node->next = nullptr;
                if(_size == 0) tail = head = new_node;
                else {
                    tail->next = new_node;
                    tail = new_node;
                }
                ++_size;
            }

            /**
             * @brief Inserts the value @a val at the beginning of the list.
             * 
             * @param val 
             */
            void prepend(T val) {
                ListNode<T> *new_node = new ListNode<T>();
                new_node->val = val;
                if(_size == 0) head = tail = new_node;
                else {
                    new_node->next = head;
                    head = new_node;
                }
                ++_size;
            }

            /**
             * @brief deletes the node at the beginning of the list
             */
            void pop_begin() {
                switch(_size) {
                    case 0:
                        return;
                    case 1:
                        delete head;
                        head = tail = nullptr;
                        break;
                    default:
                        ListNode<T> *temp = head->next;
                        delete head;
                        head = temp;
                }
                --_size;
            }

            /**
             * @brief Show the contents of the list
             * 
             * @param os the output stream to write to
             */
            void show(std::ostream& os = std::cout) {
                os << "[";
                for(ListNode<T> *curr = head; curr != nullptr; curr = curr->next) {
                    os << curr->val;
                    if(curr != tail) os << ", ";
                }
                os << "]";
            }

            /**
             * @brief Returns the number of elements in the list
             */
            inline unsigned size() { return _size; }
            
            template <typename J>
            friend std::ostream& operator<<(std::ostream& os, LinkedList<J>& ll);

            /**
             * @brief Iterator helpers
             */
            class iterator;
            iterator begin() { return iterator(head, *this); }
            iterator end() { return iterator(nullptr, *this); }
    };

    /**
     * @brief Show the contents of the list
     * 
     * @param os the output stream to write to
     */
    template <typename J>
    std::ostream& operator<<(std::ostream& os, LinkedList<J>& ll) {
        ll.show(os);
        return os;
    }

    /**
     * @brief Iterator class for LinkedLists
     * 
     * @tparam type T
     */
    template <typename T>
    class LinkedList<T>::iterator {
        private:
            ListNode<T> *_pos;
            LinkedList<T> &_ll;
        public:
            iterator(ListNode<T> *pos, LinkedList<T> &ll): _pos(pos), _ll(ll) {}
            
            iterator &operator++() {
                _pos = _pos->next;
                return *this;
            }

            bool operator!=(const iterator &other) const { return _pos != other._pos; }

            T operator*() { return _pos->val; }
    };
}

#endif // LINKEDLIST_HPP