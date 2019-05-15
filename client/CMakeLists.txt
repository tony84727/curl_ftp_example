find_package(CURL CONFIG REQUIRED)

add_executable(
    client
    main.cc
)

target_link_libraries(client CURL::libcurl)