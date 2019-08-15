#include <iostream>
#include "dbus_example.hpp"


namespace phosphor
{
namespace custom
{

void Example::write(int32_t id, std::string str)
{
	//fprintf(stderr,"hello_dbus: Integer = %d, Message = %s\n", id, str.c_str());
    auto num = numWrite();

    lastInt(id);
    lastStr(str);
    numWrite(++num);
    
}

void Example::clear()
{
    // Clear numWrite, broadcast 'Cleared' signal
    auto num = numWrite();
    lastInt(0);
    lastStr("");
    numWrite(0);
    cleared(num);
}

} // namespace custom
} // namespace phosphor
