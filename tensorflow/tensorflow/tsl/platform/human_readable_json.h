/* Copyright 2018 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#ifndef TENSORFLOW_TSL_PLATFORM_HUMAN_READABLE_JSON_H_
#define TENSORFLOW_TSL_PLATFORM_HUMAN_READABLE_JSON_H_

#include "tensorflow/tsl/platform/protobuf.h"
#include "tensorflow/tsl/platform/status.h"

namespace tsl {

// Converts a proto to a JSON-like string that's meant to be human-readable
// but still machine-parseable.
//
// This string may not be strictly JSON-compliant, but it must be parseable by
// HumanReadableJSONToProto.
//
// When ignore_accuracy_loss = true, this function may ignore JavaScript
// accuracy loss with large integers.
Status ProtoToHumanReadableJson(const protobuf::Message& proto, string* result,
                                bool ignore_accuracy_loss);
Status ProtoToHumanReadableJson(const protobuf::MessageLite& proto,
                                string* result, bool ignore_accuracy_loss);

// Converts a string produced by ProtoToHumanReadableJSON to a protobuf.  Not
// guaranteed to work for general JSON.
Status HumanReadableJsonToProto(const string& str, protobuf::Message* proto);
Status HumanReadableJsonToProto(const string& str,
                                protobuf::MessageLite* proto);

}  // namespace tsl

#endif  // TENSORFLOW_TSL_PLATFORM_HUMAN_READABLE_JSON_H_
