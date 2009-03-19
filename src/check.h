/*
 * Cppcheck - A tool for static C/C++ code analysis
 * Copyright (C) 2007-2009 Daniel Marjamäki, Reijo Tomperi, Nicolas Le Cam,
 * Leandro Penz, Kimmo Varis, Vesa Pikki
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
 * along with this program.  If not, see <http://www.gnu.org/licenses/
 */

#ifndef checkH
#define checkH

#include "settings.h"
#include <list>

class Tokenizer;
class ErrorLogger;

class Check
{
public:
    // This constructor is used when registering the CheckClass
    Check()
    {
        instances().push_back(this);
    }

    virtual ~Check()
    {
        instances().remove(this);
    }

    /** get instances of this */
    static std::list<Check *> &instances()
    {
        static std::list<Check *> _instances;
        return _instances;
    }

    /** run checks.. */
    virtual void runChecks(const Tokenizer *tokenizer, const Settings *settings, ErrorLogger *errorLogger) = 0;
};

#endif

