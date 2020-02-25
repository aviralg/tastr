#ifndef RTYPESPARSER_R_TYPES_PARSER_H
#define RTYPESPARSER_R_TYPES_PARSER_H
#include "parser.hpp"

#include <map>
#include <string>

/* Give Flex the prototype of yylex we want ... */
#define YY_DECL yy::parser::symbol_type yylex(RTypesParser& rtypesparser)
/* ... and declare it for the parser's sake. */
YY_DECL;

/* Conducting the whole scanning and parsing */
class RTypesParser {
  public:
    explicit RTypesParser()
        : trace_parsing_(false), trace_scanning_(false), result_(-1) {
    }

    void trace_parsing() {
        trace_parsing_ = true;
    }

    void trace_scanning() {
        trace_scanning_ = true;
    }

    bool is_trace_scanning_enabled() const {
        return trace_scanning_;
    }

    int parse(const std::string& filename) {
        file = filename;
        location_.initialize(&file);
        scan_begin();
        yy::parser parse(*this);
        parse.set_debug_level(trace_parsing_);
        int res = parse();
        scan_end();
        return res;
    }

    yy::location& get_location() {
        return location_;
    }

    const yy::location& get_location() const {
        return location_;
    }

    /* Handling the scanner. */
    void scan_begin();
    void scan_end();

    int get_variable(const std::string& variable) {
        return variables_[variable];
    }

    void set_variable(const std::string& variable, int value) {
        variables_[variable] = value;
    }

    void set_result(int result) {
        result_ = result;
    }

    int get_result() {
        return result_;
    }

  private:
    /* The name of the file being parsed. */
    std::string file;
    /* Whether to generate parser debug traces. */
    bool trace_parsing_;
    /* Whether to generate scanner debug traces. */
    bool trace_scanning_;
    /* Return 0 on success. */
    int result_;
    /* The token's location used by the scanner. */
    yy::location location_;

    std::map<std::string, int> variables_;
};

#endif /* RTYPESPARSER_TYPES_PARSER_H */