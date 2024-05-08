# stl_numeric

## `std::accumulate`

- 有序相加

```C++
// C++20后，重载1
template< class InputIt, class T >
constexpr T accumulate( InputIt first, InputIt last, T init );
// C++20后，重载2
template< class InputIt, class T, class BinaryOperation >
constexpr T accumulate( InputIt first, InputIt last, T init, BinaryOperation op );z
```

## `std::reduce`

- 无序相加
- C++17新增
- 较 `accumulate` 更快

```C++
// C++17~C++20，重载1
template<class InputIt>
typename std::iterator_traits<InputIt>::value_type reduce(InputIt first, InputIt last);
```
