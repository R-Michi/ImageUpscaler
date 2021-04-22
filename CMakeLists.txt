# requiered CMAKE version to build the project
cmake_minimum_required (VERSION 3.8)

# current project
project("ImageUpscaler")

set(${CMAKE_CXX_STANDARD}, 17)

include_directories("C:/OpenCV/opencv/build/include"
					"${CMAKE_CURRENT_SOURCE_DIR}/lib/opencv_modules/dnn_superres/include")

link_directories("C:/OpenCV/opencv/build/x64/vc15/lib")

add_library(opencv_modules "${CMAKE_CURRENT_SOURCE_DIR}/lib/opencv_modules/dnn_superres/src/dnn_superres.cpp" "ImageUpscaler.cpp")

add_executable(image_upscaler "main.cpp" "ImageUpscaler.cpp")
target_link_libraries(image_upscaler PRIVATE opencv_modules "-lopencv_world452")

# additional work
set(CMAKE_EXPORT_COMPILE_COMMANDS on)
