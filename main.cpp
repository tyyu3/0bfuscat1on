#include <iostream>

std::size_t pass_logic (std::string s)
{
    std::size_t hash = 0;
    for (unsigned char i : s)
    {
        if(i % 2 == 0)
        {
            hash += i;
        }
        else
        {
            hash += 2*i;
        }
    }
    return hash;
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
