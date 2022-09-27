#pragma once

#include <vector>
#include <string>
#include <map>
#include <set>

/*
* 966. Vowel Spellchecker
* Given a wordlist, we want to implement a spellchecker that converts a query word into a correct word.
* 
* When the query exactly matches a word in the wordlist (case-sensitive), you should return the same word back.
* When the query matches a word up to capitlization, you should return the first such match in the wordlist.
* When the query matches a word up to vowel errors, you should return the first such match in the wordlist.
* If the query has no matches in the wordlist, you should return the empty string.
*/

std::vector<std::string> spellchecker(std::vector<std::string>& wordlist, std::vector<std::string>& queries) {
  std::string vowel_alphabet = "aeiou";
  auto to_wildcard = [](std::string word)
  {
    for (int i = 0; i < word.length(); i++)
    {
      if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u')
      {
        word[i] = '*';
      }
    }
    return word;
  };
  
  auto to_lower = [](std::string word)
  {
    std::string rv;
    for (char a : word)
    {
      rv.push_back(std::tolower(a));
    }
    return rv;
  };
  

  std::map<std::string, std::string> wildcard_wordlist;
  std::map<std::string, std::string> lowercase_wordlist;
  std::set<std::string> direct_wordlist;
  for (std::string word : wordlist)
  {
    direct_wordlist.insert(word);
    /* we should just be able to allow insertion to fail on duplicate elements and ignore them */
    lowercase_wordlist.insert(std::pair<std::string, std::string>(to_lower(word), word));
    wildcard_wordlist.insert(std::pair<std::string, std::string>(to_wildcard(to_lower(word)), word));
  }

  std::vector<std::string> spellchecked;
  for (std::string query : queries)
  {
    if (direct_wordlist.find(query) != direct_wordlist.end())
    {
      spellchecked.push_back(query);
      continue;
    }

    std::string lowercase_query = to_lower(query);

    if (lowercase_wordlist.find(lowercase_query) != lowercase_wordlist.end())
    {
      spellchecked.push_back(lowercase_wordlist[lowercase_query]);
      continue;
    }

    std::string wildcard_query = to_wildcard(lowercase_query);
    if (wildcard_wordlist.find(wildcard_query) != wildcard_wordlist.end())
    {
      spellchecked.push_back(wildcard_wordlist[wildcard_query]);
      continue;
    }
    spellchecked.push_back(std::string(""));
  }

  return spellchecked;

}
