#include "errors.hpp"
#include <cstdarg>
#include <string>

void Errors::die(const char* format, ...)
{
    char output[ERROR_STRING_MAX_LENGTH];
    va_list args;
    va_start(args, format);
    vsnprintf(output, ERROR_STRING_MAX_LENGTH, format, args);
    va_end(args);
    throw Emulation_error(output);
}

void Errors::print_warning(const char* format, ...)
{
    /*this is 100% identical to printf
    but is intended for errors that we want to ignore for now*/
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}
