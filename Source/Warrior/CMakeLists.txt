# cmake_minimum_required(VERSION <specify CMake version here>)
project(Warrior)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Public)
include_directories(Public/Characters)
include_directories(Public/GameModes)

add_executable(Warrior
        Private/Characters/WarriorBaseCharacter.cpp
        Private/GameModes/WarriorGameModeBase.cpp
        Public/Characters/WarriorBaseCharacter.h
        Public/GameModes/WarriorGameModeBase.h
        Warrior.cpp
        Warrior.h
        WarriorCharacter.cpp
        WarriorCharacter.h
        WarriorGameMode.cpp
        WarriorGameMode.h)
