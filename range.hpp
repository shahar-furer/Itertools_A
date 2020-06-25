//
// Created by netanel & Or on 6/15/2020.
//

#ifndef C___RANGE_HPP
#define C___RANGE_HPP

#include <iostream>
#include <string>

#pragma once

    namespace itertools{
        class range{
            int start_index, end_index ;
        public:
            typedef int	value_type;
            range(int s, int e): start_index(s),end_index(e){}
            class iterator{
            private:
                int now_index;

            public:

                iterator(int c)
                        : now_index(c) {
                }
                int operator*() const {
                    return now_index;
                }
                iterator& operator++() {
                    ++this->now_index;
                    return *this;
                }
                const iterator operator++(int) {
                    iterator tmp= *this;
                    ++now_index;
                    return tmp;
                }
                bool operator==(const iterator& r) const {
                    return now_index == r.now_index;
                }
                bool operator!=(const iterator& r) const {
                    return now_index != r.now_index;
                }
            };  

            iterator begin() {
                return iterator{start_index};
            }

            iterator end() {
                return iterator{end_index};
            }
//
//          typename range::iterator range::begin()
//          {
//              return iterator{ *this, start_index };
//          }
//
//
//            typename range::iterator range::end()
//            {
//                return iterator{ *this, end_index };
//            }

        };
    }



#endif //C___RANGE_HPP
