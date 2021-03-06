cmake_minimum_required(VERSION 3.14)
project(InventoryAndShop VERSION 0.1.0)
enable_language(C ASM_NASM)

include(CTest)
enable_testing()

include(CheckPIESupported)
check_pie_supported()

add_executable(InventoryAndShop
    main.cpp 
    functions.o
    mainMenu.o
    AsmInclusions.h 
    GlobalUI.h
    GlobalUI.cpp
    Items/Item.h
    Items/Item.cpp
    Items/Effect.h
    Items/Effect.cpp
    Items/Armor.h
    Items/Armor.cpp
    Items/Weapon.cpp
    Items/Weapon.h
    Items/Potion.h
    Items/Potion.cpp
    Inventories/Inventory.cpp
    Inventories/Inventory.h
    Inventories/Player.h
    Inventories/Player.cpp
    Inventories/Shop.h
    Inventories/Shop.cpp
    Inventories/Lootable.h
    Inventories/Lootable.cpp
)

set_property(TARGET InventoryAndShop PROPERTY POSITION_INDEPENDENT_CODE FALSE)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
