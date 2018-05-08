cmake_minimum_required(VERSION 3.9)
project(LeetCode)

set(CMAKE_CXX_STANDARD 11)

add_executable(LeetCode add.h jzoffer/effective.cpp jzoffer/string.cpp jzoffer/array.cpp jzoffer/list.cpp jzoffer/sort.cpp jzoffer/find.cpp jzoffer/tree.cpp jzoffer/Main.cpp _001_TwoSum.cpp Main.cpp _167_TwoSumII.cpp _002_AddTwoNumbers.cpp Algorithms4/Sort.cpp Algorithms4/Sort.h jzoffer/dp.cpp _003_LongestSubstringWithoutRepeatingCharacters.cpp _005_LongestPalindroicSubstring.cpp _048_RotateImage.cpp _022_GenerateParentheses.cpp)