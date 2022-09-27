#pragma once

#include <string>
#include <set>

/*
* 2351. First Letter to Appear Twice
* Given a string s consisting of lowercase English letters, return the first letter to appear twice.
*/

char repeatedCharacter(std::string s) {
  std::set<char> seen;
  for (char x : s)
  {
    if (seen.insert(x).second == false)
      return x;
  }
  /* this is here simply for compile sake, problem constraints guarantee a duplicate char above */
  return '\0';
}
