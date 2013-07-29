#pragma once

/*
 * Automaton.h
 *
 * @author: Milot Shala <milot.shala@gmail.com>
 * @date: January 20, 2013
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

#include <vector>
#include <memory>


class Automaton
{
public:
    Automaton();
    /**
     * @brief nextState
     * @return next state, whereas nextState->at(0) denotes fail state.
     */
    std::shared_ptr<std::vector<std::shared_ptr<Automaton> > > nextState();

    /**
     * @brief acceptedStateValues are the state integers as presented in the paper.
     * @return
     */
    std::shared_ptr<std::vector<int> > acceptedStateValues();


private:
    std::shared_ptr<std::vector<int> >                          m_AcceptedStateValues;
    std::shared_ptr<std::vector<std::shared_ptr<Automaton> > >   m_NextState;
};
