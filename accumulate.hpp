//
// Created by netanel & Or on 6/15/2020.
//

#ifndef C___ACCUMULATE_HPP
#define C___ACCUMULATE_HPP

#pragma once

#include <iostream>
#include <string>
using namespace std;

namespace itertools{
    class ADD
    {
    public:

        template <typename T>
        T operator()(T a, T b) { return a + b;
        }
    };
    template <typename T, typename func = ADD>
    class accumulate
    {

    private:
        T bin;
        func function;

        typedef typename T::value_type sum;
    public:
        accumulate(T c , func f=ADD()):
        bin(c),
        function(f){};
        class iterator {
            typename T::iterator start_index;
            typename T::iterator end_index;
            typename T::value_type sum;
            func function;
        public:
            iterator(typename T::iterator s_it,typename T::iterator e_it,func f):
                    start_index(s_it),end_index(e_it), sum(*s_it), function(f){}

            auto operator*() {
                return sum;
            }

            iterator& operator++() {
                ++start_index;
                if(start_index!=end_index)
                     sum= function(sum,*start_index);
                return *this;
            }

            const iterator operator++(int) {
                iterator tmp= *this;
                ++start_index;
                if(start_index!=end_index)
                    accumulate::iterator::sum= function(sum,*start_index);
                return tmp;
            }

            bool operator==(const iterator& other) const {
                return start_index == other.start_index;
            }

            bool operator!=(const iterator& other) const {
                return start_index != other.start_index;
            }
        };
        iterator begin() {
            return iterator{bin.begin(),bin.end(),function};
        }

        iterator end() {
            return iterator{bin.end(),bin.end(),function};
        }
    };
}

#endif
