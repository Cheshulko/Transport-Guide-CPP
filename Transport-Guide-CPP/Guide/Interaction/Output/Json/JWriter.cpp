//
//  JWriter.cpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 06.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#include "JWriter.hpp"
#include "RouteInfoResponse.hpp"
#include "StopCrossingRoutesResponse.hpp"
#include "OptimalRouteResponse.hpp"
#include "ErrorResponse.hpp"

#include <iostream>
#include <iomanip>
#include <map>
#include <vector>

namespace guide::interaction::output::json {

JWriter::JWriter(serialization::json::Document& document)
    : document_(document)
    , rootArray_(document_.GetRoot().AsArray())
{}

void JWriter::WriteRouteInfoResponse(const response::RouteInfoResponse& routeInfoResponse)
{
    using Node = serialization::json::Node;
    
    const auto& routeInfoResponseData = routeInfoResponse.GetRouteInfoResponseData();
    
    Node routeInfoResponseNode {
        std::map<std::string, Node> {}
    };
    
    auto& routeInfoResponseNodeMap = routeInfoResponseNode.AsMap();
    
    // TODO: Fix `Yeah Yeah Yeah` case
    
    if (auto routeIdOpt = routeInfoResponseData.GetRouteId(); routeIdOpt.has_value()) {
        routeInfoResponseNodeMap["request_id"] = Node {
            static_cast<int>(routeIdOpt.value())
        }; // Yeah Yeah Yeah
    } else {
        // TODO: Exception for this case
        throw std::runtime_error("No route id in response data");
    }
    
    routeInfoResponseNodeMap["stop_count"] = Node {
        static_cast<int>(routeInfoResponseData.GetStopsCnt())
    }; // Yeah Yeah Yeah
    
    routeInfoResponseNodeMap["unique_stop_count"] = Node {
        static_cast<int>(routeInfoResponseData.GetUniqueStopsCnt())
    }; // Yeah Yeah Yeah
    
    routeInfoResponseNodeMap["route_length"] = Node {
        routeInfoResponseData.GetRoutePracticalLength()
    };
    
    const double curvature = routeInfoResponseData.GetRoutePracticalLength() / routeInfoResponseData.GetRouteLength();
    routeInfoResponseNodeMap["curvature"] = Node {
        curvature
    };

    rootArray_.push_back(routeInfoResponseNode);
}

void JWriter::WriteStopCrossingRoutesResponse(const response::StopCrossingRoutesResponse& stopCrossingRoutesResponse)
{
    using Node = serialization::json::Node;
    
    const auto& crossingRoutesResponseData = stopCrossingRoutesResponse.GetStopCrossingRoutesResponseData();
    
    Node stopCrossingRoutesResponseNode {
        std::map<std::string, Node> {}
    };
    
    auto& stopCrossingRoutesResponseNodeMap = stopCrossingRoutesResponseNode.AsMap();
    
    // TODO: Fix `Yeah Yeah Yeah` case

    if (auto stopIdOpt = crossingRoutesResponseData.GetStopId(); stopIdOpt.has_value()) {
        stopCrossingRoutesResponseNodeMap["request_id"] = Node {
            static_cast<int>(stopIdOpt.value())
        }; // Yeah Yeah Yeah
    } else {
        // TODO: Exception for this case
        throw std::runtime_error("No stop id in response data");
    }
    
    Node stopCrossingRoutesBusesNode {
        std::vector<Node> {}
    };
    
    auto& stopCrossingRoutesBusesNodeMap = stopCrossingRoutesBusesNode.AsArray();
    
    const auto& crossingRoutesNames = crossingRoutesResponseData.GetCrossingRoutesNames();
    for (const auto& crossingRouteName: crossingRoutesNames) {
        stopCrossingRoutesBusesNodeMap.push_back( Node {
            crossingRouteName
        });
    }
    
    stopCrossingRoutesResponseNodeMap["buses"] = stopCrossingRoutesBusesNode;
    rootArray_.push_back(stopCrossingRoutesResponseNode);
}

void JWriter::WriteOptimalRouteResponse(const response::OptimalRouteResponse& optimalRouteResponse)
{
    using Node = serialization::json::Node;
    
    const auto& optimalRouteResponseData = optimalRouteResponse.GetOptimalRouteResponseData();
    
    Node optimalRouteResponseNode {
        std::map<std::string, Node> {}
    };
    
    auto& optimalRouteResponseNodeMap = optimalRouteResponseNode.AsMap();
    
    // TODO: Fix `Yeah Yeah Yeah` case
    
    if (auto requestIdOpt = optimalRouteResponseData.GetRequestId(); requestIdOpt.has_value()) {
        optimalRouteResponseNodeMap["request_id"] = Node {
            static_cast<int>(requestIdOpt.value())
        }; // Yeah Yeah Yeah
    } else {
        // TODO: Exception for this case
        throw std::runtime_error("No id in response data");
    }
    
    optimalRouteResponseNodeMap["total_time"] = Node {
        optimalRouteResponseData.GetTime()
    };
    
    optimalRouteResponseNodeMap["items"] = Node {
        std::vector<Node> {}
    };
    
    auto& optimalRouteResponseItems = optimalRouteResponseNodeMap["items"].AsArray();
    
    for (const auto& item: optimalRouteResponseData.GetItems()) {
        
        Node itemNode {
            std::map<std::string, Node> {}
        };
        
        auto& itemNodeMap = itemNode.AsMap();
        
        switch (item->GetType()) {
            case response::data::OptimalRouteResponseData::Item::Type::Wait: {
                
                itemNodeMap["time"] = Node {
                    item->GetTime()
                };
                itemNodeMap["stop_name"] = Node {
                    item->GetName()
                };
                itemNodeMap["type"] = Node {
                    std::string { "Wait" }
                };
                
                break;
            }
            case response::data::OptimalRouteResponseData::Item::Type::Bus: {
                    
                itemNodeMap["time"] = Node {
                    item->GetTime()
                };
                itemNodeMap["bus"] = Node {
                    item->GetName()
                };
                itemNodeMap["span_count"] = Node {
                    static_cast<int>(item->GetCount())
                };
                itemNodeMap["type"] = Node {
                    std::string { "Bus" }
                };
                
                break;
            }
        }
        
        optimalRouteResponseItems.push_back(std::move(itemNode));
    }
    
    rootArray_.push_back(optimalRouteResponseNode);
}

void JWriter::WriteErrorResponse(const response::ErrorResponse& errorResponse)
{
    using Node = serialization::json::Node;
    
    const auto& errorResponseData = errorResponse.GetErrorResponseData();
    
    Node errorResponseNode {
        std::map<std::string, Node> {}
    };
    
    auto& errorResponseNodeMap = errorResponseNode.AsMap();
    
    // TODO: Fix `Yeah Yeah Yeah` case
    
    if (auto requestIdOpt = errorResponseData.GetRequestId(); requestIdOpt.has_value()) {
        errorResponseNodeMap["request_id"] = Node {
            static_cast<int>(requestIdOpt.value())
        }; // Yeah Yeah Yeah
    } else {
        // TODO: Exception for this case
        throw std::runtime_error("No id in response data");
    }
    
    errorResponseNodeMap["error_message"] = Node {
        errorResponseData.GetErrorMessage()
    };
    
    rootArray_.push_back(errorResponseNodeMap);
}

}
