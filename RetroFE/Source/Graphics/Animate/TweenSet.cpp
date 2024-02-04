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
#include "TweenSet.h"

TweenSet::TweenSet() = default;

TweenSet::TweenSet(TweenSet &copy)
{
    for(auto it = copy.set_.begin(); it != copy.set_.end(); it++)
    {
        auto *t = new Tween(**it);
        set_.push_back(t);
    }
}

TweenSet& TweenSet::operator=(const TweenSet& other) {
    if (this != &other) { // Check for self-assignment
        clear(); // Clear existing resources

        // Deep copy
        for (auto const* tween : other.set_) {
            auto* newTween = new Tween(*tween); // Assuming Tween has a suitable copy constructor
            push(newTween);
        }
    }
    return *this;
}


TweenSet::~TweenSet()
{
    clear();
}

void TweenSet::push(Tween *tween)
{
    set_.push_back(tween);
}

void TweenSet::clear()
{
    for(Tween* tween : set_)
    {
        delete tween;
    }
    set_.clear();
}

std::vector<Tween *> *TweenSet::tweens()
{
    return &set_;
}

Tween *TweenSet::getTween(unsigned int index)
{
    return set_[index];
}


size_t TweenSet::size() const
{
    return set_.size();
}
