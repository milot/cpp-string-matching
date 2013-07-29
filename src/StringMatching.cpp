#include "StringMatching.h"

StringMatching::StringMatching()
{
}

std::string StringMatching::searchString(const std::string &word)
{

    std::string result = "";

    std::shared_ptr<Automaton> currentState = rootNode;

    if (currentState == NULL)
    {
        result = "";
    }

    for (int i = 0; i < word.length(); ++i)
    {
        int characterInWord = (int) (word[i] & 0xff);

        if (characterInWord < 0 || characterInWord > 0xff)
        {
            characterInWord = 0xff;
        }

        if (currentState == NULL)
        {
            currentState = rootNode;
        }

        while (currentState->nextState()->at(characterInWord) == NULL)
        {
            currentState = currentState->nextState()->at(0);

            if (currentState == NULL) break;
        }

        if (currentState == NULL) continue;

        currentState = currentState->nextState()->at(characterInWord);

        if (result.c_str() != NULL)
        {
            if (currentState->acceptedStateValues()->size() > 0)
            {
                result = m_WordsList.at(currentState->acceptedStateValues()->at(0));
                break;
            }
        }
        else if(currentState->acceptedStateValues()->size() > 0)
        {
            break;
        }

    }


    return result;
}

std::shared_ptr<Automaton> StringMatching::createAutomaton()
{
    std::shared_ptr<Automaton> patternMatchinAutomaton(new Automaton());

    if (patternMatchinAutomaton != NULL)
    {
        pmaList.push_back(patternMatchinAutomaton);
    }

    return patternMatchinAutomaton;
}

std::vector<std::string> StringMatching::tokenizeWords(const std::string &string)
{
    std::istringstream stringStream(string);
    std::string tmpStr;
    std::vector<std::string> tokenizedWords;

    while (stringStream >> tmpStr)
    {
        tokenizedWords.push_back(tmpStr);
    }

    return tokenizedWords;
}

std::shared_ptr<Automaton> StringMatching::buildIndex(const std::string &words)
{
    std::vector<std::string> wordsList = tokenizeWords(words);

    const int size = wordsList.size();

    std::shared_ptr<Automaton> tmpRootNode = createAutomaton();

    rootNode = tmpRootNode;

    for (int i = 0; i < size; ++i)
    {
        std::string s = wordsList.at(i);
        m_WordsList.push_back(s);

        // Build the simplest Trie EVER :P
        std::shared_ptr<Automaton> trie = rootNode;
        const int _size = s.length();

        for (int j = 0; j < _size; ++j)
        {
            int c = (int) (s.at(j) & 0xff);

            if (trie->nextState()->at(c) == NULL)
            {
                trie->nextState()->at(c).reset(new Automaton());
            }
            trie = trie->nextState()->at(c);
        }

        trie->acceptedStateValues()->push_back(i);
    }


    /*
     * build failure function as presented in the paper
     * using breadth first search
     */
    std::shared_ptr<std::queue<std::shared_ptr<Automaton> > >
            automatonStateQueue(new std::queue<std::shared_ptr<Automaton> >());

    for (int unicodeCharacter = 0x01; unicodeCharacter <= 0xff; ++unicodeCharacter)
    {
        if (rootNode->nextState()->at(unicodeCharacter) != NULL)
        {
            rootNode->nextState()->at(unicodeCharacter)->nextState()->at(0) = rootNode;
            automatonStateQueue->push(rootNode->nextState()->at(unicodeCharacter));
        }
        else
        {
            rootNode->nextState()->at(unicodeCharacter) = rootNode;
        }
    }

    std::shared_ptr<Automaton> tmpAutomaton;
    while(automatonStateQueue->size() > 0)
    {
        tmpAutomaton = automatonStateQueue->front();
        automatonStateQueue->pop();

        for (int unicodeCharacter = 0x01; unicodeCharacter <= 0x0ff; ++unicodeCharacter)
        {
            if (tmpAutomaton->nextState()->at(unicodeCharacter) != NULL)
            {
                automatonStateQueue->push(tmpAutomaton->nextState()->at(unicodeCharacter));
                std::shared_ptr<Automaton> r = tmpAutomaton->nextState()->at(0);

                while (r->nextState()->at(unicodeCharacter) == NULL)
                {
                    r = r->nextState()->at(0);
                }
                tmpAutomaton->nextState()->at(unicodeCharacter)->nextState()->at(0) = r->nextState()->at(unicodeCharacter);
            }
        }        
    }

    return rootNode;
}
