add_library(Galaga_lib STATIC
    Nave.cpp
    Projectile.cpp)

target_include_directories(Galaga_lib PUBLIC
    ${CMAKE_SOURCE_DIR}/include)
