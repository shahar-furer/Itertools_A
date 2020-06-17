//
// Created by Tehila on 6/15/2020.
//

#pragma once

#include <iostream>
#include <string>
using namespace std;

namespace itertools {
    template<typename cont, typename cont2>
    class compress {
        private:
        cont container;
        cont2 flags;
    public:
        compress(cont c, cont2 f) : container(c), flags(f) {}

        class iterator {
            typename cont::iterator start1_it;
            typename cont::iterator end1_it;
            typename cont2::iterator start2_it;
            typename cont2::iterator end2_it;
        public:
            iterator(typename cont::iterator s_it, typename cont::iterator e_it, typename cont2::iterator sF_it,
                     typename cont2::iterator eF_it) :
                    start1_it(s_it), end1_it(e_it), start2_it(sF_it), end2_it(eF_it) {}

            decltype(*(container.begin())) operator*() {
                if (!(*start2_it))
                    ++(*this);
                return *start1_it;
            }

            iterator &operator++() {
                do {
                    ++start1_it;
                    ++start2_it;
                }
                while (start1_it != end1_it && !(*start2_it)); // go to index of second container
                return *this;
            }

            const iterator operator++(int) {
                iterator tmp = *this;
                ++(*this);
                return tmp;
            }

            bool operator==(const iterator &other) const {
                return (start1_it == other.start1_it) && (start2_it == other.start2_it);
            }

            bool operator!=(const iterator &other) const {
                return (start1_it != other.start1_it) || (start2_it != other.start2_it);
            }
        }; 

        iterator begin() {
            return iterator{container.begin(), container.end(), flags.begin(), flags.end()};
        }

        iterator end() {
            return iterator{container.end(), container.end(), flags.end(), flags.end()};
        }
    };
}