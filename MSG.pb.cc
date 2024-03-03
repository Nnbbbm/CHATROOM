// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MSG.proto

#include "MSG.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

class MSGDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<MSG> _instance;
} _MSG_default_instance_;
static void InitDefaultsMSG_MSG_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_MSG_default_instance_;
    new (ptr) ::MSG();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::MSG::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_MSG_MSG_2eproto =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsMSG_MSG_2eproto}, {}};

void InitDefaults_MSG_2eproto() {
  ::google::protobuf::internal::InitSCC(&scc_info_MSG_MSG_2eproto.base);
}

::google::protobuf::Metadata file_level_metadata_MSG_2eproto[1];
const ::google::protobuf::EnumDescriptor* file_level_enum_descriptors_MSG_2eproto[1];
constexpr ::google::protobuf::ServiceDescriptor const** file_level_service_descriptors_MSG_2eproto = nullptr;

const ::google::protobuf::uint32 TableStruct_MSG_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::MSG, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::MSG, type_),
  PROTOBUF_FIELD_OFFSET(::MSG, data_),
  PROTOBUF_FIELD_OFFSET(::MSG, from_),
  PROTOBUF_FIELD_OFFSET(::MSG, to_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::MSG)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::_MSG_default_instance_),
};

::google::protobuf::internal::AssignDescriptorsTable assign_descriptors_table_MSG_2eproto = {
  {}, AddDescriptors_MSG_2eproto, "MSG.proto", schemas,
  file_default_instances, TableStruct_MSG_2eproto::offsets,
  file_level_metadata_MSG_2eproto, 1, file_level_enum_descriptors_MSG_2eproto, file_level_service_descriptors_MSG_2eproto,
};

const char descriptor_table_protodef_MSG_2eproto[] =
  "\n\tMSG.proto\"B\n\003MSG\022\023\n\004type\030\001 \001(\0162\005.TYPE\022"
  "\014\n\004data\030\002 \001(\014\022\014\n\004from\030\003 \001(\014\022\n\n\002to\030\004 \001(\014*"
  "\300\001\n\004TYPE\022\017\n\013CLIENT_QUIT\020\000\022\025\n\021CLIENT_ENTE"
  "R_ROOM\020\001\022\025\n\021CLIENT_LEAVE_ROOM\020\002\022\020\n\014CLIEN"
  "T_LOGIN\020\003\022\024\n\020CLIENT_LOGIN_YES\020\004\022\023\n\017CLIEN"
  "T_LOGIN_NO\020\005\022\r\n\tTEXT_DATA\020\006\022\017\n\013SERVER_HI"
  "NT\020\007\022\014\n\010ROOM_NUM\020\010\022\016\n\nROOM_NAMES\020\tb\006prot"
  "o3"
  ;
::google::protobuf::internal::DescriptorTable descriptor_table_MSG_2eproto = {
  false, InitDefaults_MSG_2eproto, 
  descriptor_table_protodef_MSG_2eproto,
  "MSG.proto", &assign_descriptors_table_MSG_2eproto, 282,
};

void AddDescriptors_MSG_2eproto() {
  static constexpr ::google::protobuf::internal::InitFunc deps[1] =
  {
  };
 ::google::protobuf::internal::AddDescriptors(&descriptor_table_MSG_2eproto, deps, 0);
}

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_MSG_2eproto = []() { AddDescriptors_MSG_2eproto(); return true; }();
const ::google::protobuf::EnumDescriptor* TYPE_descriptor() {
  ::google::protobuf::internal::AssignDescriptors(&assign_descriptors_table_MSG_2eproto);
  return file_level_enum_descriptors_MSG_2eproto[0];
}
bool TYPE_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
      return true;
    default:
      return false;
  }
}


// ===================================================================

void MSG::InitAsDefaultInstance() {
}
class MSG::HasBitSetters {
 public:
};

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int MSG::kTypeFieldNumber;
const int MSG::kDataFieldNumber;
const int MSG::kFromFieldNumber;
const int MSG::kToFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

