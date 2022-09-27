#pragma once

#include <vector>
#include <string>

/*
* 1880. Check if Word Equals Summation of Two Words
* The letter value of a letter is its position in the alphabet starting from 0 (i.e. 'a' -> 0, 'b' -> 1, 'c' -> 2, etc.).
* The numerical value of some string of lowercase English letters s is the concatenation of the letter values of each letter in s, 
* which is then converted into an integer.
*
* You are given three strings firstWord, secondWord, and targetWord, each consisting of lowercase English letters 'a' through 'j' inclusive.
* Return true if the summation of the numerical values of firstWord and secondWord equals the numerical value of targetWord, or false otherwise.
*/

bool isSumEqual(std::string firstWord, std::string secondWord, std::string targetWord) {

  auto stv = [](std::string word)
  {
    int counter = 0;
    for (char x : word)
    {
      /* problem constraints guarantee strings to be lowercase english letters only */
      counter += std::tolower(x) - 97;
    }
    return counter;
  };

  return stv(firstWord) + stv(secondWord) == stv(targetWord);
}
