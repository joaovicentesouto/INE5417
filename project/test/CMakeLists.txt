file(GLOB_RECURSE virtual_wallet_run_tests_SRC
    "*.cpp"
)

add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE .)

add_executable(run_tests ${virtual_wallet_run_tests_SRC})
target_link_libraries(run_tests PUBLIC
    Catch
    lib_control
    lib_model
    lib_visual
)
