#include <boost/test/unit_test.hpp>
#include <stdexcept>
#include <fstream>
#include <random>
#include <string>
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

#include "fileinfo.h"

typedef std::vector<char> char_array;

char_array charset()
{
  //Change this to suit
  return char_array(
    { '0','1','2','3','4',
    '5','6','7','8','9',
    'A','B','C','D','E','F',
    'G','H','I','J','K',
    'L','M','N','O','P',
    'Q','R','S','T','U',
    'V','W','X','Y','Z',
    'a','b','c','d','e','f',
    'g','h','i','j','k',
    'l','m','n','o','p',
    'q','r','s','t','u',
    'v','w','x','y','z',
    ' ','!','"','#','$',
    '%','&','(',')','*',
    '+',',','-','.','/',
    ':',';','<','=','>',
    '?','@','[',']','^',
    '_','`','{','|','}',
    '~','\n'
    });
};

std::string random_string(size_t length, std::function<char(void)> rand_char)
{
  std::string str(length, 0);
  std::generate_n(str.begin(), length, rand_char);
  return str;
}

//vo testot programce koe so sozdava 1000 fileoj vo for
//vo string zacuvvame teskt se sozdava file od stringot se brojat znaci,... se sporedvat

BOOST_AUTO_TEST_SUITE(getFileInfo_tests)
BOOST_AUTO_TEST_CASE(getFileInfo_test1)
{
    const unsigned int numCharacters = 17;
    const unsigned int numSpecialSymbols = 4;
    const unsigned int numNewLines = 2;
    const unsigned int numWhiteSpace = 3;

    const std::string fileName = "D:\\test1.txt";

    FileInfo_t inf = getFileInfo(fileName);

    BOOST_CHECK_EQUAL(numCharacters, inf.numCharacters);
    BOOST_CHECK_EQUAL(numSpecialSymbols, inf.numSpecialSymbols);
    BOOST_CHECK_EQUAL(numNewlines, inf.numNewLines);
    BOOST_CHECK_EQUAL(numWhitespace, inf.numWhiteSpace);
}

BOOST_AUTO_TEST_CASE(getFileInfo_test2)
{
    const unsigned int numCharacters = 17;
    const unsigned int numSpecialSymbols = 3;
    const unsigned int numNewLines = 3;
    const unsigned int numWhiteSpace = 4;

    std::ofstream myfile;
    myfile.open("D:\\test2.txt");
    myfile << "dke\n;[4 d\ns  0\ns2d @";
    myfile.close();

    const std::string fileName = "D:\\test2.txt";

    FileInfo_t inf = getFileInfo(fileName);

    BOOST_CHECK_EQUAL(numCharacters, inf.numCharacters);
    BOOST_CHECK_EQUAL(numSpecialSymbols, inf.numSpecialSymbols);
    BOOST_CHECK_EQUAL(numNewLines, inf.numNewLines);
    BOOST_CHECK_EQUAL(numWhiteSpace, inf.numWhiteSpace);
}

BOOST_AUTO_TEST_CASE(getFileInfo_test3)
{
    //0) create the character set.
    const auto ch_set = charset();

    //1) create a non-deterministic random number generator
    std::default_random_engine rng(std::random_device{}());

    //2) create a random number "shaper" that will give
    //   us uniformly distributed indices into the character set
    std::uniform_int_distribution<> dist(0, ch_set.size() - 1);

    //3) create a function that ties them together, to get:
    //   a non-deterministic uniform distribution from the
    //   character set of your choice.
    auto randchar = [ch_set, &dist, &rng]() {return ch_set[dist(rng)]; };

    //4) set the length of the string you want and profit!
    auto length = 10000;

    std::string sodrzina = random_string(length, randchar);
    FileInfo_t infS = getStringInfo(sodrzina);

    std::ofstream myfile;
    myfile.open("D:\\test3.txt");
    myfile << sodrzina;
    myfile.close();

    const std::string fileName = "D:\\test3.txt";

    FileInfo_t inf = getFileInfo(fileName);

    BOOST_CHECK_EQUAL(infS.numCharacters, inf.numCharacters);
    BOOST_CHECK_EQUAL(infS.numSpecialSymbols, inf.numSpecialSymbols);
    BOOST_CHECK_EQUAL(infS.numNewLines, inf.numNewLines);
    BOOST_CHECK_EQUAL(infS.numWhiteSpace, inf.numWhiteSpace);
}

BOOST_AUTO_TEST_SUITE_END()

