//
// Created by Erik Karlsson on 10/13/16.
//

#include "String.h"

int String::allocations = 0;
String::String(const char *s)
{
    buf = strdup(s);
}

String::String(const String &string)
{
    buf = strdup(string.buf);
}

String::~String()
{
    delete_char_array(buf);
}

String String::operator=(const String &string)
{
    delete_char_array(buf);
    buf = strdup(string.buf);
    return *this;
}

char &String::operator[](int index)
{
    if(index > strlen(buf)) error("Index out of bounds!");
    return buf[index];
}

int String::size()
{
    return strlen(buf);
}

String String::reverse()
{
    int  bufSize = size();
    char reversed[bufSize];
    int  j       = 0;

    for (int i  = bufSize - 1; i >= 0; --i)
    {
        reversed[j] = buf[i];
        ++j;
    }
    reversed[j] = '\0';
    return String(reversed);
}

int String::indexOf(const char c)
{
    const char *resultC = strchr(buf, c);
    if (resultC == NULL)
    {
        return -1;
    }

    return resultC - buf;
}

int String::indexOf(const String pattern)
{
    const char *resultC = strstr(buf, pattern.buf);
    if (resultC == NULL)
    {
        return -1;
    }

    return resultC - buf;
}

bool String::operator==(const String string)
{
    return strcmp(this->buf, string.buf) == 0;
}

bool String::operator!=(const String string)
{
    return strcmp(this->buf, string.buf) != 0;
}

bool String::operator>(const String string)
{
    return strcmp(this->buf, string.buf) > 0;
}

bool String::operator<(const String string)
{
    return strcmp(this->buf, string.buf) < 0;
}

bool String::operator<=(const String string)
{
    return strcmp(this->buf, string.buf) <= 0;
}

bool String::operator>=(const String string)
{
    return strcmp(this->buf, string.buf) >= 0;
}

String String::operator+(const String s)
{
    char copyString[strlen(buf)];
    strcpy(copyString, buf);
    return strcat(copyString, s.buf);
}

String String::operator+=(const String string)
{
    return strcat(buf, string.buf);
}

void String::print(ostream &out)
{
    int strLength = strlen(buf);

    for (int i = 0; i < strLength; ++i)
    {
        out << buf[i];
    }
}

void String::read(istream &in)
{
    char *input = new_char_array(2000);
    in.getline(input, 2000);
    delete_char_array(buf);
    buf = strdup(input);
    delete_char_array(input);
}

int String::strlen(const char *s)
{
    int index = 0;
    while (s != NULL && s[index] != '\0')
    {
        ++index;
    }

    return index;
}

char *String::strcpy(char *dest, const char *src)
{
    int srcLength;
    int strIndex;

    srcLength = strlen(src) + 1;
    strIndex  = 0;

    while (strIndex < srcLength)
    {
        (dest)[strIndex] = src[strIndex];
        ++strIndex;
    }
    dest[strIndex] = '\0';

    return dest;
}

char *String::strcat(char *dest, const char *src)
{
    strcpy(dest + strlen(dest), src);
    return dest;
}

int String::strcmp(const char *left, const char *right)
{
    int leftStringLength = strlen(left);
    int rightStringLength = strlen(right);
    if(leftStringLength == 0)
    {
        if(rightStringLength == 0)
            return 0;
        else
            return rightStringLength;
    }
    else
    {
        if(rightStringLength == 0)
            return leftStringLength;
    }

    return strncmp(left, right, rightStringLength + leftStringLength);
}

int String::strncmp(const char *left, const char *right, int n)
{
    int  i        = 0;
    bool matching = true;
    int  result;

    while (left[i] != '\0' && right[i] != '\0' && matching && i < n)
    {
        if (left[i] != right[i])
        {
            matching = false;
        }
        ++i;
    }

    if (matching)
    {
        result = 0;
    }
    else
    {
        result = left[i - 1] - right[i - 1];
    }

    return result;
}

const char *String::strchr(const char *str, int c)
{
    int  i     = 0;
    bool found = false;
    while (str != nullptr && str[i] != '\0' && !found)
    {
        if (str[i] == c)
        {
            found = true;
        }
        else{
            ++i;
        }
    }
    if (!found)
    {
        return NULL;
    }
    return &str[i];
}

const char *String::strstr(const char *haystack, const char *needle)
{
    int bufSize     = strlen(haystack);
    int patternSize = strlen(needle);
    int j;

    if (patternSize > bufSize)
    {
        return NULL;
    }

    for (int i = 0; i < bufSize; ++i)
    {
        j = 0;
        while (j < patternSize && haystack[i + j] == needle[j])
        {
            j += 1;
        }
        if (j == patternSize)
        {
            return &haystack[j];
        }
    }

    return NULL;
}

ostream &operator<<(ostream &out, String str)
{
    str.print(out);
    return out;
}

istream &operator>>(istream &in, String &str)
{
    str.read(in);
    return in;
}

char* String::strdup(const char* src)
{
    return strcpy(new_char_array( strlen(src) + 1 ), src);
}
