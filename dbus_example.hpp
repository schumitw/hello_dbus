#pragma once

#include <sdbusplus/server.hpp>
#include "xyz/openbmc_project/vertiv/custom/Example/server.hpp"

namespace phosphor
{
namespace custom
{

using ExampleIface = sdbusplus::server::object::object<
    sdbusplus::xyz::openbmc_project::vertiv::custom::server::Example>;

/** @class Example
 *  @brief Example implementation.
 *  @details A concrete implementation for the
 *  xyz.openbmc_project.vertiv.custom.Example DBus API.
 */
class Example : public ExampleIface
{
    public:
        
        /** @brief Constructor to put object onto bus at a dbus path.
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         */
        Example(sdbusplus::bus::bus& bus, const char* objPath) :
                ExampleIface(bus, objPath) {};

        /** @brief sd_bus Write method implementation callback.
         * @param[in] writeId - The integer that was sent.
         * @param[in] writeStr - The string that was sent.
         */
        void write(int32_t id, std::string str) override;

        /** @brief Implementation for Clear
         *  Reset the NumWrite property to zero.
         */
        void clear() override;

};

} // namespace custom
} // namespace phosphor
