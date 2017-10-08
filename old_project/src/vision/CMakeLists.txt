file(GLOB_RECURSE vision_SRC
    "*.cpp"
)

add_library(lib_visual ${vision_SRC})
