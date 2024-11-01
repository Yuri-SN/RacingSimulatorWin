# CMakeList.txt: проект CMake для App; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

project(App)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (App "main.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET App PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.

target_link_libraries(App PRIVATE Vehicles)
