#include "ros/ros.h"
#include "std_msgs/String.h"
#include <string>
#include <iostream>
#include "../../../devel/include/dino_package/dino_service.h"

using namespace std;
using namespace std_msgs;
using namespace ros;

int main(int argc, char **argv)
{
    init(argc, argv, "publisher");
    NodeHandle handler;
    ServiceClient dino_client = handler.serviceClient<dino_package::dino_service>("dino_service");
    dino_package::dino_service srv;
    string dino_begin;
    while(ok())
    {
        ROS_INFO("\n===================DINO GENERATOR===================");
        cout << "Enter your word: ";
        cin >> dino_begin;
        srv.request.dino_begin = dino_begin;
        if(dino_client.call(srv))
        {
            cout << srv.response.full_dino << endl;
        }
        else
        {
            cout << "You have problems with connection with dino_server!" << endl;
            return -1;
        }
    }
    return 0;
}


