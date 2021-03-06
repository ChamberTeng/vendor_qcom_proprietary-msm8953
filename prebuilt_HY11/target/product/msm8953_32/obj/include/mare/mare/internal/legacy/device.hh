// --~--~--~--~----~--~--~--~----~--~--~--~----~--~--~--~----~--~--~--~--
// Copyright 2013-2015 Qualcomm Technologies, Inc.
// All rights reserved.
// Confidential and Proprietary – Qualcomm Technologies, Inc.
// --~--~--~--~----~--~--~--~----~--~--~--~----~--~--~--~----~--~--~--~--
#pragma once

#ifdef MARE_HAVE_OPENCL

#include <mare/internal/device/cldevice.hh>
#include <mare/internal/legacy/types.hh>

namespace mare {
namespace internal {
namespace legacy {

template<typename Attribute>
inline void get_devices(Attribute d_type, std::vector<device_ptr>* devices)
{
  MARE_INTERNAL_ASSERT(devices, "null vector passed to get_devices");
  internal::get_devices(d_type, devices);
}

template<typename Attribute>
auto get_device_attribute(device_ptr device, Attribute attr) ->
     typename internal::device_attr<Attribute>::type
{
  auto d_ptr = internal::c_ptr(device);
  MARE_API_ASSERT(d_ptr, "null device_ptr");
  return d_ptr->get(std::forward<Attribute>(attr));
}

};
};
};

#endif
