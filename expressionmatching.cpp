//
// Created by Yi Yang on 2018/8/30.
//

#include "expressionmatching.h"
bool matching::ismatch(string s, string p) {
    bool **f;//s[i] and p[j] is matching
    f= new bool *[s.length()];
    for(int i=0;i<s.length();i++)
        f[i]= new bool[p.length()];
    bool first_match;

    for(int i=s.length()-1; i>=0;i--)
    {
        for (int j = p.length() - 1; j >= 0; j--) {
            first_match = (s[i] == p[j]) || p.at(j) == '.';
            if(i==s.length()-1&&j == p.length() - 1)
            {
                f[i][j] = first_match;
                continue;
            }
            else if ( j < p.length() - 1 && p.at(j + 1) == '*')
            {
                if(first_match)
                    f[i][j] =(i == s.length() - 1)||f[i + 1][j];
                else
                    f[i][j] = (j<p.length() - 2)&&f[i][j + 2];
            }
            else{
                if(i==s.length()-1||j == p.length() - 1)
                    f[i][j] = false;
                else
                    f[i][j] = first_match&&f[i + 1][j + 1];
            }
        }
    }
    return f[0][0];
}