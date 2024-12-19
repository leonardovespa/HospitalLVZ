# Requerir una versión mínima de CMake
cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(HospitalLVZ LANGUAGES CXX)

# Configurar el estándar de C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Especificar los archivos fuente del proyecto
add_executable(HospitalLVZ
    main.cpp
    Paciente.cpp
    Medico.cpp
    Cita.cpp
    Reporte.cpp
    BBDD.cpp
)

# Incluir el directorio actual para los headers
include_directories(${CMAKE_SOURCE_DIR})
