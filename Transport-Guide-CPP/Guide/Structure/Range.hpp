//
//  Range.hpp
//  Transport-Guide-CPP
//
//  Created by Mykyta Cheshulko on 07.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef Range_hpp
#define Range_hpp

namespace guide::structure {

template <typename It>
class Range {
public:
    using ValueType = typename std::iterator_traits<It>::value_type;

    Range(It begin, It end) : begin_(begin), end_(end) {}
    It begin() const { return begin_; }
    It end() const { return end_; }

private:
    It begin_;
    It end_;
};

}

#endif /* Range_hpp */
