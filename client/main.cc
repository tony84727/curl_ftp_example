#include <curl/curl.h>
#include <cassert>
#include <string>
#include <stdexcept>
#include <iostream>

static size_t write_data(char *ptr, size_t size, size_t nmemb, void *userdata) {
    if (nmemb <= 0) {
        return 0;
    }
    assert(size == 1);
    ((std::string *)userdata)->append(ptr, nmemb);
    return nmemb;
}

int main(int argc, char** argv) {
    if (argc <= 1) {
        std::cout << "usage: client [url]" << std::endl;
        return 1;
    }
    CURL *c = curl_easy_init();
    std::string buffer;
    char error_message[CURL_ERROR_SIZE];
    curl_easy_setopt(c, CURLOPT_URL, argv[1]);
    curl_easy_setopt(c, CURLOPT_WRITEDATA, &buffer);
    curl_easy_setopt(c, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(c, CURLOPT_ERRORBUFFER, error_message);
    CURLcode code = curl_easy_perform(c);
    if (code != CURLE_OK) {
        throw std::runtime_error(error_message);
    }
    long statusCode = 200;
    curl_easy_getinfo(c, CURLINFO_RESPONSE_CODE, &statusCode);
    std::cout << buffer << std::endl;
    return 0;
}
