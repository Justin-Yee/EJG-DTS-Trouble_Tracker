# Generated by Boost 1.70.0

# address-model=32

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
  return()
endif()

# layout=versioned

# toolset=vc142

if(Boost_COMPILER AND NOT Boost_COMPILER STREQUAL "vc142")
  return()
endif()

if(BOOST_DETECTED_TOOLSET AND NOT BOOST_DETECTED_TOOLSET STREQUAL "vc142")
  return()
endif()

# link=static

if(NOT "${Boost_USE_STATIC_LIBS}" STREQUAL "" AND NOT Boost_USE_STATIC_LIBS)
  return()
endif()

if(BUILD_SHARED_LIBS AND NOT Boost_USE_STATIC_LIBS)
  return()
endif()

# runtime-link=shared

if(Boost_USE_STATIC_RUNTIME)
  return()
endif()

# runtime-debugging=on

if(NOT "${Boost_USE_DEBUG_RUNTIME}" STREQUAL "" AND NOT Boost_USE_DEBUG_RUNTIME)
  return()
endif()

# threading=multi

# variant=debug

if(NOT "${Boost_USE_DEBUG_LIBS}" STREQUAL "" AND NOT Boost_USE_DEBUG_LIBS)
  return()
endif()


set_property(TARGET Boost::graph_parallel APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(Boost::graph_parallel PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG CXX
  )

list(APPEND _BOOST_GRAPH_PARALLEL_DEPS headers)