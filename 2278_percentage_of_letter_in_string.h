#pragma once

#include <string>

/*
* 2278. Percentage of Letter in String
* Given a string s and a character letter, return the percentage of characters in s that equal letter rounded down to the nearest whole percent.
*/

int percentageLetter(std::string s, char letter) {
  /* Multiply each side by 100 first as it avoids decimal truncation issues in this case */
  return 100 * (std::count(s.begin(), s.end(), letter) * 100) / ((float)s.size() * 100);
}

