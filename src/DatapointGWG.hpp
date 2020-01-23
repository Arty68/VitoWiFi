/*

Copyright 2017 Bert Melis

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/

#pragma once

// #include <stdint.h>
// #include <stdio.h>
#include <string.h>  // for strcmp()
#include <functional>
#include <vector>
#include <memory>
#include <algorithm>
#include "DPTypes.hpp"
#include "DPValue.hpp"
#include "Constants.hpp"


// callback and forward declares
class IDatapointGWG;
typedef std::function<void(const IDatapoint&, DPValue)> Callback;

// Datapoints
class IDatapointGWG {
  template<class> friend class VitoWiFiClass;

 public:
  IDatapointGWG(const char* name, const char* group, uint8_t function,uint8_t address, bool writeable = false);
  ~IDatapointGWG();
  const char* getName() const { return _name; }
  const char* getGroup() const { return _group; }
  const uint8_t getAddress() const { return _address; }
  const uint8_t getFunction() const { return _function; }
  IDatapointGWG& setFunction(uint8_t address) { _function = function; return *this; }
  IDatapointGWG& setAddress(uint8_t address) { _address = address; return *this; }
  const bool isWriteable() const { return _writeable; }
  IDatapointGWG& setWriteable(bool writeable) { _writeable = writeable; return *this; }
  IDatapointGWG& setGlobalCallback(Callback cb) { _globalCb = cb; return *this; }
  IDatapointGWG& setCallback(Callback cb) { _cb = cb; return *this; }
  virtual const size_t getLength() const = 0;
  virtual IDatapointGWG& setLength(uint8_t length) = 0;
  virtual void encode(uint8_t* out, const DPValue in) = 0;
  virtual DPValue decode(const uint8_t* in) = 0;
  void setValue(DPValue value);

 protected:
  const char* _name;
  const char* _group;
  uint8_t _function;
  uint8_t _address;
  bool _writeable;
  static Callback _globalCb;
  Callback _cb;
  static std::vector<IDatapointGWG*> _dps;

 public:
  // better not use this publicly
  const std::vector<IDatapointGWG*>& getCollection() const { return _dps; }
};

template <class T>
class DatapointGWG : public IDatapointGWG {
 public:
  DatapointGWG(const char* name, const char* group,uint8_t function, uint8_t address, bool writeable = false) :
    IDatapointGWG(name, group, function, address, writeable) {}

 protected:
  T _t;

 public:
  const size_t getLength() const { return _t.getLength(); }
  IDatapointGWG& setLength(uint8_t length) { _t.setLength(length); return *this; }
  void encode(uint8_t* out, const DPValue in)  { _t.encode(out, in); }
  DPValue decode(const uint8_t* in) { return _t.decode(in); }
};

typedef DatapointGWG<convRaw> DPRaw;
typedef DatapointGWG<conv2_10_F> DPTemp;
typedef DatapointGWG<conv1_1_US> DPTempS;
typedef DatapointGWG<conv1_1_B> DPStat;
typedef DatapointGWG<conv4_1_UL> DPCount;
typedef DatapointGWG<conv2_1_UL> DPCountS;
typedef DPTempS DPMode;
typedef DatapointGWG<conv4_3600_F> DPHours;
typedef DatapointGWG<conv1_10_F> DPCoP;
