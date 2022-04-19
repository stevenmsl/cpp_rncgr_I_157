#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol157;

/*
Input: file = "abc", n = 4
Output: 3
Explanation: After calling your read method, buf should contain "abc".
We read a total of 3 characters from the file, so return 3.
Note that "abc" is the file's content, not buf.
buf is the destination buffer that you will have to write the results to.
*/

tuple<string, int, int> testFixture1()
{
  return make_tuple("abc", 4, 3);
}
/*
Input: file = "abcde", n = 5
Output: 5
Explanation: After calling your read method,
buf should contain "abcde". We read a total of
5 characters from the file, so return 5.
*/

tuple<string, int, int> testFixture2()
{
  return make_tuple("abcde", 5, 5);
}

/*
Input: file = "abcdABCD1234", n = 12
Output: 12
*/

tuple<string, int, int> testFixture3()
{
  return make_tuple("abcdABCD1234", 12, 12);
}

/*
Input: file = "leetcode", n = 5
Output: 5
*/

tuple<string, int, int> testFixture4()
{
  return make_tuple("leetcode", 5, 5);
}

void test1()
{
  auto f = testFixture1();
  const int size = get<1>(f);
  char *buf = new char[size + 1];
  auto file = File(get<0>(f));
  cout << "Expect to see " << to_string(get<2>(f)) << endl;
  cout << "Result: " << to_string(file.read(buf, size)) << endl;
  cout << "Buffer: " << endl;
  cout << buf << endl;
}

void test2()
{
  auto f = testFixture2();
  const int size = get<1>(f);
  char *buf = new char[size + 1];
  auto file = File(get<0>(f));
  cout << "Expect to see " << to_string(get<2>(f)) << endl;
  cout << "Result: " << to_string(file.read(buf, size)) << endl;
  cout << "Buffer: " << endl;
  cout << buf << endl;
}

void test3()
{
  auto f = testFixture3();
  const int size = get<1>(f);
  char *buf = new char[size + 1];
  auto file = File(get<0>(f));
  cout << "Expect to see " << to_string(get<2>(f)) << endl;
  cout << "Result: " << to_string(file.read(buf, size)) << endl;
  cout << "Buffer: " << endl;
  cout << buf << endl;
}

void test4()
{
  auto f = testFixture4();
  const int size = get<1>(f);
  char *buf = new char[size + 1];
  auto file = File(get<0>(f));
  cout << "Expect to see " << to_string(get<2>(f)) << endl;
  cout << "Result: " << to_string(file.read(buf, size)) << endl;
  cout << "Buffer: " << endl;
  cout << buf << endl;
}

/* test read4
File file("abcdefghijk"); // File is "abcdefghijk", initially file pointer (fp) points to 'a'
char[] buf = new char[4]; // Create buffer with enough space to store characters
read4(buf); // read4 returns 4. Now buf = "abcd", fp points to 'e'
read4(buf); // read4 returns 4. Now buf = "efgh", fp points to 'i'
read4(buf); // read4 returns 3. Now buf = "ijk", fp points to end of file
*/
void testRead4()
{
  auto file = File("abcdefghijk");
  char buffer[5];
  cout << "Expect to see 4" << endl;
  cout << to_string(file.read4(buffer)) << endl;
  cout << "Expect to see abcd" << endl;
  cout << buffer << endl;
  cout << "Expect to see 4" << endl;
  cout << to_string(file.read4(buffer)) << endl;
  cout << "Expect to see efgh" << endl;
  cout << buffer << endl;
  cout << "Expect to see 3" << endl;
  cout << to_string(file.read4(buffer)) << endl;
  cout << "Expect to see ijk" << endl;
  cout << buffer << endl;
}

main()
{
  test1();
  test2();
  test3();
  test4();
  // testRead4();
  return 0;
}