MSG::MSG()
  : ::google::protobuf::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:MSG)
}
MSG::MSG(const MSG& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(nullptr) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  data_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.data().size() > 0) {
    data_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.data_);
  }
  from_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.from().size() > 0) {
    from_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.from_);
  }
  to_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.to().size() > 0) {
    to_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.to_);
  }
  type_ = from.type_;
  // @@protoc_insertion_point(copy_constructor:MSG)
}

void MSG::SharedCtor() {
  ::google::protobuf::internal::InitSCC(
      &scc_info_MSG_MSG_2eproto.base);
  data_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  from_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  to_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  type_ = 0;
}

MSG::~MSG() {
  // @@protoc_insertion_point(destructor:MSG)
  SharedDtor();
}

void MSG::SharedDtor() {
  data_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  from_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  to_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void MSG::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const MSG& MSG::default_instance() {
  ::google::protobuf::internal::InitSCC(&::scc_info_MSG_MSG_2eproto.base);
  return *internal_default_instance();
}


void MSG::Clear() {
// @@protoc_insertion_point(message_clear_start:MSG)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  data_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  from_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  to_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  type_ = 0;
  _internal_metadata_.Clear();
}

#if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
const char* MSG::_InternalParse(const char* begin, const char* end, void* object,
                  ::google::protobuf::internal::ParseContext* ctx) {
  auto msg = static_cast<MSG*>(object);
  ::google::protobuf::int32 size; (void)size;
  int depth; (void)depth;
  ::google::protobuf::uint32 tag;
  ::google::protobuf::internal::ParseFunc parser_till_end; (void)parser_till_end;
  auto ptr = begin;
  while (ptr < end) {
    ptr = ::google::protobuf::io::Parse32(ptr, &tag);
    GOOGLE_PROTOBUF_PARSER_ASSERT(ptr);
    switch (tag >> 3) {
      // .TYPE type = 1;
      case 1: {
        if (static_cast<::google::protobuf::uint8>(tag) != 8) goto handle_unusual;
        ::google::protobuf::uint64 val = ::google::protobuf::internal::ReadVarint(&ptr);
        msg->set_type(static_cast<::TYPE>(val));
        GOOGLE_PROTOBUF_PARSER_ASSERT(ptr);
        break;
      }
      // bytes data = 2;
      case 2: {
        if (static_cast<::google::protobuf::uint8>(tag) != 18) goto handle_unusual;
        ptr = ::google::protobuf::io::ReadSize(ptr, &size);
        GOOGLE_PROTOBUF_PARSER_ASSERT(ptr);
        object = msg->mutable_data();
        if (size > end - ptr + ::google::protobuf::internal::ParseContext::kSlopBytes) {
          parser_till_end = ::google::protobuf::internal::GreedyStringParser;
          goto string_till_end;
        }
        GOOGLE_PROTOBUF_PARSER_ASSERT(::google::protobuf::internal::StringCheck(ptr, size, ctx));
        ::google::protobuf::internal::InlineGreedyStringParser(object, ptr, size, ctx);
        ptr += size;
        break;
      }
      // bytes from = 3;
      case 3: {
        if (static_cast<::google::protobuf::uint8>(tag) != 26) goto handle_unusual;
        ptr = ::google::protobuf::io::ReadSize(ptr, &size);
        GOOGLE_PROTOBUF_PARSER_ASSERT(ptr);
        object = msg->mutable_from();
        if (size > end - ptr + ::google::protobuf::internal::ParseContext::kSlopBytes) {
          parser_till_end = ::google::protobuf::internal::GreedyStringParser;
          goto string_till_end;
        }
        GOOGLE_PROTOBUF_PARSER_ASSERT(::google::protobuf::internal::StringCheck(ptr, size, ctx));
        ::google::protobuf::internal::InlineGreedyStringParser(object, ptr, size, ctx);
        ptr += size;
        break;
      }
      // bytes to = 4;
      case 4: {
        if (static_cast<::google::protobuf::uint8>(tag) != 34) goto handle_unusual;
        ptr = ::google::protobuf::io::ReadSize(ptr, &size);
        GOOGLE_PROTOBUF_PARSER_ASSERT(ptr);
        object = msg->mutable_to();
        if (size > end - ptr + ::google::protobuf::internal::ParseContext::kSlopBytes) {
          parser_till_end = ::google::protobuf::internal::GreedyStringParser;
          goto string_till_end;
        }
        GOOGLE_PROTOBUF_PARSER_ASSERT(::google::protobuf::internal::StringCheck(ptr, size, ctx));
        ::google::protobuf::internal::InlineGreedyStringParser(object, ptr, size, ctx);
        ptr += size;
        break;
      }
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->EndGroup(tag);
          return ptr;
        }
        auto res = UnknownFieldParse(tag, {_InternalParse, msg},
          ptr, end, msg->_internal_metadata_.mutable_unknown_fields(), ctx);
        ptr = res.first;
        GOOGLE_PROTOBUF_PARSER_ASSERT(ptr != nullptr);
        if (res.second) return ptr;
      }
    }  // switch
  }  // while
  return ptr;
