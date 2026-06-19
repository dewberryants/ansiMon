add_executable(test_data
    "test_data.cpp"
    "${PROJECT_SOURCE_DIR}/src/data/data.cpp"
)

target_link_libraries(test_data
    GTest::gtest_main
)

target_include_directories(test_data PRIVATE
    "${PROJECT_SOURCE_DIR}/include"
)

add_executable(test_ui
    test_ui.cpp
    "${PROJECT_SOURCE_DIR}/src/ui/ui.cpp"
)

target_link_libraries(test_ui
    GTest::gtest_main
    ftxui::component
)

target_include_directories(test_ui PRIVATE
    "${PROJECT_SOURCE_DIR}/include"
)

add_executable(test_game
    test_game.cpp
    "${PROJECT_SOURCE_DIR}/src/data/data.cpp"
)

target_link_libraries(test_game
    GTest::gtest_main
)

target_link_libraries(test_game
    GTest::gtest_main
    ftxui::component
)

target_include_directories(test_game PRIVATE
    "${PROJECT_SOURCE_DIR}/include"
)

include(GoogleTest)

gtest_discover_tests(test_data)

gtest_discover_tests(test_ui)

gtest_discover_tests(test_game)