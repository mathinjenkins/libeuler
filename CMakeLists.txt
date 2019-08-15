cmake_minimum_required(VERSION 3.5)
project(libeuler VERSION 1.0.0 LANGUAGES CXX)

list(INSERT CMAKE_MODULE_PATH 0 ${CMAKE_SOURCE_DIR}/cmake)

find_package(Exponent 1.0 REQUIRED)

add_library(euler
    src/euler.cpp
)

add_library(Euler::euler ALIAS euler)

target_include_directories(euler
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_features(euler PRIVATE cxx_auto_type)
target_compile_options(euler PRIVATE $<$<CXX_COMPILER_ID:GNU>:-Wall>)

target_link_libraries(euler
    PRIVATE
        Exponent::Exponent
)

include(GNUInstallDirs)
set(INSTALL_CONFIGDIR ${CMAKE_INSTALL_LIBDIR}/cmake/Euler)

install(TARGETS euler
    EXPORT euler-targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

set_target_properties(euler PROPERTIES EXPORT_NAME Euler)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT euler-targets
  FILE
    EulerTargets.cmake
  NAMESPACE
    Euler::
  DESTINATION
    ${INSTALL_CONFIGDIR}
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/EulerConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(${CMAKE_CURRENT_LIST_DIR}/cmake/EulerConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/EulerConfig.cmake
    INSTALL_DESTINATION ${INSTALL_CONFIGDIR}
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/EulerConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/EulerConfigVersion.cmake
    DESTINATION ${INSTALL_CONFIGDIR}
)

export(EXPORT euler-targets FILE ${CMAKE_CURRENT_BINARY_DIR}/EulerTargets.cmake NAMESPACE Euler::)

export(PACKAGE Euler)

add_subdirectory(test)