#include <iostream>
#include <sdbusplus/server.hpp>
#include "config.h"
#include "xyz/openbmc_project/vertiv/custom/Example/server.hpp"
#include "dbus_example.hpp"

int main(int argc, char**)
{
    auto bus = sdbusplus::bus::new_default();

    // Add sdbusplus ObjectManager.
    sdbusplus::server::manager::manager objExample(bus, BMC_OBJPATH);

    phosphor::custom::Example example(bus,
                                        BMC_OBJPATH);

    bus.request_name(BMC_BUSNAME);

    while(true)
    {
        bus.process_discard();
        bus.wait();
    }

    exit(EXIT_SUCCESS);

}
