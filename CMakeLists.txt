# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.12)

project (RacingSimulator)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
	cmake_policy(SET CMP0141 NEW)
	set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

if(MSVC)
	add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
	add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
endif()

add_library(SharedLib SHARED
	SharedLib/Vehicle.h
    SharedLib/Vehicle.cpp
    SharedLib/VehicleResult.h
    SharedLib/VehicleGround.h
    SharedLib/VehicleGround.cpp
    SharedLib/VehicleAir.h
    SharedLib/VehicleAir.cpp
    SharedLib/Ground/Camel.h
    SharedLib/Ground/Camel.cpp
    SharedLib/Ground/CamelSpeed.h
    SharedLib/Ground/CamelSpeed.cpp
    SharedLib/Ground/Centaur.h
    SharedLib/Ground/Centaur.cpp
    SharedLib/Ground/AllTerrainBoots.h
    SharedLib/Ground/AllTerrainBoots.cpp
    SharedLib/Air/FlyingCarpet.h
    SharedLib/Air/FlyingCarpet.cpp
    SharedLib/Air/Eagle.h
    SharedLib/Air/Eagle.cpp
    SharedLib/Air/Broomstick.h
    SharedLib/Air/Broomstick.cpp
    SharedLib/Race.h
    SharedLib/Race.cpp
    SharedLib/RaceType.h
)

add_executable(RacingSimulator main.cpp)

target_link_libraries(RacingSimulator SharedLib)
