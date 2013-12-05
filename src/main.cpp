/*
 * TNode.h
 *
 * @author: Milot Shala <milot.shala@gmail.com>
 * @date: January 20, 2013
 *
 */

#include <iostream>
#include "StringMatching.h"

int main() {

  /*
   * Example usage of the StringMatching class.
   */
  std::string text = "He is capable of using unusual gadgetry,"
                     "which aids him in situations that require stealth, "
                     "and also in head-on encounters. Corvo is highly proficient"
                     "with both ranged and melee weapons, such as the sword and the crossbow.";

  StringMatching stringMatchingObject;

  stringMatchingObject.buildIndex(text);

  std::cout << "Match: " << stringMatchingObject.searchString("A very long text which MentionsCorvoAttano"
                                       "in ambiguous way to test string matching") << std::endl;

  return 0;
}

