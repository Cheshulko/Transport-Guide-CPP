//
//  GeoPoint.cpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 03.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#include "GeoPoint.hpp"

#include <cmath>

namespace guide::route {

GeoPoint::GeoPoint(double latitude, double longitude)
    : latitude_(latitude)
    , longitude_(longitude)
{}

double GeoPoint::GetLatitude() const
{
    return latitude_;
}

double GeoPoint::GetLongitude() const
{
    return longitude_;
}

double GeoPoint::DistanceTo(const GeoPoint& geoPoint) const
{
    if (*this == geoPoint) {
        return 0.0;
    }
    
    const long long R = 6371e3; // metres
    const double   PI = 3.1415926535;
    const double   PI_RAD = PI / 180;
    
    const double lat1 = this->GetLatitude();
    const double lon1 = this->GetLongitude();
    
    const double lat2 = geoPoint.GetLatitude();
    const double lon2 = geoPoint.GetLongitude();
    
    const double f1 = lat1 * PI_RAD; // φ, λ in radians
    const double f2 = lat2 * PI_RAD;
    const double df = (lat2 - lat1) * PI_RAD;
    const double dl = (lon2 - lon1) * PI_RAD;

    const double a = sin(df / 2) * sin(df / 2) +
                     cos(f1) * cos(f2) *
                     sin(dl / 2) * sin(dl / 2);
    const double c = 2 * atan2(sqrt(a), sqrt(1-a));

    const double d = R * c; // in metres
    
    return d;
}

bool GeoPoint::operator==(const GeoPoint& rhs) const
{
    return fabs(this->GetLatitude()  - rhs.GetLatitude())  < EPS_ &&
           fabs(this->GetLongitude() - rhs.GetLongitude()) < EPS_;
}

}
