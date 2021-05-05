// Generated by gencpp from file mobrob_util/ME439SensorsProcessed.msg
// DO NOT EDIT!


#ifndef MOBROB_UTIL_MESSAGE_ME439SENSORSPROCESSED_H
#define MOBROB_UTIL_MESSAGE_ME439SENSORSPROCESSED_H


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
struct ME439SensorsProcessed_
{
  typedef ME439SensorsProcessed_<ContainerAllocator> Type;

  ME439SensorsProcessed_()
    : e0radians(0.0)
    , e1radians(0.0)
    , e0meters(0.0)
    , e1meters(0.0)
    , e0radpersec(0.0)
    , e1radpersec(0.0)
    , e0meterspersec(0.0)
    , e1meterspersec(0.0)
    , a0(0.0)
    , a1(0.0)
    , a2(0.0)
    , a3(0.0)
    , a4(0.0)
    , a5(0.0)
    , u0meters(0.0)
    , u1meters(0.0)
    , u2meters(0.0)
    , dt()  {
    }
  ME439SensorsProcessed_(const ContainerAllocator& _alloc)
    : e0radians(0.0)
    , e1radians(0.0)
    , e0meters(0.0)
    , e1meters(0.0)
    , e0radpersec(0.0)
    , e1radpersec(0.0)
    , e0meterspersec(0.0)
    , e1meterspersec(0.0)
    , a0(0.0)
    , a1(0.0)
    , a2(0.0)
    , a3(0.0)
    , a4(0.0)
    , a5(0.0)
    , u0meters(0.0)
    , u1meters(0.0)
    , u2meters(0.0)
    , dt()  {
  (void)_alloc;
    }



   typedef float _e0radians_type;
  _e0radians_type e0radians;

   typedef float _e1radians_type;
  _e1radians_type e1radians;

   typedef float _e0meters_type;
  _e0meters_type e0meters;

   typedef float _e1meters_type;
  _e1meters_type e1meters;

   typedef float _e0radpersec_type;
  _e0radpersec_type e0radpersec;

   typedef float _e1radpersec_type;
  _e1radpersec_type e1radpersec;

   typedef float _e0meterspersec_type;
  _e0meterspersec_type e0meterspersec;

   typedef float _e1meterspersec_type;
  _e1meterspersec_type e1meterspersec;

   typedef float _a0_type;
  _a0_type a0;

   typedef float _a1_type;
  _a1_type a1;

   typedef float _a2_type;
  _a2_type a2;

   typedef float _a3_type;
  _a3_type a3;

   typedef float _a4_type;
  _a4_type a4;

   typedef float _a5_type;
  _a5_type a5;

   typedef float _u0meters_type;
  _u0meters_type u0meters;

   typedef float _u1meters_type;
  _u1meters_type u1meters;

   typedef float _u2meters_type;
  _u2meters_type u2meters;

   typedef ros::Duration _dt_type;
  _dt_type dt;





  typedef boost::shared_ptr< ::mobrob_util::ME439SensorsProcessed_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::mobrob_util::ME439SensorsProcessed_<ContainerAllocator> const> ConstPtr;

}; // struct ME439SensorsProcessed_

typedef ::mobrob_util::ME439SensorsProcessed_<std::allocator<void> > ME439SensorsProcessed;

