add_library(Galaga_lib STATIC
    Nave.cpp
    Projectile.cpp)

target_link_libraries(Galaga_lib  "sfml-window" "sfml-system"  "sfml-main" "sfml-graphics")

target_include_directories(Galaga_lib PUBLIC
    ${CMAKE_SOURCE_DIR}/include)
