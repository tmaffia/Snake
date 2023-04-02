# CMakeList.txt : CMake project for Snake, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.20)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Snake")

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

# Add source to this project's executable.
add_executable (Snake "src/snake/Snake.cpp" "src/snake/Snake.h" "src/snake/Game.h" "src/snake/Game.cpp")
target_link_libraries(Snake PRIVATE sfml-graphics)

if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET Snake POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:Snake> $<TARGET_FILE_DIR:Snake> COMMAND_EXPAND_LISTS)
endif()

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Snake PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
