#include <iomanip>
#include <iostream>

#include "superbai.pb.h"

void PrintHex(const std::string& str) {
  for (const unsigned char c : str) {
    std::cout << std::hex << std::setw(2) << std::setfill('0')
              << static_cast<int>(c);
  }
  std::cout << std::endl;
}

int main() {
  // std::string pb_str;
  // superbai::sample::RosProtoTest proto_test;
  // 0801
  // 0000 1000 0000 0001
  // tag-value
  // tag 的二进制：000 1 000
  //  wire_type的二进制： 000  0
  // field_num的二进制：0001     1
  // int32 num = 1;
  // wire_type : 0
  // field_num : 1

  // 08c801
  //  0000 1000    c801

  // a00601
  // 1010 0000 0000 0110 0000 0001
  // 010 0000 000 0110
  // 000 01100100  000

  // proto_test.set_num(1);

  // 12087375706572626169
  // 0001 0010 0000 1000 01110011 0111 0101 01110000011001010111001
  // tag: 001 0 010
  // len: 000 1000 8
  // value:01110011 ---115   s
  // 0111 0101 ---117 u

  // proto_test.set_name("superbai");
  // proto_test.SerializeToString(&pb_str);
  // PrintHex(pb_str);

  std::string des;
  const google::protobuf::Descriptor* descriptor =
      superbai::sample::RosProtoTest::descriptor();
  for (int i = 0; i < descriptor->field_count(); ++i) {
    const google::protobuf::FieldDescriptor* field = descriptor->field(i);

    des.append("value_name: ");
    des.append(field->name());
    des.append("; ");
    des.append("type: ");
    des.append(google::protobuf::FieldDescriptor::TypeName(field->type()));
    des.append(";\n");
  }
  std::cout << des << std::endl;
}