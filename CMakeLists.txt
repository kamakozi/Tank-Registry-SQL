cmake_minimum_required(VERSION 3.31)
project(TankPorject)

set(CMAKE_CXX_STANDARD 17)

find_package(PkgConfig REQUIRED)
pkg_check_modules(PQXX REQUIRED libpqxx)

include_directories(${PQXX_INCLUDE_DIRS})
link_directories(${PQXX_LIBRARY_DIRS})

add_executable(TankPorject main.cpp
        TankManager/TankManager.cpp
        TankManager/TankManager.h
        TankManager/Entities/Tank/Tank.cpp
        TankManager/Entities/Tank/Tank.h
        TankManager/DbConnection/DbConnection.h
        TankManager/Services/CreateNewTank/CreateNewTank.cpp
        TankManager/Services/CreateNewTank/CreateNewTank.h
        TankManager/Services/CreateNewTank/CreateName/CreateName.cpp
        TankManager/Services/CreateNewTank/CreateName/CreateName.h
        TankManager/Services/CreateNewTank/CreateCreationYear/CreateCreationYear.cpp
        TankManager/Services/CreateNewTank/CreateCreationYear/CreateCreationYear.h
        TankManager/Services/CreateNewTank/SelectCountry/SelectCountry.cpp
        TankManager/Services/CreateNewTank/SelectCountry/SelectCountry.h
        TankManager/Entities/CreateTables/CreateTank/CreateTankTable.cpp
        TankManager/Entities/CreateTables/CreateTank/CreateTankTable.h
        TankManager/Entities/CreateTables/CreateCountryTable/CreateCountryTable.cpp
        TankManager/Entities/CreateTables/CreateCountryTable/CreateCountryTable.h
        TankManager/Entities/CreateTables/CreateCreationYearTable/CreateCreationYearTable.cpp
        TankManager/Entities/CreateTables/CreateCreationYearTable/CreateCreationYearTable.h
        TankManager/Services/PrintTanksManager/PrintTanksManager.cpp
        TankManager/Services/PrintTanksManager/PrintTanksManager.h
        TankManager/Services/PrintTanksManager/PrintFromVector/PrintFromVector.cpp
        TankManager/Services/PrintTanksManager/PrintFromVector/PrintFromVector.h
        TankManager/Services/PrintTanksManager/PrintFromDatabase/PrintFromDatabase.cpp
        TankManager/Services/PrintTanksManager/PrintFromDatabase/PrintFromDatabase.h
        TankManager/Services/PrintTanksManager/PrintFromDatabase/PrintFromCountry/PrintFromCountry.cpp
        TankManager/Services/PrintTanksManager/PrintFromDatabase/PrintFromCountry/PrintFromCountry.h
)

target_link_libraries(TankPorject ${PQXX_LIBRARIES})
