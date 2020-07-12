//
//  RoutesMap.hpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 02.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef RoutesMap_hpp
#define RoutesMap_hpp

#include "Route.hpp"
#include "Stop.hpp"

#include "DirectedWeightedGraph.hpp"
#include "Router.hpp"

#include <optional>
#include <set>
#include <unordered_map>
#include <map>
#include <tuple>

namespace guide::route {

class RoutesMap
{
public:
    class Settings final
    {
    public:
        Settings(size_t busWaitTime, size_t busVelocity);
        
        size_t GetBusWaitTime() const;
        size_t GetBusVelocity() const;
        
    private:
        size_t busWaitTime_;
        size_t busVelocity_;
    };
    
public:
    RoutesMap();
    RoutesMap(std::vector<std::shared_ptr<Route>> routes, std::vector<std::shared_ptr<Stop>> stops);
    
    bool AddStop(std::shared_ptr<Stop> stop);
    bool AddRoute(std::shared_ptr<Route> route);
    
    std::optional<std::weak_ptr<Stop>> FindStop(const std::string& name) const;
    std::optional<std::weak_ptr<Stop>> FindStop(std::shared_ptr<Stop> stop) const;
    std::optional<std::weak_ptr<Route>> FindRoute(const std::string& name) const;
    
    void SetSettings(std::shared_ptr<Settings> settings_);
    
    size_t GetStopsCount() const;
    const Settings& GetSettings() const;
    std::optional<size_t> GetStopId(std::shared_ptr<Stop> stop) const;
    std::optional<std::weak_ptr<Stop>> GetStop(size_t stopId) const;
    std::optional<std::weak_ptr<Route>> GetRoute(size_t routeId) const;
    
    std::vector<std::tuple<
        std::weak_ptr<Stop>,  /* From stop     */
        std::weak_ptr<Stop>,  /* To stop       */
        double,               /* Time, minutes */
        std::weak_ptr<Route>, /* Using route   */
        size_t                /* Stops count   */
    >> GetOptimalRoute(std::shared_ptr<Stop> fromStop, std::shared_ptr<Stop> toStop);
     
    void BuildGraph();

private:
    std::shared_ptr<Settings> settings_;
    
private:
    std::set<std::shared_ptr<Route>, Route::SharedComparator> routes_;
    std::set<std::shared_ptr<Stop>, Stop::SharedComparator> stops_;
    
private: /* These for graph */
    std::map<
        std::weak_ptr<Stop>,
        size_t,
        Stop::WeakComparator
    > stopsId_;
    std::vector<std::weak_ptr<Stop>> idStops_;
    std::vector<std::weak_ptr<Route>> idRoutes_;

private:
    std::unique_ptr<structure::graph::Router<double>> router_;
    std::unique_ptr<structure::graph::DirectedWeightedGraph<double>> graph_;
};

}

#endif /* RoutesMap_hpp */
