//
// Created by Tehila on 6/15/2020.
//

#ifndef C___ACCUMULATE_HPP
#define C___ACCUMULATE_HPP

#pragma once

#include <iostream>
#include <string>
using namespace std;

namespace itertools{
    struct ADD
    {
    public:
        template <typename T>
        T operator()(T a, T b) { return a+b; }
    };
    template <typename T, typename func = ADD>
    class accumulate
    {
    private:
        T col;
        func add;
    public:
        accumulate(T c , func f=ADD()):
        col(c),
        add(f){}

        class iterator {
            typename T::iterator start_index;
            typename T::iterator end_index;
            decltype(*(col.begin())) sum;
            func add;
        public:
            iterator(typename T::iterator s_it,typename T::iterator e_it,func f):
                    start_index(s_it),end_index(e_it), sum(*s_it), add(f){}

            decltype(*(col.begin())) operator*() const {
                return sum;
            }

            iterator& operator++() {
                ++start_index;
                if(start_index==end_index)
                return *this;
                sum= add(sum,*start_index);
                return *this;
            }

            const iterator operator++(int) {
                iterator tmp= *this;
                ++start_index;
                if(start_index!=end_index)
                    sum= add(sum,*start_index);
                return tmp;
            }

            bool operator==(const iterator& other_iter) const {
                return start_index == other_iter.start_index;
            }

            bool operator!=(const iterator& other_iter) const {
                return start_index != other_iter.start_index;
            }
        };

        iterator begin() {
            return iterator{col.begin(),col.end(),add};
        }

        iterator end() {
            return iterator{col.end(),col.end(),add};
        }
    };
}

#endif //C___ACCUMULATE_HPP
