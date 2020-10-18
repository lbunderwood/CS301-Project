cmake_minimum_required(VERSION 3.0.0)
project(InventoryAndShop VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(InventoryAndShop main.cpp functions.obj AsmInclusions.h 
    Items/Item.h
    Items/Item.cpp
    Items/Effect.h
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
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
