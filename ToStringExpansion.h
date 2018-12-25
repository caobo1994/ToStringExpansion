#ifndef TOSTRINGEXPANSION_CAOBO1994_H
#define TOSTRINGEXPANSION_CAOBO1994_H

#include <cmath>

#include <string>

#include <algorithm>
#include <numeric>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <utility>

#include <iomanip>
#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>

#include <memory>

#include <typeinfo>

namespace std
{
  //Declarations
  std::string to_string(const std::string& str);
  std::string to_string(const YAML::Node& str);

  template <class T0, class T1> /* pair */
  std::string to_string(const std::pair<T0, T1>& value);

  template <class It>
  std::string castList2String(It begin, It end, const std::string& header, const std::string& separator, const std::string& closer);

  template <class T> /* vector */
  std::string to_string(const std::vector<T>& value);

  template <class T> /* deque */
  std::string to_string(const std::deque<T>& value);

  template <class T> /* forward_list */
  std::string to_string(const std::forward_list<T>& value);

  template <class T> /* list */
  std::string to_string(const std::list<T>& value);

  template <class T> /* set */
  std::string to_string(const std::set<T>& value);

  template <class T> /* multiset */
  std::string to_string(const std::multiset<T>& value);

  template <class T> /* unordered_set */
  std::string to_string(const std::unordered_set<T>& value);

  template <class T> /* unordered_multiset */
  std::string to_string(const std::unordered_multiset<T>& value);

  template <class It>
  std::string castMap2String(It begin, It end, const std::string& header, const std::string& pair_header, const std::string& connector);

  template <class K, class V> /* map */
  std::string to_string(const std::map<K, V>& value);

  template <class K, class V> /* multimap */
  std::string to_string(const std::multimap<K, V>& value);

  template <class K, class V> /* unordered_map */
  std::string to_string(const std::unordered_map<K, V>& value);

  template <class K, class V> /* unordered_multimap*/
  std::string to_string(const std::unordered_multimap<K, V>& value);

  //Definitions
  template <class T0, class T1> /* pair */
  std::string to_string(const std::pair<T0, T1>& value)
  {
    std::string str = " ( ";
    str += std::to_string(value.first);
    str += std::to_string(value.second);
    str += " ) ";
    return str;
  }

  template <class It>
  std::string castList2String(It begin, It end, const std::string& header, const std::string& separator, const std::string& closer)
  {
    std::string str = header;
    for (auto v = begin; v != end; ++v)
    {
      str += separator + std::to_string(*v);
    }
    str += separator;
    str += closer;
    return str;
  }

  template <class T> /* vector */
  std::string to_string(const std::vector<T>& value)
  {
    return castList2String(value.begin(), value.end(), "std::vector[", " ", "]");
  }

  template <class T> /* deque */
  std::string to_string(const std::deque<T>& value)
  {
    return castList2String(value.begin(), value.end(), "std::deque{", " ", "}");
  }

  template <class T> /* forward_list */
  std::string to_string(const std::forward_list<T>& value)
  {
    return castList2String(value.begin(), value.end(), "std::forward_list{", " ", "}");
  }

  template <class T> /* list */
  std::string to_string(const std::list<T>& value)
  {
    return castList2String(value.begin(), value.end(), "std::list{", " ", "}");
  }

  template <class T> /* set */
  std::string to_string(const std::set<T>& value)
  {
    return castList2String(value.begin(), value.end(), "std::set{", " ", "}");
  }

  template <class T> /* multiset */
  std::string to_string(const std::multiset<T>& value)
  {
    return castList2String(value.begin(), value.end(), "std::multiset{", " ", "}");
  }

  template <class T> /* unordered_set */
  std::string to_string(const std::unordered_set<T>& value)
  {
    return castList2String(value.begin(), value.end(), "std::unordered_set{", " ", "}");
  }

  template <class T> /* unordered_multiset */
  std::string to_string(const std::unordered_multiset<T>& value)
  {
    return castList2String(value.begin(), value.end(), "std::unordered_multiset{", " ", "}");
  }

  template <class It>
  std::string castMap2String(It begin, It end, const std::string& header, const std::string& pair_header, const std::string& connector)
  {
    std::string str = header;
    for (auto v = begin; v != end; ++v)
    {
      str +=
          "\n " + pair_header + " " + std::to_string(v->first) + " " + connector + " " + std::to_string(v->second);
    }
    str += "\n\n";
    return str;
  }

  template <class K, class V> /* map */
  std::string to_string(const std::map<K, V>& value)
  {
    return castMap2String(value.begin(), value.end(), "std::map", "-", ":");
  }

  template <class K, class V> /* multimap */
  std::string to_string(const std::multimap<K, V>& value)
  {
    return castMap2String(value.begin(), value.end(), "std::multimap", "-", ":");
  }

  template <class K, class V> /* unordered_map*/
  std::string to_string(const std::unordered_map<K, V>& value)
  {
    return castMap2String(value.begin(), value.end(), "std::unordered_map", "-", ":");
  }

  template <class K, class V> /* unordered_multimap*/
  std::string to_string(const std::unordered_multimap<K, V>& value)
  {
    return castMap2String(value.begin(), value.end(), "std::unordered_multimap", "-", ":");
  }
}
#endif
