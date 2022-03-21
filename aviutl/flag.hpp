#pragma once
#include <type_traits>
#include <concepts>

namespace AviUtl {
    namespace detail::flag {
        template<class T1, class T2 = T1>struct ops_def:std::false_type{};

        template<class T>
        concept enum_c = std::is_enum_v<T>;

        template<class T1, class T2 = T1>
        concept defined = ops_def<T1, T2>::value || ops_def<T2, T1>::value;

        template<class T> constexpr auto to_underlying(T x) { return x; }
        template<enum_c T> constexpr auto to_underlying(T x) { return static_cast<std::underlying_type_t<T>>(x); }
        
        template<class T> using my_underlying_type_t = decltype(to_underlying(std::declval<T>));

        template<class T1, class T2 = T1>
        using flag_result_t = std::conditional_t<std::is_enum_v<T1>, T1, T2>;

        template<class T1, class T2 = T1>
        concept is_enable = defined<T1, T2> && std::same_as<my_underlying_type_t<T1>, my_underlying_type_t<T2>>;

        template<class T1, class T2, class T3>
        concept is_enable_tri = is_enable<T1, T2> && is_enable<T2, T3> && is_enable<T3, T1>;


        template<class T> requires is_enable<T> constexpr bool operator!(T x) { return to_underlying(x) == 0; }
        template<class T> requires is_enable<T> constexpr auto operator+(T x) { return to_underlying(x); }
        template<class T> requires is_enable<T> constexpr T operator~(T x) { return static_cast<T>(~to_underlying(x)); }
        
        template<class T1, class T2> requires is_enable<T1, T2> constexpr auto operator&(T1 x, T2 y) { return static_cast<flag_result_t<T1, T2>>(to_underlying(x) & to_underlying(y)); }
        template<class T1, class T2> requires is_enable<T1, T2> constexpr auto operator|(T1 x, T2 y) { return static_cast<flag_result_t<T1, T2>>(to_underlying(x) | to_underlying(y)); }
        template<class T1, class T2> requires is_enable<T1, T2> constexpr auto operator^(T1 x, T2 y) { return static_cast<flag_result_t<T1, T2>>(to_underlying(x) ^ to_underlying(y)); }

        template<class T1, class T2> requires is_enable<T1, T2> constexpr T1& operator&=(T1& x, T2 y) { return x = static_cast<T1>(to_underlying(x) & to_underlying(y)); }
        template<class T1, class T2> requires is_enable<T1, T2> constexpr T1& operator|=(T1& x, T2 y) { return x = static_cast<T1>(to_underlying(x) | to_underlying(y)); }
        template<class T1, class T2> requires is_enable<T1, T2> constexpr T1& operator^=(T1& x, T2 y) { return x = static_cast<T1>(to_underlying(x) ^ to_underlying(y)); }

        template<class T1, class T2> requires is_enable<T1, T2> constexpr bool has_flag_or(T1 x, T2 y) { return (to_underlying(x) & to_underlying(y)) != 0; }
        template<class T1, class T2> requires is_enable<T1, T2> constexpr bool has_flag_and(T1 x, T2 y) { return (to_underlying(x) & to_underlying(y)) == to_underlying(y); }
        template<class T1, class T2> requires is_enable<T1, T2> constexpr bool has_flag(T1 x, T2 y) { return has_flag_and(x, y); }
        template<class T1, class T2, class T3> requires is_enable_tri<T1, T2, T3> constexpr bool masked_eq(T1 x, T2 y, T3 mask) { return (to_underlying(x) ^ to_underlying(y)) & to_underlying(mask); }
    }
}

using AviUtl::detail::flag::operator!;
using AviUtl::detail::flag::operator+;
using AviUtl::detail::flag::operator~;
using AviUtl::detail::flag::operator&;
using AviUtl::detail::flag::operator|;
using AviUtl::detail::flag::operator^;
using AviUtl::detail::flag::operator&=;
using AviUtl::detail::flag::operator|=;
using AviUtl::detail::flag::operator^=;
using AviUtl::detail::flag::has_flag;
using AviUtl::detail::flag::has_flag_and;
using AviUtl::detail::flag::has_flag_or;
using AviUtl::detail::flag::masked_eq;
