#include "plugin.h"
#include "task.h"

int main(int argc, char *argv[]){

    //register
    iplugin::register_plugin_class<task::testA>("testA");
    iplugin::register_plugin_class<task::testB>("testB");

    //use
    iplugin::Plugin* objB = task::create_task_plugin("testB");
    std::cout << "we need testB: " << objB->who_am_i() << std::endl;

    iplugin::Plugin* objA = task::create_task_plugin("testA");
    std::cout << "we need testA: " << objA->who_am_i() << std::endl;

    //pointer is NULL
    iplugin::Plugin* objC = task::create_task_plugin("testC");
    if(NULL != objC){
        std::cout << "we need testC: " << objC->who_am_i() << std::endl;
    }
    return 0;
}
