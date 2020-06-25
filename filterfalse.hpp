//
// Created by Theila on 6/15/2020.
//

#ifndef C___FILTERFALSE_HPP
#define C___FILTERFALSE_HPP
#pragma once

#include <iostream>
#include <string>
using namespace std;

namespace itertools{
    template <typename condi, typename cont>
    class filterfalse
    {
    private:
        cont container;
        condi if_;
    public:
        filterfalse(condi co, cont c):container(c),if_(co){}

        class iterator {
            typename cont::iterator start_itert;
            typename cont::iterator end_it;
            condi if_;
        public:
            iterator(typename cont::iterator s_it,typename cont::iterator e_it,condi co):
                    start_itert(s_it),end_it(e_it), if_(co){}

            auto operator*()  {

                if(if_(*start_itert)) {
                    start_itert++;
                    return *start_itert;
                }else{
                }
            }

            iterator& operator++() {
                do {start_itert++;}
                while(start_itert!= end_it && if_(*start_itert));
                return *this;
            }

            bool operator==(const iterator& other) const {
                return start_itert == other.start_itert;
            }

            bool operator!=(const iterator& other) const {
                return start_itert != other.start_itert;
            }
        };

        iterator begin() {
            return iterator{container.begin(),container.end(),if_};
        }

        iterator end() {
            return iterator{container.end(),container.end(),if_};
        }
    };
}



#endif
