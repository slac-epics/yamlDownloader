# yamlDownloader dependencies

## Overview

This module downloads the YAML tarball storaged in the FPGA's PROM. The tarball is written and untared
to an specific destination folder. Then, it can be loaded, for example, using the yamlLoader module.

This document describes what external packages and modules are reuired and how to configure them into
your IOC.

## Dependencies

This module depends on the following external packages:
- yamlReader
- CPSW, framework
- CPSW, device library
- BOOST
- YAML-CPP

No EPICS modules is required.

## Dependencies configuration

In order to use this module you need to add the following definitions into your IOC application,
(using the right versions for your particular case):

### configure/CONFIG_SITE

```
# CPSW framework
CPSW_FRAMEWORK_PACKAGE_NAME=cpsw/framework
CPSW_FRAMEWORK_VERSION=R3.6.3
CPSW_FRAMEWORK_TOP=$(PACKAGE_SITE_TOP)/$(CPSW_FRAMEWORK_PACKAGE_NAME)/$(CPSW_FRAMEWORK_VERSION)
CPSW_FRAMEWORK_LIB = $(CPSW_FRAMEWORK_TOP)/$(PKG_ARCH)/lib
CPSW_FRAMEWORK_INCLUDE = $(CPSW_FRAMEWORK_TOP)/$(PKG_ARCH)/include

# YAML-CPP
YAML_PACKAGE_NAME=yaml-cpp
YAML_VERSION=yaml-cpp-0.5.3
YAML_TOP=$(PACKAGE_SITE_TOP)/$(YAML_PACKAGE_NAME)/$(YAML_VERSION)
YAML_LIB= $(YAML_TOP)/$(PKG_ARCH)/lib
YAML_INCLUDE=$(YAML_TOP)/$(PKG_ARCH)/include

# BOOST
BOOST_PACKAGE_NAME=boost
BOOST_VERSION=1.63.0
BOOST_TOP=$(PACKAGE_SITE_TOP)/$(BOOST_PACKAGE_NAME)/$(BOOST_VERSION)
BOOST_LIB = $(BOOST_TOP)/$(PKG_ARCH)/lib
BOOST_INCLUDE = $(BOOST_TOP)/$(PKG_ARCH)/include

# YamlReader
YAMLREADER_PACKAGE_NAME     = cpsw/yamlReader
YAMLREADER_VERSION          = yamlReader.git
YAMLREADER_TOP              = $(PACKAGE_SITE_TOP)/$(YAMLREADER_PACKAGE_NAME)/$(YAMLREADER_VERSION)
YAMLREADER_LIB              = $(YAMLREADER_TOP)/$(PKG_ARCH)/lib
YAMLREADER_INCLUDE          = $(YAMLREADER_TOP)/$(PKG_ARCH)/include

# CPSW Device Library
DEVICELIB_PACKAGE_NAME     = cpsw/deviceLibrary
DEVICELIB_VERSION          = R1.0.0
DEVICELIB_TOP              = $(PACKAGE_SITE_TOP)/$(DEVICELIB_PACKAGE_NAME)/$(DEVICELIB_VERSION)
DEVICELIB_LIB              = $(DEVICELIB_TOP)/$(PKG_ARCH)/lib
DEVICELIB_INCLUDE          = $(DEVICELIB_TOP)/$(PKG_ARCH)/include

```

### configure/CONFIG_SITE.Common.linuxRT-x86_64

```
PKG_ARCH=$(LINUXRT_BUILDROOT_VERSION)-x86_64
```

### configure/CONFIG_SITE.Common.rhel6-x86_64

```
PKG_ARCH=$(LINUX_VERSION)-x86_64
```

### configure/RELEASE

```
YAMLDOWNLOADER_MODULE_VERSION=R1.0.0

YAMLDOWNLOADER=$(EPICS_MODULES)/yamlDownloader/$(YAMLDOWNLOADER_MODULE_VERSION)
```

### xxxApp/src/Makefile

```
# =====================================================
# Path to "NON EPICS" External PACKAGES: USER INCLUDES
# =====================================================
USR_INCLUDES = $(addprefix -I,$(BOOST_INCLUDE) $(CPSW_FRAMEWORK_INCLUDE) $(YAML_INCLUDE) $(YAMLREADER_INCLUDE) $(DEVICELIB_INCLUDE))
# =====================================================

# ======================================================
#PATH TO "NON EPICS" EXTERNAL PACKAGES: USER LIBRARIES
# ======================================================
deviceLib_DIR = $(DEVICELIB_LIB)
cpsw_DIR = $(CPSW_FRAMEWORK_LIB)
boost_system_DIR = $(BOOST_LIB)
yaml-cpp_DIR = $(YAML_LIB)
yamlReader_DIR  = $(YAMLREADER_LIB)
# ======================================================

# ======================================================
# LINK "NON EPICS" EXTERNAL PACKAGE LIBRARIES STATICALLY
# ======================================================
USR_LIBS_Linux += yamlReader deviceLib cpsw boost_system yaml-cpp
# ======================================================

# yamlDownloader DBD
xxx_DBD += yamlDownloader.dbd

# =====================================================
# Link in the libraries from other EPICS modules
# =====================================================
xxx_LIBS += yamlDownloader
```