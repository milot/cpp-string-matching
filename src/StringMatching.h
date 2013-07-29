#pragma once

/*
 * StringMatching.h
 *
 * @author: Milot Shala <milot.shala@gmail.com>
 *
 * @reference: http://www.win.tue.nl/~watson/2R080/opdracht/p333-aho-corasick.pdf
 * @reference: http://www.cs.uku.fi/~kilpelai/BSA05/lectures/slides04.pdf
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include <memory>
#include "Automaton.h"

class TNode;

/**
 * @brief The StringMatching class
 * This class is responsible for creating the String Matching Index and provides
 * a match function for string-matching. When building the String Matching Index
 * failure function, it uses breadth first search strategy as described in the
 * Aho Corasick paper of 1975.
 */
class StringMatching
{
public:
    explicit StringMatching();

    /**
     * @brief searchString function searches for matched string and returns it.
     * @param word input
     * @return the matched string
     *
     */
    std::string searchString(const std::string &word);

    /**
     * @brief createAutomaton function creates automaton state and inserts it in the pattern
     * matching automaton list to keep track.
     * @return returns the new automaton.
     */
    std::shared_ptr<Automaton> createAutomaton();

    /**
     * @brief tokenizeWords function is used to return list of tokens for a given string
     * @param string
     * @return list of tokens stripped from the given string
     */
    std::vector<std::string> tokenizeWords(const std::string &string);

    /**
     * @brief buildIndex function generates the string matching index,
     * creates simple trie data structure, failure and goto functions for the
     * given piece of string (or a larger text). Internally it uses also tokenizeWords
     * function to get the individual tokens of words to build the trie with.
     * @param words
     * @return
     */
    std::shared_ptr<Automaton> buildIndex(const std::string &words);

private:
    std::vector<std::shared_ptr<Automaton> >   pmaList;
    std::vector<std::string>                  m_WordsList;
    std::shared_ptr<Automaton>                 rootNode;

};
