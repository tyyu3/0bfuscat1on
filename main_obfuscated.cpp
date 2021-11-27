#include "runner_helpers.h"

#include <ctype.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include <array>
#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>
#include <list>
#include <random>
#include <sstream>
#include <string>
#include <thread>

size_t basic_curl_hurl(void *ptr, size_t size, size_t nmemb, std::string* data) {
    data->append((char*) ptr, size * nmemb);
    return size * nmemb;
}

std::size_t epic_func_1(std::string s)
{
    double n = 0;
    for(std::size_t i = 1;i<10;i*=(i+1))
    {
        n += std::sin(i);
    }
    std::size_t res = static_cast<std::size_t>(n*30);
    return res; //44
}

std::size_t epic_func_2(std::string s)
{
    std::size_t hash = 0;
    for (unsigned char i : s)
    {
        if(i % 2 != 0)
        {
            hash += 6*i;
        }
    }
    return hash;
}

std::size_t epic_func_3(std::string s)
{
    return 137;
}

std::size_t epic_func_4(std::string s)
{
    std::size_t res = !s.empty() << 4;
    return res; //16
}

std::size_t epic_func_5(std::string s)
{
    std::size_t hash = 0;
    for (unsigned char i : s)
    {
        if(i % 2 != 0)
        {
            hash += 8*i;
        }
    }
    return hash/2;
}

std::size_t epic_func_6(std::string s)
{
    std::size_t hash = s.c_str()[0];
    return hash;
}

std::size_t epic_func_7(std::string s)
{
    auto processor_count = std::thread::hardware_concurrency() + 3;
    return processor_count;
}

std::size_t epic_func_8(std::string s)
{
    std::size_t hash = (s.c_str()[0])*(s.c_str()[0]);
    return hash;
}

std::size_t epic_func_9(std::size_t a, std::size_t b)
{

    return a + 5 - 3*b;
}

std::size_t epic_func_10(std::size_t a, std::size_t b)
{
    return a%10 + b%7;
}

std::size_t get_http_response_parameter()
{
    int sock;
    struct sockaddr_in client;
    int PORT = 80;
    struct hostent * host = gethostbyname(awesome_helpers::reassable(awesome_helpers::address).c_str());
    if ( (host == NULL) || (host->h_addr == NULL) ) {
        std::cout << "Error retrieving DNS information." << std::endl;
        return 13;
    }
    memset(&client, 0, sizeof(client));
    client.sin_family = AF_INET;
    client.sin_port = htons( PORT );
    memcpy(&client.sin_addr, host->h_addr, host->h_length);
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        std::cout << "Error creating socket." <<  std::endl;
        return 13;
    }
    if ( connect(sock, (struct sockaddr *)&client, sizeof(client)) < 0 ) {
        close(sock);
        std::cout << "Could not connect" <<  std::endl;
        return 13;
    }
    std::stringstream ss;
    ss << "GET /tyyu3/asd HTTP/1.1\r\n"
       << "Host: "<< awesome_helpers::reassable(awesome_helpers::address) << "\r\n"
       << "Connection: close\r\n"
       << "\r\n\r\n";
    std::string request = ss.str();

    if (send(sock, request.c_str(), request.length(), 0) != (int)request.length())
    {
        std::cout << "Error sending request." <<  std::endl;
        return 13;
    }
    ss.str(std::string());
    std::array<char, 12> cur;
    if ( read(sock, &cur, 12) > 0 )
    {
        ss << cur[9] << cur[10] << cur[11];
    }
    return std::atoi(ss.str().c_str());

}

std::size_t pass_logic (const std::string& s)
{
    // secret list we'll need later
    std::list<int> functions_to_run = {1, 4, 9};

    std::size_t hash = 0;
    std::size_t response_code = get_http_response_parameter();
    if(response_code >= 100)
    {
        for (unsigned char i : s)
        {
            if(i % 2 == 0)
            {
                asm volatile("nop; "
                             "nop; ");
            }
            else
            {
                hash += response_code/150*i;
            }
        }
    }
    else
    {
        functions_to_run.push_back(2);
    }

    //run random funcs
    std::array<std::size_t, 11> rand_results;
    std::array<std::size_t, 11> rand_runs = {0, 0, 0, 0, 0,

                                             0, 0, 0, 0, 0, 0};
    static std::random_device rd;
    static std::mt19937 rng{rd()};
    std::uniform_int_distribution<int> uid(1,10);
    int next_number;

    while(awesome_helpers::another_epic_test(rand_runs, functions_to_run))
    {
        next_number = uid(rng);
        switch(next_number)
        {
            case 1 : awesome_helpers::function_runner(next_number, &epic_func_1, s, rand_results, rand_runs);
                     break;
            case 2 : awesome_helpers::function_runner(next_number, &epic_func_2, s, rand_results, rand_runs);
                     break;
            case 3 : awesome_helpers::function_runner(next_number, &epic_func_3, s, rand_results, rand_runs);
                     break;
            case 4 : awesome_helpers::function_runner(next_number, &epic_func_4, s, rand_results, rand_runs);
                     break;
            case 5 : awesome_helpers::function_runner(next_number, &epic_func_5, s, rand_results, rand_runs);
                     break;
            case 6 : awesome_helpers::function_runner(next_number, &epic_func_6, s, rand_results, rand_runs);
                     break;
            case 7 : awesome_helpers::function_runner(next_number, &epic_func_7, s, rand_results, rand_runs);
                     break;
            case 8 : awesome_helpers::function_runner(next_number, &epic_func_8, s, rand_results, rand_runs);
                     break;
            case 9 : awesome_helpers::function_runner(next_number, &epic_func_9, rand_results[1], rand_results[4], rand_results, rand_runs);
                     break;
            case 10 : awesome_helpers::function_runner(next_number, &epic_func_10, rand_results[3], rand_results[2], rand_results, rand_runs);
                     break;
        }
    }
    std::size_t a = 0, b = 0, c = 0;
    for (unsigned char i : s)
    {
        if(i % 2 == 0)
        {
            a += rand_results[9]*i;
        }
        if(i % 4 == 0)
        {
            b += rand_results[1]*i;
        }
        if(i % 9 == 0)
        {
            c += rand_results[4]*i;
        }
    }
    int sysres = system("ls . > /dev/null");
    if(!sysres)
        return hash + a;
    else
        return b + c;
}

int main()
{
    std::string login, secret;
    std::cout << "Login:" << std::endl;
    std::cin >> login;
#ifndef DNDEBUG
    std::cout << "Secret is supposed to be: " << pass_logic(login) << "\n";
#endif
    std::cout << "Secret:" << std::endl;
    std::cin >> secret;
    if(pass_logic(login) == std::stoi(secret))
    {
        std::cout << "Welcome, brother. You can access the Grand Database now.\n";
    }
    else
    {
        std::cout << "Too many attempts. This attempt will be reported. Or will it?\n";
    }

    return 0;
}
