add_executable(test_settings
	test_settings.cpp
)

target_include_directories(test_settings
	PRIVATE ${CMAKE_SOURCE_DIR}/include)

add_test(
	NAME settings
	COMMAND test_settings
)