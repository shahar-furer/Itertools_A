//
// Created by Teheila on 6/15/2020.
//

#ifndef C___RANGE_HPP
#define C___RANGE_HPP

#include <iostream>
#include <string>

#pragma once

    namespace itertools{
        class range{
            int s_i, e_i ;
        public:
            typedef int	value_type;
            range(int start, int end): s_i(start),e_i(end){}
            class iterator{
            private:
                int index;

            public:

                iterator(int c)
                        : index(c) {
                }
                auto operator*() const {
                    return index;
                }
                auto& operator++() {
                    ++this->index;
                    return *this;
                }
                const iterator operator++(int) {
                    iterator tmp= *this;
                    ++index;
                    return tmp;
                }
                bool operator==(const iterator& r) const {
                    return index == r.index;
                }
                bool operator!=(const iterator& r) const {
                    return index != r.index;
                }
            };  

            iterator begin() {
                return iterator{s_i};
            }

            iterator end() {
                return iterator{e_i};
            }


        };
    }



#endif //C___RANGE_HPP
