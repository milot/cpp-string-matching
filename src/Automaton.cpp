#include "Automaton.h"

Automaton::Automaton()
    : m_NextState(new std::vector<std::shared_ptr<Automaton> >(0x100)),
      m_AcceptedStateValues(new std::vector<int>())

{

}

std::shared_ptr<std::vector<std::shared_ptr<Automaton> > > Automaton::nextState()
{
    return m_NextState;
}

std::shared_ptr<std::vector<int> > Automaton::acceptedStateValues()
{
    return m_AcceptedStateValues;
}
