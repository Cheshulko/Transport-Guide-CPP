//
//  OptimalRouteResponseData.hpp
//  transportnyi-spravochnik
//
//  Created by Mykyta Cheshulko on 12.07.2020.
//  Copyright © 2020 Mykyta Cheshulko. All rights reserved.
//

#ifndef OptimalRouteResponseData_hpp
#define OptimalRouteResponseData_hpp

#include <cstddef>
#include <string>
#include <optional>
#include <vector>
#include <memory>

namespace guide::interaction::response::data {

class OptimalRouteResponseData
{
public:
    class Item
    {
    public:
        enum class Type
        {
            Wait,
            Bus
        };
        
        virtual Type GetType() const = 0;
        virtual double GetTime() const = 0;
        virtual const std::string& GetName() const = 0;
        virtual size_t GetCount() const = 0;
    };
    
    class WaitItem: public Item
    {
    public:
        WaitItem(double time, const std::string& name, size_t count);
        
        virtual Type GetType() const override;
        virtual double GetTime() const override;
        virtual const std::string& GetName() const override;
        virtual size_t GetCount() const override;
        
    private:
        Type type_;
        double time_;
        std::string name_;
        size_t count_;
    };
    
    class BusItem: public Item
    {
    public:
        BusItem(double time, const std::string& name, size_t count);
        
        virtual Type GetType() const override;
        virtual double GetTime() const override;
        virtual const std::string& GetName() const override;
        virtual size_t GetCount() const override;
        
    private:
        Type type_;
        double time_;
        std::string name_;
        size_t count_;
    };
    
public:
    explicit OptimalRouteResponseData(std::optional<size_t> id = std::nullopt);
    
    void AddItem(std::shared_ptr<Item> item);
    
    double GetTime() const;
    const std::vector<std::shared_ptr<Item>>& GetItems() const;
    std::optional<size_t> GetRequestId() const;
    
private:
    std::optional<size_t> id_;
    std::vector<std::shared_ptr<Item>> items_;
    double time_;
};

}

#endif /* OptimalRouteResponseData_hpp */
