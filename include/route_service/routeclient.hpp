#ifndef ROUTECLIENT_HPP
#define ROUTECLIENT_HPP

#include <chrono>
#include <memory>
#include <string>
#include <utility>
#include <random>



#include "rclcpp/rclcpp.hpp"
#include "visibility_control.h"

#include "airdos_msgs/srv/route.hpp"

namespace route_service_client_composition
{


class RouteClient : public rclcpp::Node
{
    public:
        COMPOSITION_PUBLIC

        explicit RouteClient(const rclcpp::NodeOptions & node_options =rclcpp::NodeOptions());
        virtual ~RouteClient();

        airdos_msgs::msg::WaypointArray send_request(std::string, std::string);

    private:
        rclcpp::Client<airdos_msgs::srv::Route>::SharedPtr route_service_client_;
        airdos_msgs::msg::WaypointArray result_WP_array;
};

/*

RouteClient::RouteClient(const rclcpp::NodeOptions & node_options)
: Node("route_client",node_options)
{   
    using namespace std::chrono_literals;
    route_service_client_=this->create_client<RouteOperator>("route_operator");
    while(!route_service_client_->wait_for_service(1s)){
        if(!rclcpp::ok()){
            RCLCPP_ERROR(this->get_logger(),"Interrupted while waiting for the service");
            return;
        }
        RCLCPP_INFO(this->get_logger(),"Service not available... waiting...");
    }
}

RouteClient::~RouteClient()
{

}


void RouteClient::send_request(std::string _start, std::string _end){

    auto request = std::make_shared<RouteOperator::Request>();
    request->start=_start;
    request->end=_end;

    auto response_received_callback =[this](rclcpp::Client<RouteOperator>::SharedFuture future) {
        auto response=future.get();
        RCLCPP_INFO(this->get_logger(),"Receiced time: ",response->stamp);
        result_WP_array=response->route;
        
        for(auto & cur:result_WP_array.waypoints){
            std::cout<<cur.command<<"    lla:  "<<cur.lattitude<<"   "<<cur.longitude<<"   "<<cur.altitude<<"   "<<"param 1 2 3 4: "<<
                    cur.param1<<"   "<<cur.param2<<"   "<<cur.param3<<"   "<<cur.param4<<std::endl;
        }
        //return result_WP_array;
    };

    auto future_result=
        route_service_client_->async_send_request(request, response_received_callback);

}
*/

}













#endif