string_till_end:
  static_cast<::std::string*>(object)->clear();
  static_cast<::std::string*>(object)->reserve(size);
  goto len_delim_till_end;
len_delim_till_end:
  return ctx->StoreAndTailCall(ptr, end, {_InternalParse, msg},
                               {parser_till_end, object}, size);
}
#else  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
bool MSG::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!PROTOBUF_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:MSG)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // .TYPE type = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) == (8 & 0xFF)) {
          int value = 0;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          set_type(static_cast< ::TYPE >(value));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // bytes data = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) == (18 & 0xFF)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_data()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // bytes from = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) == (26 & 0xFF)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_from()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // bytes to = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) == (34 & 0xFF)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_to()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:MSG)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:MSG)
  return false;
#undef DO_
}
#endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER

void MSG::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:MSG)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .TYPE type = 1;
  if (this->type() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      1, this->type(), output);
  }

  // bytes data = 2;
  if (this->data().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      2, this->data(), output);
  }

  // bytes from = 3;
  if (this->from().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      3, this->from(), output);
  }

  // bytes to = 4;
  if (this->to().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      4, this->to(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:MSG)
}

::google::protobuf::uint8* MSG::InternalSerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:MSG)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .TYPE type = 1;
  if (this->type() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      1, this->type(), target);
  }

  // bytes data = 2;
  if (this->data().size() > 0) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        2, this->data(), target);
  }

  // bytes from = 3;
  if (this->from().size() > 0) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        3, this->from(), target);
  }

  // bytes to = 4;
  if (this->to().size() > 0) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        4, this->to(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:MSG)
  return target;
}

size_t MSG::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:MSG)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // bytes data = 2;
  if (this->data().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::BytesSize(
        this->data());
  }

  // bytes from = 3;
  if (this->from().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::BytesSize(
        this->from());
  }

  // bytes to = 4;
  if (this->to().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::BytesSize(
        this->to());
  }

  // .TYPE type = 1;
  if (this->type() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::EnumSize(this->type());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void MSG::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:MSG)
  GOOGLE_DCHECK_NE(&from, this);
  const MSG* source =
      ::google::protobuf::DynamicCastToGenerated<MSG>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:MSG)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:MSG)
    MergeFrom(*source);
  }
}

void MSG::MergeFrom(const MSG& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:MSG)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.data().size() > 0) {

    data_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.data_);
  }
  if (from.from().size() > 0) {

    from_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.from_);
  }
  if (from.to().size() > 0) {

    to_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.to_);
  }
  if (from.type() != 0) {
    set_type(from.type());
  }
}

void MSG::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:MSG)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MSG::CopyFrom(const MSG& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:MSG)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MSG::IsInitialized() const {
  return true;
}

void MSG::Swap(MSG* other) {
  if (other == this) return;
  InternalSwap(other);
}
void MSG::InternalSwap(MSG* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  data_.Swap(&other->data_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  from_.Swap(&other->from_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  to_.Swap(&other->to_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(type_, other->type_);
}

::google::protobuf::Metadata MSG::GetMetadata() const {
  ::google::protobuf::internal::AssignDescriptors(&::assign_descriptors_table_MSG_2eproto);
  return ::file_level_metadata_MSG_2eproto[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
namespace google {
namespace protobuf {
template<> PROTOBUF_NOINLINE ::MSG* Arena::CreateMaybeMessage< ::MSG >(Arena* arena) {
  return Arena::CreateInternal< ::MSG >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>