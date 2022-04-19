#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <set>
#include <cstring>
using namespace sol157;
using namespace std;

/*takeaways
  - nothing jumps out other than in C++ you need
    to indicate where the string ends by appending
    '\000' at the end
*/
int File::read(char *buf, int n)
{
  auto charsRead = 0;
  while (charsRead <= n)
  {
    char chunk[5];
    auto read = read4(chunk);

    /* you need less than 4 chars */
    if (read >= n)
    {
      strncpy(buf + charsRead, chunk, n);
      charsRead = n;
      break;
    }
    /* see if we need to read in all chars read*/
    auto readin = charsRead + read <= n ? read : n - charsRead;
    if (readin > 0)
      strncpy(buf + charsRead, chunk, readin);
    charsRead += readin;

    if (read < 4 || readin == 0)
      break;
  }

  buf[charsRead + 1] = '\000';

  return charsRead;
}

int File::read4(char *buf)
{
  if (curIndx >= N)
  {
    buf[0] = '\000';
    return 0;
  }
  auto chars = curIndx + 4 <= N ? 4 : N - curIndx;
  strncpy(buf, buffer + curIndx, chars);
  curIndx += chars;
  buf[chars] = '\000';
  return chars;
}