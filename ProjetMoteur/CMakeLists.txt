cmake_minimum_required(VERSION 3.8)
project(ProjetMoteur)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/MatrixC.cpp src/MatrixC.h src/Vector.cpp src/Vector.h src/Vector3f.cpp src/Vector3f.h src/Vector4f.cpp src/Vector4f.h src/MatrixC3.cpp src/MatrixC3.h src/MatrixC4.cpp src/MatrixC4.h src/CoordSpherique.cpp src/CoordSpherique.h src/Quaternion.cpp src/Quaternion.h src/AngleEuler.cpp src/AngleEuler.h src/openglFunction.cpp src/openglFunction.h src/ObjectRender.cpp src/ObjectRender.h src/RectangularPrism.cpp src/RectangularPrism.h src/Cylinder.cpp src/Cylinder.h src/CoordinateSystem.cpp src/CoordinateSystem.h src/Sphere.cpp src/Sphere.h src/complexSurface.cpp src/complexSurface.h src/Triangle.cpp src/Triangle.h src/Plan.cpp src/Plan.h src/Light.cpp src/Light.h src/interfaceCreationObjet.cpp src/interfaceCreationObjet.h)
add_executable(ProjetMoteur ${SOURCE_FILES})

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARY})