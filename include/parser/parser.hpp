#ifndef TASTR_PARSER_PARSER_HPP
#define TASTR_PARSER_PARSER_HPP

#include "parser/ParseResult.hpp"

#include <filesystem>
#include <ostream>
#include <string>

std::ostream& operator<<(std::ostream& os, const tastr::ast::Node& node);

namespace tastr::parser {

std::string to_string(const tastr::ast::Node& node);

void unparse_stdout(const tastr::ast::Node& node,
                    bool show_ast = false,
                    bool style_output = false);

void unparse_string(const tastr::ast::Node& node,
                    std::string& string,
                    bool show_ast = false,
                    bool style_output = false);

void unparse_file(const tastr::ast::Node& node,
                  const std::filesystem::path& filepath,
                  bool show_ast = false,
                  bool style_output = false);

ParseResult parse_stdin(bool debug_lexer = false, bool debug_parser = false);

ParseResult parse_string(const std::string& string,
                         bool debug_lexer = false,
                         bool debug_parser = false);

ParseResult parse_file(const std::filesystem::path& filepath,
                       bool debug_lexer = false,
                       bool debug_parser = false);

} // namespace tastr::parser

#endif /* TASTR_PARSER_PARSER_HPP */
