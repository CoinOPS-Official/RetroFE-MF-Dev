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

#include "Animation.h"
#include <string>

Animation::Animation() = default;

Animation::Animation(Animation& copy)
{
    for (auto* tweenSet : copy.animationVector_)
    {
        Push(new TweenSet(*tweenSet));
    }
}

Animation& Animation::operator=(const Animation& other) {
    if (this != &other) { // Check for self-assignment
        Clear(); // Clear existing resources

        // Deep copy
        for (auto* tweenSet : other.animationVector_) {
            TweenSet* newTweenSet = new TweenSet(*tweenSet); // Deep copy of TweenSet
            Push(newTweenSet);
        }
    }
    return *this;
}

Animation::~Animation()
{
    Clear();
}

void Animation::Push(TweenSet *set)
{
    animationVector_.push_back(set);
}

void Animation::Clear()
{
    for (TweenSet* set : animationVector_) {
        delete set;
    }
    animationVector_.clear();
}


std::vector<TweenSet *> *Animation::tweenSets()
{
    return &animationVector_;
}

TweenSet *Animation::tweenSet(unsigned int index)
{
    return animationVector_[index];
}


size_t Animation::size() const
{
    return animationVector_.size();
}
