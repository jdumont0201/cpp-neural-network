//
// Created by jbmdu on 08/04/2018.
//

#include "Global.h"
#include <iostream>
#include <vector>
#include <iterator>

template <typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
    if ( !v.empty() ) {
        out << '[';
        std::copy (v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
        out << "\b\b]";
    }
    return out;
}