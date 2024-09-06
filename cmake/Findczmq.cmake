include(FindPkgConfig)
PKG_CHECK_MODULES(PC_CZMQ "libczmq")

find_path(
        CZMQ_INCLUDE_DIRS
        NAMES czmq.h
        HINTS ${PC_CZMQ_INCLUDE_DIRS}
)

find_library(
        CZMQ_LIBRARIES
        NAMES czmq
        HINTS ${PC_CZMQ_LIBRARY_DIRS}
)

include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(CZMQ DEFAULT_MSG CZMQ_LIBRARIES CZMQ_INCLUDE_DIRS)
mark_as_advanced(CZMQ_LIBRARIES CZMQ_INCLUDE_DIRS)
