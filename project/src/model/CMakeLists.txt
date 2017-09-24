file(GLOB_RECURSE model_SRC
    "*.cpp"
)

file(GLOB_RECURSE model_H
"*.h"
)

add_library(lib_model ${model_SRC})

install(TARGETS lib_model DESTINATION lib)
install(FILES model_H DESTINATION include/project)
