// string::assign
#include <iostream>
#include <string>
#include <bits/stdc++.h>

int main ()
{
  std::string str;
  std::string base="The quick brown fox jumps over a lazy dog.";

  // used in the same order as described above:

  str.assign(base);
  std::cout << str << '\n';

  str.assign(base,10,9);
  std::cout << str << '\n';         // "brown fox"

  str.assign("pangrams are cool",7);
  std::cout << str << '\n';         // "pangram"

  str.assign("c-string");
  std::cout << str << '\n';         // "c-string"

  str.assign(10,'*');
  std::cout << str << '\n';         // "**********"

//   str.assign<int>(10,0x2D);
//   std::cout << str << '\n';         // "----------"

  str.assign(base.begin()+16,base.end()-12);
  std::cout << str << '\n';         // "fox jumps over"

  // tolower(char);

  when define 
  char str[];
  strlen(str) // xd length of str
 str.length()

  size_t or auto found = srt.find("string");
  found != string::npos ===> find "string"

  string substr (size_t pos = 0, size_t len = npos) const;
  std::string str="We think in generalities, but we live in details.";
                                           // (quoting Alfred N. Whitehead)cnn

  std::string str2 = str.substr (3,5);     // "think"
  std::size_t pos = str.find("live");      // position of "live" in str
  std::string str3 = str.substr (pos);     // get from "live" to the end
  std::cout << str2 << ' ' << str3 << '\n';

  lower_bound(v.begin(), v.end(), a[i]) - v.begin())
  

  return 0;
}