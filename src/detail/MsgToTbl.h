#ifndef DETAIL_MSGTOTBL_H
#define DETAIL_MSGTOTBL_H

struct lua_State;

namespace LuaIntf {
class LuaRef;
}  // namespace LuaIntf

namespace google {
namespace protobuf {
class Message;
// DEL class Descriptor;
class Reflection;
class FieldDescriptor;
}  // namespace protobuf
}  // namespace google

// Message to lua table convertor.
class MsgToTbl final
{
public:
    explicit MsgToTbl(lua_State& rLuaState,
        const google::protobuf::Message& msg);

public:
    using LuaRef = LuaIntf::LuaRef;

    LuaRef ToTbl() const;

private:
    using FieldDescriptor = google::protobuf::FieldDescriptor;

    LuaRef GetField(const FieldDescriptor& field) const;
    LuaRef GetRepeatedField(const FieldDescriptor& field) const;
    // index starts from 0.
    LuaRef GetRepeatedFieldElement(const FieldDescriptor& field, int index) const;

private:
    lua_State& m_rLuaState;
    const google::protobuf::Message& m_msg;
    // DEL const google::protobuf::Descriptor* m_pDesc;  // = msg.GetDescriptor();
    const google::protobuf::Reflection* m_pRefl;  // = msg.GetReflection();
};

#endif  // DETAIL_MSGTOTBL_H