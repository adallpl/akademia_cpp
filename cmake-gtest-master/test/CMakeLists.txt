add_executable(test
    example.cpp
    main.cpp)

target_link_libraries(test libstuff libgtest)
