// Copyright 2017 Google Inc. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// WARNING: compiled with different flags => must not define/instantiate any
// inline functions, nor include any headers that do - see instruction_sets.h.

#include "highwayhash/highwayhash_target.h"

#include "highwayhash/highwayhash.h"

#ifndef HH_DISABLE_TARGET_SPECIFIC
namespace highwayhash {

extern "C" {
uint64_t HH_ADD_TARGET_SUFFIX(HighwayHash64_)(const HHKey key,
                                              const char* bytes,
                                              const uint64_t size) {
  HHStateT<HH_TARGET> state(key);
  HHResult64 result;
  HighwayHashT(&state, bytes, size, &result);
  return result;
}
}  // extern "C"

template <TargetBits Target>
void HighwayHash<Target>::operator()(const HHKey& key,
                                     const char* HH_RESTRICT bytes,
                                     const size_t size,
                                     HHResult64* HH_RESTRICT hash) const {
  HHStateT<Target> state(key);
  HighwayHashT(&state, bytes, size, hash);
}

template <TargetBits Target>
void HighwayHash<Target>::operator()(const HHKey& key,
                                     const char* HH_RESTRICT bytes,
                                     const size_t size,
                                     HHResult128* HH_RESTRICT hash) const {
  HHStateT<Target> state(key);
  HighwayHashT(&state, bytes, size, hash);
}

template <TargetBits Target>
void HighwayHash<Target>::operator()(const HHKey& key,
                                     const char* HH_RESTRICT bytes,
                                     const size_t size,
                                     HHResult256* HH_RESTRICT hash) const {
  HHStateT<Target> state(key);
  HighwayHashT(&state, bytes, size, hash);
}

// Instantiate for the current target.
template struct HighwayHash<HH_TARGET>;

}  // namespace highwayhash
#endif  // HH_DISABLE_TARGET_SPECIFIC
