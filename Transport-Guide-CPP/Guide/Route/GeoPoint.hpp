//
//  GeoPoint.hpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 03.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef GeoPoint_hpp
#define GeoPoint_hpp

namespace guide::route {

class GeoPoint
{
public:
    GeoPoint(double latitude, double longitude);
    
    double GetLatitude() const;
    double GetLongitude() const;
    double DistanceTo(const GeoPoint& geoPoint) const;
    
    bool operator==(const GeoPoint& rhs) const;
    
private:
    double latitude_;
    double longitude_;
    
private:
    constexpr static double EPS_ = 10e-6;
};

}

#endif /* GeoPoint_hpp */
