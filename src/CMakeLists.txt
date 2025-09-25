set(OPENPIGEONQT_SOURCES
    main.cpp
    system/ftp_client.cpp
)

add_executable(openpigeonqt ${OPENPIGEONQT_SOURCES})

# Include folder
target_include_directories(openpigeonqt
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

# Build folder
set_target_properties(openpigeonqt PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}
)

if(MSVC)
    target_compile_options(openpigeonqt PRIVATE /W4 /permissive-)
else()
    target_compile_options(openpigeonqt PRIVATE -Wall -Wextra -Wpedantic)
endif()

if(WIN32)
    target_link_libraries(openpigeonqt PRIVATE ws2_32)
endif()