typedef boost::shared_ptr< ::mobrob_util::ME439SensorsProcessed > ME439SensorsProcessedPtr;
typedef boost::shared_ptr< ::mobrob_util::ME439SensorsProcessed const> ME439SensorsProcessedConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::mobrob_util::ME439SensorsProcessed_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::mobrob_util::ME439SensorsProcessed_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::mobrob_util::ME439SensorsProcessed_<ContainerAllocator1> & lhs, const ::mobrob_util::ME439SensorsProcessed_<ContainerAllocator2> & rhs)
{
  return lhs.e0radians == rhs.e0radians &&
    lhs.e1radians == rhs.e1radians &&
    lhs.e0meters == rhs.e0meters &&
    lhs.e1meters == rhs.e1meters &&
    lhs.e0radpersec == rhs.e0radpersec &&
    lhs.e1radpersec == rhs.e1radpersec &&
    lhs.e0meterspersec == rhs.e0meterspersec &&
    lhs.e1meterspersec == rhs.e1meterspersec &&
    lhs.a0 == rhs.a0 &&
    lhs.a1 == rhs.a1 &&
    lhs.a2 == rhs.a2 &&
    lhs.a3 == rhs.a3 &&
    lhs.a4 == rhs.a4 &&
    lhs.a5 == rhs.a5 &&
    lhs.u0meters == rhs.u0meters &&
    lhs.u1meters == rhs.u1meters &&
    lhs.u2meters == rhs.u2meters &&
    lhs.dt == rhs.dt;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::mobrob_util::ME439SensorsProcessed_<ContainerAllocator1> & lhs, const ::mobrob_util::ME439SensorsProcessed_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace mobrob_util

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::mobrob_util::ME439SensorsProcessed_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::mobrob_util::ME439SensorsProcessed_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mobrob_util::ME439SensorsProcessed_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mobrob_util::ME439SensorsProcessed_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mobrob_util::ME439SensorsProcessed_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mobrob_util::ME439SensorsProcessed_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::mobrob_util::ME439SensorsProcessed_<ContainerAllocator> >
{
  static const char* value()
  {
    return "44afd1f89023a5ad6799a84d47e3ad41";
  }

  static const char* value(const ::mobrob_util::ME439SensorsProcessed_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x44afd1f89023a5adULL;
  static const uint64_t static_value2 = 0x6799a84d47e3ad41ULL;
};

template<class ContainerAllocator>
struct DataType< ::mobrob_util::ME439SensorsProcessed_<ContainerAllocator> >
{
  static const char* value()
  {
    return "mobrob_util/ME439SensorsProcessed";
  }

  static const char* value(const ::mobrob_util::ME439SensorsProcessed_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::mobrob_util::ME439SensorsProcessed_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 e0radians\n"
"float32 e1radians\n"
"float32 e0meters\n"
"float32 e1meters\n"
"float32 e0radpersec\n"
"float32 e1radpersec\n"
"float32 e0meterspersec\n"
"float32 e1meterspersec\n"
"float32 a0\n"
"float32 a1\n"
"float32 a2\n"
"float32 a3\n"
"float32 a4\n"
"float32 a5\n"
"float32 u0meters\n"
"float32 u1meters\n"
"float32 u2meters\n"
"duration dt\n"
;
  }

  static const char* value(const ::mobrob_util::ME439SensorsProcessed_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::mobrob_util::ME439SensorsProcessed_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.e0radians);
      stream.next(m.e1radians);
      stream.next(m.e0meters);
      stream.next(m.e1meters);
      stream.next(m.e0radpersec);
      stream.next(m.e1radpersec);
      stream.next(m.e0meterspersec);
      stream.next(m.e1meterspersec);
      stream.next(m.a0);
      stream.next(m.a1);
      stream.next(m.a2);
      stream.next(m.a3);
      stream.next(m.a4);
      stream.next(m.a5);
      stream.next(m.u0meters);
      stream.next(m.u1meters);
      stream.next(m.u2meters);
      stream.next(m.dt);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ME439SensorsProcessed_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::mobrob_util::ME439SensorsProcessed_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::mobrob_util::ME439SensorsProcessed_<ContainerAllocator>& v)
  {
    s << indent << "e0radians: ";
    Printer<float>::stream(s, indent + "  ", v.e0radians);
    s << indent << "e1radians: ";
    Printer<float>::stream(s, indent + "  ", v.e1radians);
    s << indent << "e0meters: ";
    Printer<float>::stream(s, indent + "  ", v.e0meters);
    s << indent << "e1meters: ";
    Printer<float>::stream(s, indent + "  ", v.e1meters);
    s << indent << "e0radpersec: ";
    Printer<float>::stream(s, indent + "  ", v.e0radpersec);
    s << indent << "e1radpersec: ";
    Printer<float>::stream(s, indent + "  ", v.e1radpersec);
    s << indent << "e0meterspersec: ";
    Printer<float>::stream(s, indent + "  ", v.e0meterspersec);
    s << indent << "e1meterspersec: ";
    Printer<float>::stream(s, indent + "  ", v.e1meterspersec);
    s << indent << "a0: ";
    Printer<float>::stream(s, indent + "  ", v.a0);
    s << indent << "a1: ";
    Printer<float>::stream(s, indent + "  ", v.a1);
    s << indent << "a2: ";
    Printer<float>::stream(s, indent + "  ", v.a2);
    s << indent << "a3: ";
    Printer<float>::stream(s, indent + "  ", v.a3);
    s << indent << "a4: ";
    Printer<float>::stream(s, indent + "  ", v.a4);
    s << indent << "a5: ";
    Printer<float>::stream(s, indent + "  ", v.a5);
    s << indent << "u0meters: ";
    Printer<float>::stream(s, indent + "  ", v.u0meters);
    s << indent << "u1meters: ";
    Printer<float>::stream(s, indent + "  ", v.u1meters);
    s << indent << "u2meters: ";
    Printer<float>::stream(s, indent + "  ", v.u2meters);
    s << indent << "dt: ";
    Printer<ros::Duration>::stream(s, indent + "  ", v.dt);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MOBROB_UTIL_MESSAGE_ME439SENSORSPROCESSED_H
