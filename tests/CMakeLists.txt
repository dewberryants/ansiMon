add_executable(test_maps
    test_maps.cpp
    "${PROJECT_SOURCE_DIR}/src/data.cpp"
)

target_link_libraries(test_maps
    GTest::gtest_main
)

target_include_directories(test_maps PRIVATE
    "${PROJECT_SOURCE_DIR}/include"
)

add_executable(test_ui
    test_ui.cpp
    "${PROJECT_SOURCE_DIR}/src/ui.cpp"
)

target_link_libraries(test_ui
    GTest::gtest_main
    ftxui::component
)

target_include_directories(test_ui PRIVATE
    "${PROJECT_SOURCE_DIR}/include"
)

include(GoogleTest)

gtest_discover_tests(test_maps)

gtest_discover_tests(test_ui)