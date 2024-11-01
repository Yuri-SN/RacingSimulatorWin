project (Vehicles)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(Vehicles SHARED
    Vehicle.h
    Vehicle.cpp
#    Libs/SharedLib/VehicleResult.h
#    Libs/SharedLib/VehicleGround.h
#    Libs/SharedLib/VehicleGround.cpp
#    Libs/SharedLib/VehicleAir.h
#    Libs/SharedLib/VehicleAir.cpp
#    Libs/SharedLib/Ground/Camel.h
#    Libs/SharedLib/Ground/Camel.cpp
#    Libs/SharedLib/Ground/CamelSpeed.h
#    Libs/SharedLib/Ground/CamelSpeed.cpp
#    Libs/SharedLib/Ground/Centaur.h
#    Libs/SharedLib/Ground/Centaur.cpp
#    Libs/SharedLib/Ground/AllTerrainBoots.h
#    Libs/SharedLib/Ground/AllTerrainBoots.cpp
#    Libs/SharedLib/Air/FlyingCarpet.h
#    Libs/SharedLib/Air/FlyingCarpet.cpp
#    Libs/SharedLib/Air/Eagle.h
#    Libs/SharedLib/Air/Eagle.cpp
#    Libs/SharedLib/Air/Broomstick.h
#    Libs/SharedLib/Air/Broomstick.cpp
#    Libs/SharedLib/Race.h
#    Libs/SharedLib/Race.cpp
#    Libs/SharedLib/RaceType.h
)

target_include_directories(Vehicles PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
