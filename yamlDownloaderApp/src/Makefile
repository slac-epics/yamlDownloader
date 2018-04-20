TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================
DBD         += yamlDownloader.dbd
LIBRARY_IOC += yamlDownloader
LIB_SRCS    += drvYamlDownloader.cpp

# =================================================
# Need to link these external libraries statically
# =================================================
USR_INCLUDES    = $(addprefix -I,$(BOOST_INCLUDE) $(CPSW_FRAMEWORK_INCLUDE) $(YAML_INCLUDE) $(YAMLREADER_INCLUDE) $(DEVICELIB_INCLUDE))

deviceLib_DIR   = $(DEVICELIB_LIB)
cpsw_DIR        = $(CPSW_FRAMEWORK_LIB)
yaml-cpp_DIR    = $(YAML_LIB)
yamlReader_DIR  = $(YAMLREADER_LIB)
USR_LIBS_Linux += deviceLib cpsw yaml-cpp yamlReader

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE
