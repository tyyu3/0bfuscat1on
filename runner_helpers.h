#ifndef RUNNER_HELPERS_H
#define RUNNER_HELPERS_H

#include <array>
#include <list>
#include <string>
#include <sstream>
namespace awesome_helpers
{
    std::list<int> address(
    {
        'w'+3,
        'w'+3,
        'w'+3,
        '.'+3,
        'g'+3,
        'i'+3,
        't'+3,
        'h'+3,
        'u'+3,
        'b'+3,
        '.'+3,
        'c'+3,
        'o'+3,
        'm'+3,
    });

    std::list<int> command(
    {
        'l'+3,
        's'+3,
        ' '+3,
        '.'+3,
        ' '+3,
        '>'+3,
        ' '+3,
        '/'+3,
        'd'+3,
        'e'+3,
        'v'+3,
        '/'+3,
        'n'+3,
        'u'+3,
        'l'+3,
        'l'+3,
    });

    std::string reassable(std::list<int> list)
    {
        std::stringstream ss;
        for(auto i : list)
        {
            ss << static_cast<char>(i - 3);
        }
        return ss.str();
    }

    bool another_epic_test(std::array<std::size_t, 11>& run_array, std::list<int>& to_run)
    {
        bool we_should_run_another = 0;
        for(int a : to_run)
        {
            if(run_array[a] == 0)
            {
                we_should_run_another = true;
                break;
            }
        }
        return we_should_run_another;
    }

    void function_runner(std::size_t number,
                         std::size_t (*f_ptr) (std::string),
                         std::string s,
                         std::array<std::size_t, 11>& result_array,
                         std::array<std::size_t, 11>& runs_array)
    {
        if(number == 2 && (runs_array[5] == 0))
        {
            number = 5;
        }
        result_array[number] = f_ptr(s);
        runs_array[number] = 1;
    }

    void function_runner(std::size_t number,
                         std::size_t (*f_ptr) (std::size_t, std::size_t),
                         std::size_t a,
                         std::size_t b,
                         std::array<std::size_t, 11>& result_array,
                         std::array<std::size_t, 11>& runs_array)
    {
        if(number == 9 && ((runs_array[1] == 0) || (runs_array[4] == 0)))
        {
            return;
        }
        result_array[number] = f_ptr(a, b);
        runs_array[number] = 1;
        return;
    }
}


#endif // RUNNER_HELPERS_H
