//
// Created by Dan Karlsson on 10/13/16.
//

#ifndef HW3_STRING_H
#define HW3_STRING_H

#include <iostream>

using namespace std;

class String
{
    public:
        // Both constructors should construct
        //  this String from the parameter s
        String(const char *s = "");

        String(const String &string);

        ~String();

        void print(ostream &out);

        void read(istream &in);

        int size();

        String reverse(); // Does not modify this String

        char &operator[](int index);

        int indexOf(const char c);

        int indexOf(const String pattern);

        bool operator==(const String string);

        bool operator!=(const String string);

        bool operator>(const String string);

        bool operator<(const String string);

        bool operator<=(const String string);

        bool operator>=(const String string);

        // Concatenates this and s to return result
        String operator+(const String s);

        // Concatenates s onto end of this
        String operator+=(const String string);

        String operator=(const String &string);


    private:
        static int strlen(const char *s);

        static char *strcpy(char *dest, const char *src);

        static char *strcat(char *dest, const char *src);

        static int strcmp(const char *left, const char *right);

        static int strncmp(const char *left, const char *right, int n);

        const static char *strchr(const char *str, int c);

        const static char *strstr(const char *haystack, const char *needle);

        char *buf; // array for the characters in this string
        // DO NOT store the ‘logical’ length of this string
        // use the null ‘\0’ terminator to mark the end

        bool inBounds(int i)
        {
            return i >= 0 && i < strlen(buf);
        }

};

ostream &operator<<(ostream &out, String &str);

istream &operator>>(istream &in, String &str);

#endif //HW3_STRING_H