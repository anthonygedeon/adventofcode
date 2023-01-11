#if !defined(FILE_H)
#define FILE_H

#include <string>
#include <optional>

/// Read the contents of the file and output it into a string
std::optional<std::string> read_file(std::string_view filename);

#endif
