/* This file is part of RetroFE.
 *
 * RetroFE is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * RetroFE is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with RetroFE.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once


#include "Component.h"
#include "../Page.h"
#include <SDL2/SDL.h>
#include <vector>


class Font;


class Text : public Component
{

public:
    Text( const std::string& text, Page &p, Font *font, int monitor );
    ~Text( ) override;
    void     setText( const std::string& text, int id = -1 ) override;
    void     deInitializeFonts( ) override;
    void     initializeFonts( ) override;
    void     draw( ) override;

private:
    std::string textData_;
    Font       *fontInst_;
};
