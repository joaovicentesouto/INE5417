file(GLOB_RECURSE control_SRC
    "*.cpp"
)

file(GLOB_RECURSE control_H
    "*.h"
)

add_library(lib_control ${control_SRC})

install(TARGETS lib_control DESTINATION lib)
install(FILES control_H DESTINATION include/project)
