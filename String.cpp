//
// Created by Erik Karlsson on 10/13/16.
//

#include "String.h"

String::String(const char *s)
{
    buf = NULL;
    strcpy(buf, s);
}

String::String(const String &string)
{
    buf = NULL;
    strcpy(buf, string.buf);
}

String::~String()
{
    if (buf != NULL)
    {
        delete[]buf;
    }
}

String String::operator=(const String &string)
{
    strcpy(buf, string.buf);
    return *this;
}

char &String::operator[](int index)
{
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

    for (int i  = bufSize - 2; i >= 0; --i)
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
    in >> buf;
}

int String::strlen(const char *s)
{
    int index = 0;
    while (s[index] != '\0')
    {
        ++index;
    }

    return index;
}

char *String::strcpy(char *dest, const char *src)
{
    int srcLength;
    int strIndex;

    srcLength = strlen(src);
    strIndex  = 0;

    if (dest != NULL)
    {
        delete[] dest;
    }
    dest           = new char[srcLength + 1];

    while (strIndex < srcLength)
    {
        (dest)[strIndex] = src[strIndex];
        cout << "Char " << strIndex << " : " << dest[strIndex] << endl;
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
    int stringLength = strlen(left) + strlen(right);
    return strncmp(left, right, stringLength);
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
    while (str[i] != '\0' && !found)
    {
        if (str[i] == c)
        {
            found = true;
        }
        ++i;
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

ostream &operator<<(ostream &out, String &str)
{
    str.print(out);
    return out;
}

istream &operator>>(istream &in, String &str)
{
    str.read(in);
    return in;
}
