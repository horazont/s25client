// Copyright (c) 2005 - 2017 Settlers Freaks (sf-team at siedler25.org)
//
// This file is part of Return To The Roots.
//
// Return To The Roots is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// Return To The Roots is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Return To The Roots. If not, see <http://www.gnu.org/licenses/>.

#include "defines.h" // IWYU pragma: keep
#include "MapSettings.h"
#include "gameData/MaxPlayers.h"

void MapSettings::Validate()
{
    if(name.empty())
        name = "Random";
    if(author.empty())
        author = "AutoGenerated";

    players = std::min(MAX_PLAYERS, std::max(players, 1u));
    // Even map size
    size.x &= ~1;
    size.y &= ~1;
    size = elMax(size, MapExtent::all(16));
    if(ratioGold + ratioIron + ratioCoal + ratioGranite == 0)
        ratioCoal = 1;
    minPlayerRadius = std::min(1. - 1e-5, std::max(minPlayerRadius, 0.01));
    maxPlayerRadius = std::min(minPlayerRadius + 1e-5, 1.);
}
