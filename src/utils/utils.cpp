#include <iostream>
#include "utils.h"

using namespace std;

int utils::checkOS()
{
    {
        int no_os_flag=1;

#ifdef linux

        no_os_flag=0;

       cout<<"It is in Linux OS!"<<endl;

#endif

#ifdef _UNIX

        no_os_flag=0;

       cout<<"It is in UNIX OS!"<<endl;

#endif

#ifdef __WINDOWS_

        no_os_flag=0;

       cout<<"It is in Windows OS!"<<endl;

#endif

#ifdef _WIN32

        no_os_flag=0;

       cout<<"It is in WIN32 OS!"<<endl;

#endif

#ifdef __APPLE__

        no_os_flag=0;

       cout<<"It is in MAC OS!"<<endl;

#endif


#ifdef _WIN64

        no_os_flag=0;

       cout<<"It is in WIN64 OS!"<<endl;

#endif

        if(no_os_flag == 1){

            std::cout <<"No OS Defined ,I do not know what the os is!"<< std::endl;

        }
        return 0;
    }
}
