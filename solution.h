
#ifndef SOLUTION_H
#define SOLUTION_H

#include "node.h"
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>

using namespace std;
namespace sol157
{
    class File
    {
    private:
        const char *buffer;
        int curIndx, N;

    public:
        File(string input) : buffer(input.c_str()), curIndx(0), N(input.size()){};
        int read4(char *buf);
        int read(char *buf, int n);
    };
}
#endif