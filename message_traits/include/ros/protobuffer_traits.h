/*
 * Copyright (C) 2009, Willow Garage, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the names of Willow Garage, Inc. nor the names of its
 *     contributors may be used to endorse or promote products derived from
 *     this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef ROSLIB_PROTOBUFFER_TRAITS_H
#define ROSLIB_PROTOBUFFER_TRAITS_H

#include <map>
#include <string>
#include <typeinfo>

#include <google/protobuf/descriptor.h>
#include <google/protobuf/message.h>
#include <ros/time.h>

#include "message_forward.h"
#include "message_traits.h"

namespace ros {
namespace message_traits {
// protobuffer trait
// static std::map<std::string, std::string> type_md5_map;

template <typename T>
struct DataType<T, typename std::enable_if<std::is_base_of<
                       ::google::protobuf::Message, T>::value>::type> {
  static const char* value() {
    static std::string data_type = "";
    data_type = "pb_msgs/" + T::descriptor()->name();
    return data_type.c_str();
  }
  static const char* value(const T&) { return value(); }
};

template <typename T>
struct MD5Sum<T, typename std::enable_if<std::is_base_of<
                     ::google::protobuf::Message, T>::value>::type> {
  static const char* value() { return "proto_md5"; }
  static const char* value(const T&) { return value(); }
};

template <typename T>
struct Definition<T, typename std::enable_if<std::is_base_of<
                         ::google::protobuf::Message, T>::value>::type> {
  static const char* value() {
    const google::protobuf::Descriptor* descriptor = T::descriptor();

    static std::string des;
    static std::atomic<bool> flag{false};

    if (flag) {
      return des.c_str();
    }
    if (descriptor) {
      des.append("\n================\n");
      des.append("file_name: ");
      des.append(descriptor->file()->name());
      des.append(";\n");
      des.append("proto name: ");
      des.append(descriptor->full_name());
      des.append(";\n");

      // for (int i = 0; i < descriptor->field_count(); ++i) {
      //   const google::protobuf::FieldDescriptor* field =
      //   descriptor->field(i); std::cout << "Field name: " << field->name()
      //             << ", type: " << field->type()
      //             << "file: " << field->file()->name() << std::endl;
      //   des.append("value_name: ");
      //   des.append(field->name());
      //   des.append("; ");
      //   des.append("type: ");
      //   des.append(google::protobuf::FieldDescriptor::TypeName(field->type()));
      //   des.append(";\n");
      // }
      des.append(descriptor->DebugString());
      des.append("================\n");
      flag = true;
    } else {
      std::cout << "Descriptor is null." << std::endl;
    }

    return des.c_str();
  }
  static const char* value(const T&) { return value(); }
};

template <typename T>
struct HasHeader<T, typename std::enable_if<std::is_base_of<
                        ::google::protobuf::Message, T>::value>::type>
    : FalseType {};

template <typename T>
struct HasHeader<T const, typename std::enable_if<std::is_base_of<
                              ::google::protobuf::Message, T>::value>::type>
    : FalseType {};

template <typename T>
struct IsFixedSize<T, typename std::enable_if<std::is_base_of<
                          ::google::protobuf::Message, T>::value>::type>
    : FalseType {};

template <typename T>
struct IsFixedSize<T const, typename std::enable_if<std::is_base_of<
                                ::google::protobuf::Message, T>::value>::type>
    : FalseType {};

template <typename T>
struct IsMessage<T, typename std::enable_if<std::is_base_of<
                        ::google::protobuf::Message, T>::value>::type>
    : TrueType {};

template <typename T>
struct IsMessage<T const, typename std::enable_if<std::is_base_of<
                              ::google::protobuf::Message, T>::value>::type>
    : TrueType {};

}  // namespace message_traits
}  // namespace ros

#endif  // ROSLIB_MESSAGE_TRAITS_H
