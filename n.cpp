#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int> &arr)
{
    int last_element = arr.back();
    arr.pop_back();
    arr.insert(arr.begin(), last_element);
}

string isomorphMatrix(string s)
{
    int sizeOfString = s.size();
    vector<int> temp;
    map<char, int> charMap;
    int uniqueCharCount = 0;
    for (char c : s)
    {
        if (charMap.find(c) == charMap.end())
        {
            charMap[c] = uniqueCharCount++;
        }
        temp.push_back(charMap[c]);
    }

    vector<vector<int>> tempArr(sizeOfString, vector<int>(sizeOfString));

    for (int i = 0; i < sizeOfString; i++)
    {
        for (int j = 0; j < sizeOfString; j++)
        {
            tempArr[i][j] = temp[j];
        }
        rotate(temp);
    }

    string matrixString = s;
    for (int i = 0; i < sizeOfString; i++)
    {
        for (int j = 0; j < sizeOfString; j++)
        {
            matrixString += to_string(tempArr[i][j]);
        }
    }

    return matrixString;
}

size_t calcHash(string s)
{
    size_t p = 31;
    size_t m = 1e9 + 9;
    size_t hash_value = 0;
    size_t p_pow = 1;
    for (char c : s)
    {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

int main()
{
    string password = "egg";
    string matrixString = isomorphMatrix(password);
    size_t hashValue = calcHash(matrixString);
    cout << hashValue;
    return 0;
}