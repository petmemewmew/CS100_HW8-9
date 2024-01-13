cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME "Dawnbreaker")
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/bin")

#SET(FREEGLUT_REPLACE_GLUT ON CACHE BOOL "" FORCE)

IF (APPLE)
    add_definitions(-DGL_SILENCE_DEPRECATION)
ENDIF ()

add_subdirectory(
        "${CMAKE_CURRENT_LIST_DIR}/third_party/SOIL/"
        "${CMAKE_CURRENT_BINARY_DIR}/SOIL"
        EXCLUDE_FROM_ALL
)

IF (APPLE)
ELSE ()
    add_subdirectory(
            "${CMAKE_CURRENT_LIST_DIR}/third_party/freeglut/"
            "${CMAKE_CURRENT_BINARY_DIR}/freeglut"
            EXCLUDE_FROM_ALL
    )
    set(FREEGLUT_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/third_party/freeglut/include")
ENDIF ()


add_library(
        ProvidedFramework
        STATIC
        src/ProvidedFramework/ObjectBase.h
        src/ProvidedFramework/ObjectBase.cpp
        src/ProvidedFramework/WorldBase.h
        src/ProvidedFramework/WorldBase.cpp
        src/ProvidedFramework/GameManager.h
        src/ProvidedFramework/GameManager.cpp
        src/ProvidedFramework/SpriteManager.h
        src/ProvidedFramework/SpriteManager.cpp
        src/utils.h
)

IF (APPLE)
    target_link_libraries(
            ProvidedFramework
            SOIL
            "-framework OpenGL"
            "-framework Cocoa"
            "-framework IOKit"
            "-framework CoreVideo"
            "-framework GLUT"
    )

    target_include_directories(
            ProvidedFramework
            PUBLIC
            src/
            src/ProvidedFramework/
    )
ELSE ()
    target_link_libraries(
            ProvidedFramework
            freeglut
            SOIL
    )

    target_include_directories(
            ProvidedFramework
            PUBLIC
            ${FREEGLUT_INCLUDE_DIR}
            src/
            src/ProvidedFramework/
    )
ENDIF ()

add_library(
        PartForYou
        STATIC
        src/PartForYou/GameWorld.h
        src/PartForYou/GameWorld.cpp
        src/PartForYou/GameObjects.h
        src/PartForYou/GameObjects.cpp
        src/utils.h
)

target_link_libraries(
        PartForYou
        ProvidedFramework
)

target_include_directories(
        PartForYou
        PUBLIC
        src/
        src/ProvidedFramework/
        src/PartForYou/
)

add_library(
        Explosion
        STATIC
        src/PartForYou/Explosion.h
        src/PartForYou/Explosion.cpp
)

target_link_libraries(
        PartForYou
        ProvidedFramework
        Explosion
)

target_include_directories(
        Explosion
        PUBLIC
        src/
        src/ProvidedFramework/
        src/PartForYou/
)

add_library(
        Meteor
        STATIC
        src/PartForYou/Meteor.cpp
        src/PartForYou/Meteor.h
)

target_link_libraries(
        PartForYou
        ProvidedFramework
        Meteor
)

target_include_directories(
        Meteor
        PUBLIC
        src/
        src/ProvidedFramework/
        src/PartForYou/
)

add_library(
        Star
        STATIC
        src/PartForYou/Star.cpp
        src/PartForYou/Star.h
)

target_link_libraries(
        PartForYou
        ProvidedFramework
        Star
)

target_include_directories(
        Star
        PUBLIC
        src/
        src/ProvidedFramework/
        src/PartForYou/

)

add_library(
        Player
        STATIC
        src/PartForYou/Dawnbreaker.cpp
        src/PartForYou/Dawnbreaker.h
)
target_link_libraries(
        Player
        PartForYou
        ProvidedFramework
        BlueBullet
        Meteor
)

target_include_directories(
        Player
        PUBLIC
        src/
        src/ProvidedFramework/
        src/PartForYou/
)


add_library(
        Enemy
        STATIC
        src/PartForYou/Alphatron.h
        src/PartForYou/Alphatron.cpp
        src/PartForYou/Enemy.cpp
        src/PartForYou/Enemy.h
        src/PartForYou/Sigmatron.cpp
        src/PartForYou/Sigmatron.h
        src/PartForYou/Omegatron.cpp
        src/PartForYou/Omegatron.h
)

target_link_libraries(
        Enemy
        PartForYou
        ProvidedFramework
        Goodie
        RedBullet
        Explosion
)

target_include_directories(
        Enemy
        PUBLIC
        src/
        src/ProvidedFramework/
        src/PartForYou/
)

add_library(
        BlueBullet
        STATIC
        src/PartForYou/Blue_Bullet.h
        src/PartForYou/Blue_Bullet.cpp
        src/PartForYou/Red_Bullet.cpp
)
target_link_libraries(
        PartForYou
        ProvidedFramework
        BlueBullet
)

target_include_directories(
        BlueBullet
        PUBLIC
        src/
        src/ProvidedFramework/
        src/PartForYou/
)

add_library(
        RedBullet
        STATIC
        src/PartForYou/Red_Bullet.h
        src/PartForYou/Red_Bullet.cpp
)
target_link_libraries(
        PartForYou
        ProvidedFramework
        RedBullet
)

target_include_directories(
        RedBullet
        PUBLIC
        src/
        src/ProvidedFramework/
        src/PartForYou/
)


add_library(
        Goodie
        STATIC
        src/PartForYou/Meteor_Goodie.h
        src/PartForYou/Meteor_Goodie.cpp
        src/PartForYou/Power_Up_Goodie.cpp
        src/PartForYou/Power_Up_Goodie.h
        src/PartForYou/HP_Restore_Goodie.h
        src/PartForYou/HP_Restore_Goodie.cpp
        src/PartForYou/Goodie.cpp
        src/PartForYou/Goodie.h
)

target_link_libraries(
        PartForYou
        ProvidedFramework
        Goodie
)

target_include_directories(
        Goodie
        PUBLIC
        src/
        src/ProvidedFramework/
        src/PartForYou/
)


add_executable(
        ${PROJECT_NAME}
        src/main.cpp
)

target_link_libraries(
        ${PROJECT_NAME}
        ProvidedFramework
        PartForYou
        BlueBullet
        Explosion
        Enemy
        Player
        RedBullet
        Meteor
        Star
)

target_include_directories(
        ${PROJECT_NAME}
        PUBLIC
        src/
        src/ProvidedFramework/
        src/PartForYou/
)
