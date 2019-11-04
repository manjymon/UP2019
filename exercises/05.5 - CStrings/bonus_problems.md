# 05 - CStrings

## Notes

Feel free to copy paste some array algorithms and change the types to char[]

## 01 - Reverse words

Given a sentence where every word is separated by a single interval, reverse the individual words in the sentence, without reversing their order.

Return the reversed sentence.

### Example

```c++
char sentence[100]{"Turn that frown upside down :("};
std::cout << reverse_words(sentence); // nruT taht nworf edispu nwod (:
```

## 02 - String to Int

Given a string that starts with an integer, return the integer and ignore the rest of the string

### Example

```c++
std::cout << atoi("123filler") + atoi("-81morefiller") << '\n'; // 42
```

## 03 - Run Length Decode

Given a string that contains numbers and lowercase latin characters, "decode" the string by replacing every instance of {number}{character} in the string with {number} copies of {character}. Write the new string in a given buffer and return the new buffer.

### Example

```c++
char buffer[100]{};
std::cout << run_length_decode(buffer, "a2b10c"); // abbcccccccccc
```
