file(GLOB_RECURSE control_SRC
    "*.cpp"
)

add_library(lib_control ${control_SRC})
