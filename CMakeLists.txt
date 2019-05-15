cmake_minimum_required(VERSION 3.2)
include(cmake/HunterGate.cmake)
HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.23.168.tar.gz"
    SHA1 "27c195b680097a1c4e16688a2f2f4b7e22d3ec36"
)

project(curl_ftp_example)

hunter_add_package(CURL)

add_subdirectory(client)