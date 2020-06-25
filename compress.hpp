//
// Created by netan on 6/15/2020.
//

#pragma once

#include <iostream>
#include <string>

using namespace std;

namespace itertools {
    template<typename cont, typename cont2>
    class compress {
        //private:
        cont container;
        cont2 cont_flags;
    public:
        compress(cont c, cont2 f) : container(c), cont_flags(f) {}

        class iterator {
            typename cont::iterator start_it;
            typename cont::iterator end_it;
            typename cont2::iterator startF_it;
            typename cont2::iterator endF_it;
        public:
            iterator(typename cont::iterator s_it, typename cont::iterator e_it, typename cont2::iterator sF_it,
                     typename cont2::iterator eF_it) :
                    start_it(s_it), end_it(e_it), startF_it(sF_it), endF_it(eF_it) {}

            auto operator*() {
                if ((*startF_it)) {
                    //++(*this);
                    return *start_it;
                }
                return *start_it;
            }

//            iterator &operator++() {
//                do {
//                    ++start_it;
//                    ++startF_it;
//                } while (start_it != end_it && !(*startF_it));
//                return *this;
//            }
//
//            const iterator operator++(int) {
//                iterator tmp = *this;
//                ++(*this);
//                return tmp;
//            }

            iterator& operator++(){
                ++start_it;
                ++startF_it;
                while((start_it != end_it &&!(*startF_it))) {
                    ++start_it;
                    ++startF_it;
                }
                return *this;
            }

            const iterator operator++(int){
                iterator temp = *this;
                ++start_it;
                ++startF_it;
                return temp;
            }

            bool operator==(const iterator &other) const {
                return (start_it == other.start_it) && (startF_it == other.startF_it);
            }

            bool operator!=(const iterator &other) const {
                return (start_it != other.start_it) || (startF_it != other.startF_it);
            }
        }; // END OF CLASS ITERATOR

        iterator begin() {
            return iterator{container.begin(), container.end(), cont_flags.begin(), cont_flags.end()};
        }

        iterator end() {
            return iterator{container.end(), container.end(), cont_flags.end(), cont_flags.end()};
        }
    };
}