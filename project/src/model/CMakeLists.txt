file(GLOB_RECURSE model_SRC
    "*.cpp"
)

add_library(lib_model ${model_SRC})
