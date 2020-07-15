BUILT_SOURCES = \
	xyz/openbmc_project/hello_dbus/custom/Example/server.cpp \
	xyz/openbmc_project/hello_dbus/custom/Example/server.hpp \
    xyz/openbmc_project/hello_dbus/custom/Example/error.cpp \
    xyz/openbmc_project/hello_dbus/custom/Example/error.hpp


bin_PROGRAMS = hello_dbus
hello_dbus_SOURCES = \
				dbus_example.cpp \
				xyz/openbmc_project/hello_dbus/custom/Example/server.cpp \
				main.cpp \
                xyz/openbmc_project/hello_dbus/custom/Example/error.cpp


hello_dbus_LDFLAGS = $(SYSTEMD_LIBS) $(SDBUSPLUS_LIBS) \
                                 $(PHOSPHOR_DBUS_INTERFACES_LIBS)
hello_dbus_CFLAGS =  $(SYSTEMD_CFLAGS) $(SDBUSPLUS_CFLAGS) \
                                 $(PHOSPHOR_DBUS_INTERFACES_CFLAGS)

bin_PROGRAMS += hello_dbus_client

hello_dbus_client_SOURCES = client.cpp
hello_dbus_client_LDFLAGS = $(SDBUSPLUS_LIBS)
hello_dbus_client_CFLAGS = $(SDBUSPLUS_CFLAGS)

xyz/openbmc_project/hello_dbus/custom/Example/server.cpp: xyz/openbmc_project/hello_dbus/custom/Example.interface.yaml xyz/openbmc_project/hello_dbus/custom/Example/server.hpp
	@mkdir -p `dirname $@`
	$(SDBUSPLUSPLUS) -r $(srcdir) interface server-cpp xyz.openbmc_project.hello_dbus.custom.Example > $@

xyz/openbmc_project/hello_dbus/custom/Example/server.hpp: xyz/openbmc_project/hello_dbus/custom/Example.interface.yaml
	@mkdir -p `dirname $@`
	$(SDBUSPLUSPLUS) -r $(srcdir) interface server-header xyz.openbmc_project.hello_dbus.custom.Example > $@

xyz/openbmc_project/hello_dbus/custom/Example/error.cpp: xyz/openbmc_project/hello_dbus/custom/Example.errors.yaml xyz/openbmc_project/hello_dbus/custom/Example/error.hpp
	@mkdir -p `dirname $@`
	$(SDBUSPLUSPLUS) -r $(srcdir) error exception-cpp xyz.openbmc_project.hello_dbus.custom.Example > $@

xyz/openbmc_project/hello_dbus/custom/Example/error.hpp: xyz/openbmc_project/hello_dbus/custom/Example.errors.yaml
	@mkdir -p `dirname $@`
	$(SDBUSPLUSPLUS) -r $(srcdir) error exception-header xyz.openbmc_project.hello_dbus.custom.Example > $@
