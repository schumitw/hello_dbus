#include <iostream>
#include <variant>
#include <sdbusplus/bus.hpp>

int32_t oemInt;
bool oemBool;
std::string oemString;

void get_dbus()
{
    using Value = std::variant<int32_t, bool, std::string>;
    Value value;
    auto sdbus = sdbusplus::bus::new_default();
    auto m1 = sdbus.new_method_call("xyz.openbmc_project.hello_dbus", "/xyz/openbmc_project/hello_dbus/custom", "org.freedesktop.DBus.Properties", "Get");
    m1.append("xyz.openbmc_project.hello_dbus.custom.Example", "OemInt");
    auto reply = sdbus.call(m1);
    reply.read(value);
    oemInt = std::get<int32_t>(value);

	auto m2 = sdbus.new_method_call("xyz.openbmc_project.hello_dbus", "/xyz/openbmc_project/hello_dbus/custom", "org.freedesktop.DBus.Properties", "Get");
    m2.append("xyz.openbmc_project.hello_dbus.custom.Example", "OemBoolean");
	reply = sdbus.call(m2);
	reply.read(value);
	oemBool = std::get<bool>(value);

	auto m3 = sdbus.new_method_call("xyz.openbmc_project.hello_dbus", "/xyz/openbmc_project/hello_dbus/custom", "org.freedesktop.DBus.Properties", "Get");
    m3.append("xyz.openbmc_project.hello_dbus.custom.Example", "OemString");
	reply = sdbus.call(m3);
	reply.read(value);
	oemString = std::get<std::string>(value);

    std::cout<<"OemInt: "<<oemInt<<std::endl;
	if (oemBool == 0)
    	std::cout<<"OemBoolean: False"<<std::endl;
	else
    	std::cout<<"OemBoolean: True"<<std::endl;
    std::cout<<"OemString: "<<oemString<<std::endl;
}

void set_dbus()
{
    using Value = std::variant<int32_t, bool, std::string>;
    Value value = ++oemInt;
    auto sdbus = sdbusplus::bus::new_default();
    auto m1 = sdbus.new_method_call("xyz.openbmc_project.hello_dbus", "/xyz/openbmc_project/hello_dbus/custom", "org.freedesktop.DBus.Properties", "Set");
    m1.append("xyz.openbmc_project.hello_dbus.custom.Example", "OemInt", value);
    auto reply = sdbus.call(m1);

	
	value = !oemBool;
	auto m2 = sdbus.new_method_call("xyz.openbmc_project.hello_dbus", "/xyz/openbmc_project/hello_dbus/custom", "org.freedesktop.DBus.Properties", "Set");
    m2.append("xyz.openbmc_project.hello_dbus.custom.Example", "OemBoolean", value);
    reply = sdbus.call(m2);

	value = "hello_dbus_client_"+std::to_string(oemInt);
	auto m3 = sdbus.new_method_call("xyz.openbmc_project.hello_dbus", "/xyz/openbmc_project/hello_dbus/custom", "org.freedesktop.DBus.Properties", "Set");
    m3.append("xyz.openbmc_project.hello_dbus.custom.Example", "OemString", value);
    reply = sdbus.call(m3);
}

int main(int argc, char**)
{
	std::cout<<"Reading D-Bus... "<<std::endl;
	get_dbus();
	std::cout<<std::endl<<"Writing D-Bus... "<<std::endl<<std::endl;
	set_dbus();
	std::cout<<"Reading D-Bus... "<<std::endl;
	get_dbus();
	return 0;
}

