//
//  Route.cpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 02.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#include "Route.hpp"

namespace guide::route {

Route::Route(Route::Type type)
    : type_(type)
{}

bool Route::operator==(const Route& rhs) const
{
    return this->GetName() == rhs.GetName();
}

bool Route::operator<(const Route& rhs) const
{
    return std::lexicographical_compare(
        this->GetName().cbegin(), this->GetName().cend(),
        rhs.GetName().cbegin(), rhs.GetName().cend());
}

std::ostream& operator<<(std::ostream& os, const Route::Type& routeType)
{
    switch (routeType) {
        case Route::Type::Linear:  os << std::string{ "Linear" }; break;
        case Route::Type::Circle:  os << std::string{ "Circle" }; break;
        case Route::Type::Unknown: os << std::string{ "Unknown" }; break;
    }
    
    return os;
}

std::ostream& operator<<(std::ostream& os, const Route& route)
{
    os << std::string{ "`Route`(" }
       << route.GetName()
       << std::string{ " " } << route.GetRouteType()
       << std::string { " : \n" };
    
    for(const auto& stop: route.GetRouteStops()) {
        os << std::string(4, ' ') << *stop.lock() << std::string { "\n" };
    }
    
    os << std::string{ ")" };
    
    return os;
}

}
