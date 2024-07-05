# CMakeList.txt : CMake project for simulator, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("simulator")

# Add source to this project's executable.
add_library (simulator base_instrument.h 
                          csv_reader.h csv_reader.cc 
                          exchange.h exchange.cc
                          inverse_instrument.h inverse_instrument.cc
                          order.h position.h position.cc 
                          strategy.cc doctest.h strategy.h
                          orderbook.h orderbook.cc
                          signal_builder.h signal_builder.cc)

add_executable(test_sim testcases.cc)

target_link_libraries(test_sim PRIVATE simulator)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET simulator PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
