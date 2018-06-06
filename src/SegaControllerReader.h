//
// SegaControllerReader.h
//
// Author:
//       Jon Thysell <thysell@gmail.com>
//
// Copyright (c) 2017-2018 Jon Thysell <http://jonthysell.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include "constants.h"

#ifndef SegaControllerReader_h
#define SegaControllerReader_h

const unsigned long SC_READ_DELAY_MS = 5; // Must be >= 3 to give 6-button controller time to reset

class SegaControllerReader {
    public:
        SegaControllerReader(byte db9_pin_7, byte db9_pin_1, byte db9_pin_2, byte db9_pin_3, byte db9_pin_4, byte db9_pin_6, byte db9_pin_9);

        word getState();

    private:
        void readCycle(byte cycle);

        word _currentState;

        unsigned long _lastReadTime;

        boolean _sixButtonMode;

        byte _selectPin; // output select pin
        byte _inputPins[SC_IO_PINS];
};

#endif