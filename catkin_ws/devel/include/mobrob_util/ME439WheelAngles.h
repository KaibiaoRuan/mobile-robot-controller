// Generated by gencpp from file mobrob_util/ME439WheelAngles.msg
// DO NOT EDIT!


#ifndef MOBROB_UTIL_MESSAGE_ME439WHEELANGLES_H
#define MOBROB_UTIL_MESSAGE_ME439WHEELANGLES_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace mobrob_util
{
template <class ContainerAllocator>
struct ME439WheelAngles_
{
  typedef ME439WheelAngles_<ContainerAllocator> Type;

  ME439WheelAngles_()
    : ang_left(0.0)
    , ang_right(0.0)  {
    }
  ME439WheelAngles_(const ContainerAllocator& _alloc)
    : ang_left(0.0)
    , ang_right(0.0)  {
  (void)_alloc;
    }



   typedef double _ang_left_type;
  _ang_left_type ang_left;

   typedef double _ang_right_type;
  _ang_right_type ang_right;





  typedef boost::shared_ptr< ::mobrob_util::ME439WheelAngles_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::mobrob_util::ME439WheelAngles_<ContainerAllocator> const> ConstPtr;

}; // struct ME439WheelAngles_

typedef ::mobrob_util::ME439WheelAngles_<std::allocator<void> > ME439WheelAngles;

typedef boost::shared_ptr< ::mobrob_util::ME439WheelAngles > ME439WheelAnglesPtr;
typedef boost::shared_ptr< ::mobrob_util::ME439WheelAngles const> ME439WheelAnglesConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::mobrob_util::ME439WheelAngles_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::mobrob_util::ME439WheelAngles_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::mobrob_util::ME439WheelAngles_<ContainerAllocator1> & lhs, const ::mobrob_util::ME439WheelAngles_<ContainerAllocator2> & rhs)
{
  return lhs.ang_left == rhs.ang_left &&
    lhs.ang_right == rhs.ang_right;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::mobrob_util::ME439WheelAngles_<ContainerAllocator1> & lhs, const ::mobrob_util::ME439WheelAngles_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace mobrob_util

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::mobrob_util::ME439WheelAngles_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::mobrob_util::ME439WheelAngles_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mobrob_util::ME439WheelAngles_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mobrob_util::ME439WheelAngles_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mobrob_util::ME439WheelAngles_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mobrob_util::ME439WheelAngles_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::mobrob_util::ME439WheelAngles_<ContainerAllocator> >
{
  static const char* value()
  {
    return "8e9b84200a184649eafa090ea3ef1869";
  }

  static const char* value(const ::mobrob_util::ME439WheelAngles_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x8e9b84200a184649ULL;
  static const uint64_t static_value2 = 0xeafa090ea3ef1869ULL;
};

template<class ContainerAllocator>
struct DataType< ::mobrob_util::ME439WheelAngles_<ContainerAllocator> >
{
  static const char* value()
  {
    return "mobrob_util/ME439WheelAngles";
  }

  static const char* value(const ::mobrob_util::ME439WheelAngles_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::mobrob_util::ME439WheelAngles_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64 ang_left\n"
"float64 ang_right\n"
;
  }

  static const char* value(const ::mobrob_util::ME439WheelAngles_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::mobrob_util::ME439WheelAngles_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.ang_left);
      stream.next(m.ang_right);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ME439WheelAngles_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::mobrob_util::ME439WheelAngles_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::mobrob_util::ME439WheelAngles_<ContainerAllocator>& v)
  {
    s << indent << "ang_left: ";
    Printer<double>::stream(s, indent + "  ", v.ang_left);
    s << indent << "ang_right: ";
    Printer<double>::stream(s, indent + "  ", v.ang_right);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MOBROB_UTIL_MESSAGE_ME439WHEELANGLES_H
