def printSequence(str, input):
    n = len(input)
    output = ""
    input=input.upper()
    for i in range(n):
        if input[i] == " ":
            output = output + "0"
        else:
            position = ord(input[i]) - ord('A')
            output = output + str[position]
    return output


str = ["2", "22", "222",
       "3", "33", "333",
       "4", "44", "444",
       "5", "55", "555",
       "6", "66", "666",
       "7", "77", "777", "7777",
       "8", "88", "888",
       "9", "99", "999", "9999"]
 
input = "Prakhar"
print(printSequence(str, input))


# code in c++
# #include <iostream>
# #include <vector>
# #include <string>
# #include <cctype> // for toupper

# using namespace std;

# string printSequence(vector<string> &str, string input) {
#     int n = input.length();
#     string output = "";

#     for (int i = 0; i < n; ++i) {
#         if (input[i] == ' ') {
#             output += "0";
#         } else {
#             int position = toupper(input[i]) - 'A';
#             output += str[position];
#         }
#     }

#     return output;
# }

# int main() {
#     vector<string> str = {"2", "22", "222",
#                           "3", "33", "333",
#                           "4", "44", "444",
#                           "5", "55", "555",
#                           "6", "66", "666",
#                           "7", "77", "777", "7777",
#                           "8", "88", "888",
#                           "9", "99", "999", "9999"};
 
#     string input = "Prakhar";
#     cout << printSequence(str, input) << endl;

#     return 0;
# }
